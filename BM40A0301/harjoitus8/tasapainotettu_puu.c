#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct puusolmu_t {
  int luku;
  short tila; /* tasapainoilmaisin */
  struct puusolmu_t *vasen, *oikea;
} puusolmu, *puuosoitin;

void lisaa_solmu(puuosoitin *, int, int *);
void tulosta_puu(puuosoitin);
void vasen_kierto(puuosoitin *, int *);

int main()
{
  int etp = 0, i, luvut[] = {10,5,2,1,0};
  puuosoitin puu = NULL;
  
  for(i = 0; luvut[i] != 0; i++)
  {
    lisaa_solmu(&puu, luvut[i], &etp);
  }
  tulosta_puu(puu);
  printf("\n");

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
          
      }
    }
  } else
  {
    *etp = 0;
    printf("Luku %d on jo puussa\n", luku);
  }
}

void tulosta_puu(puuosoitin solmu)
{
  if(!solmu) return;
  tulosta_puu(solmu->vasen);
  printf("%d ", solmu->luku);
  tulosta_puu(solmu->oikea);
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
