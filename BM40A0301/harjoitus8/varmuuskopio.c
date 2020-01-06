#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct puusolmu_t {
  int luku;
  short tila; /* tasapainoilmaisin */
  struct puusolmu_t *vasen, *oikea;
} puusolmu, *puuosoitin;

void lisaa_solmu(puuosoitin *, int, int *);
void oikea_kierto(puuosoitin *, int *);
void tulosta_puu(puuosoitin);
void vasen_kierto(puuosoitin *, int *);
void tulosta_puu2(puuosoitin);
void tulosta_puu3(puuosoitin);



int main()
{

int etp = 0;
int lopeta = 0;
int valinta, luku;
puuosoitin puu = NULL;

while (lopeta != 1) {
	printf("\n");
	printf("1) Lisää uusi avain puuhun\n");
	printf("2) Tulosta puun avaimet sisäjärjestyksessä\n");
	printf("3) Tulosta puun avaimet esijärjestyksessä\n");
	printf("4) Tulosta puun avaimet jälkijärjestyksessä\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);

	switch(valinta) {
		case 0:
			printf("Kiitos ohjelman käytöstä!\n");
			lopeta = 1;
			break;
		case 1:
			printf("Anna binääripuuhun lisättävä luku: ");
			scanf("%d", &luku);
			lisaa_solmu(&puu, luku, &etp);
			break;
		case 2:
			printf("Puun avaimet sisäjärjestyksessä: ");
			tulosta_puu(puu);
			printf("\n");
			break;
		case 3:
			printf("Ouun avaimet esijärjestyksessä: ");
			tulosta_puu2(puu);
			printf("\n");
			break;
		case 4:
			printf("Puun avaimet jälkijärjestyksessä: ");
			tulosta_puu3(puu);
			printf("\n");
			break;
		default:
			printf("Virheellinen valinta!\n");
			break;
	}
}

  return 0;
}







void lisaa_solmu(puuosoitin *emo, int luku, int *etp)
{
  if(!(*emo))
  {
    *etp = 1;
    if(!(*emo = (puuosoitin)malloc(sizeof(puusolmu))))
    {
      perror("malloc");
      exit(1);
    }
    (*emo)->vasen = (*emo)->oikea = NULL;
    (*emo)->tila = 0;
    (*emo)->luku = luku;
  } else if(luku < (*emo)->luku)
  {
    lisaa_solmu(&(*emo)->vasen, luku, etp);
    if(*etp)
    {
      switch((*emo)->tila)
      {
        case -1:
          (*emo)->tila = 0;
          *etp = 0;
          break;
        case 0:
          (*emo)->tila = 1;
          break;
        case 1:
          vasen_kierto(emo, etp);
      }
    }
  } else if(luku > (*emo)->luku)
  {
    lisaa_solmu(&(*emo)->oikea, luku, etp);
    if(*etp)
    {
      switch((*emo)->tila)
      {
        case 1:
          (*emo)->tila = 0;
          *etp = 0;
          break;
        case 0:
          (*emo)->tila = -1;
           break;
        case -1:
          oikea_kierto(emo, etp);
      }
    }
  } else
  {
    *etp = 0;
    printf("Luku %d on jo puussa\n", luku);
  }
}



/*Tulostaa avaimet sisäjärjestyksessä*/

void tulosta_puu(puuosoitin solmu)
{
  if(!solmu) return;
  tulosta_puu(solmu->vasen);
  printf("%d ", solmu->luku);
  tulosta_puu(solmu->oikea);
}


/*Tulostaa avaimet esijärjestyksessä*/

void tulosta_puu2(puuosoitin solmu)
{
  if(!solmu) return;
printf("%d ", solmu->luku);
  tulosta_puu2(solmu->vasen);
  tulosta_puu2(solmu->oikea);
}


/*Tulostaa puun avaimet jälkijärjestyksessä*/


void tulosta_puu3(puuosoitin solmu)
{
  if(!solmu) return;
	
  tulosta_puu3(solmu->oikea);
  tulosta_puu3(solmu->vasen);
printf("%d ", solmu->luku);
}



void vasen_kierto(puuosoitin *emo, int *etp)
{
  puuosoitin lapsi, lapsenlapsi;

  lapsi = (*emo)->vasen;
  if(lapsi->tila == 1) /* LL-kierto */
  {
    (*emo)->vasen = lapsi->oikea;
    lapsi->oikea = *emo;
    (*emo)->tila = 0;
    (*emo) = lapsi;
  } else /* LR-kierto */
  {
    lapsenlapsi = lapsi->oikea;
    lapsi->oikea = lapsenlapsi->vasen;
    lapsenlapsi->vasen = lapsi;
    (*emo)->vasen = lapsenlapsi->oikea;
    lapsenlapsi->oikea = *emo;
    switch(lapsenlapsi->tila)
    {
      case 1:
        (*emo)->tila = -1;
        lapsi->tila = 0;
        break;
      case 0:
        (*emo)->tila = lapsi->tila = 0;
        break;
      case -1:
        (*emo)->tila = 0;
        lapsi->tila = 1;
    }
    *emo = lapsenlapsi;
  }
  (*emo)->tila = 0;
  *etp = 0;
}






void oikea_kierto(puuosoitin *emo, int *etp)
{
  puuosoitin lapsi, lapsenlapsi;

  lapsi = (*emo)->oikea;
  if(lapsi->tila == -1) /* LR-kierto */
  {
    (*emo)->oikea = lapsi->vasen;
    lapsi->vasen = *emo;
    (*emo)->tila = 0;
    (*emo) = lapsi;
  } else /* RL-kierto */
  {
    lapsenlapsi = lapsi->vasen;
    lapsi->vasen = lapsenlapsi->oikea;
    lapsenlapsi->oikea = lapsi;
    (*emo)->oikea = lapsenlapsi->vasen;
    lapsenlapsi->vasen = *emo;
    switch(lapsenlapsi->tila)
    {
      case 1:
        (*emo)->tila = 0;
        lapsi->tila = -1;
        break;
      case 0:
        (*emo)->tila = lapsi->tila = 0;
        break;
      case -1:
        (*emo)->tila = 1;
        lapsi->tila = 0;
    }
    *emo = lapsenlapsi;
  }
  (*emo)->tila = 0;
  *etp = 0;
}
