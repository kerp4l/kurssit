#include <stdio.h>
#include <stdlib.h>


struct Node1 {
	int avain;
	int tila;
	struct Node1 *vasen;
	struct Node1 *oikea;
};

typedef struct Node1 puu_solmu;
typedef puu_solmu *puuosoitin;

struct Node2 {
	puuosoitin solmu;
	struct Node2 *seuraava;
};

typedef struct Node2 lista_solmu;






void luo_aineisto(int a[], int);
void lue_aineisto(puuosoitin *, int *, int *, int taulukko[]);

void lisaa_solmu(puuosoitin *, int, int *, int *);
void vasen_kierto(puuosoitin *, int *);
void oikea_kierto(puuosoitin *, int *);
void sisajarjestys(puuosoitin);
void esijarjestys(puuosoitin);
void jalkijarjestys(puuosoitin);
lista_solmu *lisaa_alkio(lista_solmu *, puuosoitin);
void tulosta_puu_tasottain(int, int k[], puuosoitin);
lista_solmu *lue_taso(lista_solmu *, int m[], int *, int);
void tyhjenna_puu(puuosoitin);
void etsi_avain(puuosoitin, int, int *);




int main() {

int aineisto[] = {2, 4, 6, 8, 10, 12, 14, 30, 28};
int aineisto_koko = sizeof(aineisto) / sizeof(int);
int valinta, luku;
int lopeta = 0;
int etp = 0;
puuosoitin juuri = NULL;
int lkm = 0;
int summa = 0;
int lkm_taulukko[18];
int i,haku;

for (i = 0; i < 18; i++) {
	summa = 2*summa + 1;
	lkm_taulukko[i] = summa;
}



for(i = 1; i < 1000; i++) {
	lisaa_solmu(&juuri, i, &etp, &lkm);
}



while (lopeta != 1) {
	printf("\n");
	printf("1) Lisää uusi avain puuhun\n");
	printf("2) Etsi avainta puusta\n");
	printf("3) Tulosta puun avaimet tasoittain\n");
	printf("4) Tulosta puun avaimet sisäjärjestyksessä\n");
	printf("5) Tulosta puun avaimet esijärjestyksessä\n");
	printf("6) Tulosta puun avaimet jälkijärjestyksessä\n");
	printf("7) Tyhjennä puu\n");

	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);

	switch (valinta) {
		case 0:
			tyhjenna_puu(juuri);
			printf("Kiitos ohjelman käytöstä.\n");
			lopeta = 1;
			break;
		case 1:
			printf("Anna puuhun lisättävä avain: ");
			scanf("%d", &luku);
			if (luku > 0) {
				lisaa_solmu(&juuri, luku, &etp, &lkm);
				printf("\n");
				tulosta_puu_tasottain(lkm, lkm_taulukko, juuri);
			} else {
				printf("\n");
				printf("Virheellinen syöte. Puuhun voi lisätä vain positiivisiä avaimia.\n");
			}
			break;
		case 2:
			printf("Anna puusta etsittävä avain: ");
			scanf("%d", &luku);
			etsi_avain(juuri, luku, &haku);
			printf("\n");
			if (haku == 1) {
				printf("Avain %d löytyy puusta.\n", luku);
			} else if (haku == 0) {
				printf("Avain %d ei ole puussa.\n", luku);
			}
			break;
		case 3:
			printf("\n");
			if (juuri == NULL) {
				printf("Puu on tyhjä.\n");
			} else {
				printf("Puun avaimet tasoittain:\n");
				printf("\n");
				tulosta_puu_tasottain(lkm, lkm_taulukko, juuri);
			}
			break;
		case 4:
			printf("\n");
			if (juuri == NULL) {
				printf("Puu on tyhjä.\n");
			} else {
				printf("Puussa olevat avaimet sisäjärjestyksessä: ");
				sisajarjestys(juuri);
				printf("\n");
			}
			break;
		case 5:
			printf("\n");
			if (juuri == NULL) {
				printf("Puu on tyhjä.\n");
			} else {
				printf("Puussa olevat avaimet esijärjestyksessä: ");
				esijarjestys(juuri);
				printf("\n");
			}
			break;
		case 6:
			printf("\n");
			if (juuri == NULL) {
				printf("Puu on tyhjä.\n");
			} else {
				printf("Puussa olevat avaimet jälkijärjestyksessä: ");
				jalkijarjestys(juuri);
				printf("\n");
			}
			break;
		case 7:
			printf("\n");
			printf("Puu on tyhjennetty. Poistettiin %d avainta.\n", lkm);
			tyhjenna_puu(juuri);
			juuri = NULL;
			lkm = 0;
			etp = 0;
			break;
		default:
			printf("\n");
			printf("Virheellinen valinta. Yritä uudelleen.\n");
			break;
	}
}







return 0;
}




void luo_aineisto(int aineisto[], int n) {

int i;
FILE *tiedosto = fopen("aineisto.txt", "w");

if (tiedosto == NULL) {
	perror("Tiedoston avaaminen epäonnistui. Ohjelma suljetaan.");
	exit(1);
}
printf("Luotiin aineisto tiedostoon aineisto.txt.\n");
printf("Aineistossa on seuraavat avaimet: ");

for (i = 0; i < n; i++) {
	fprintf(tiedosto, "%d\n", aineisto[i]);
	printf("%d ", aineisto[i]);
}

fclose(tiedosto);
printf("\n");
}





void lue_aineisto(puuosoitin *juuri, int *etp, int *lkm, int lkm_taulukko[]) {

int i;
FILE *tiedosto = fopen("aineisto.txt", "r");

if (tiedosto == NULL) {
	perror("Tiedoston avaaminen epäonnistui. Ohjelma suljetaan.");
	exit(1);
}

while (!feof (tiedosto)) {
	fscanf(tiedosto, "%d", &i);
	lisaa_solmu(juuri, i, etp, lkm);
	printf("Aineistosta luettiin avain %d ja se lisättiin puuhun.\n", i);
	printf("\n");
	tulosta_puu_tasottain(*lkm, lkm_taulukko, *juuri);
	printf("\n");
}

fclose(tiedosto);
}



void lisaa_solmu(puuosoitin *emo, int luku, int *etp, int *lkm) {

if((*emo) == NULL) {
	*etp = 1;
	*lkm = *lkm + 1;
	if (((*emo) = (puuosoitin) malloc(sizeof(puu_solmu))) == NULL) {
		perror("Muistinvaraaminen epäonnistui. Ohjelma suljjetaan.\n");
		exit(1);
	}
	(*emo)->avain = luku;
	(*emo)->vasen = NULL;
	(*emo)->oikea = NULL;
	(*emo)->tila = 0;

} else if (luku < (*emo)->avain) {

	lisaa_solmu(&(*emo)->vasen, luku, etp, lkm);

	if (*etp == 1) {
		switch ((*emo)->tila) {
			case -1:
				(*emo)->tila = 0;
				*etp = 0;
				break;
			case 0:
				(*emo)->tila = 1;
				break;
			case 1:
				vasen_kierto(emo, etp);
				break;
		}
	}
} else if (luku > (*emo)->avain) {

	lisaa_solmu(&(*emo)->oikea, luku, etp, lkm);
	
	if (*etp == 1) {
		switch ((*emo)->tila) {
			case 1:
				(*emo)->tila = 0;
				*etp = 0;
				break;
			case 0:
				(*emo)->tila = -1;
				break;
			case -1:
				oikea_kierto(emo, etp);
				break;
		}
	}

} else {
	*etp = 0;
	printf("\n");
	printf("Avain %d on jo puussa.\n", luku);
}
}




void vasen_kierto(puuosoitin *emo, int *etp) {

puuosoitin lapsi, lapsenlapsi;
lapsi = (*emo)->vasen;

if (lapsi->tila == 1) { /*L-kierto*/
	(*emo)->vasen = lapsi->oikea;
	lapsi->oikea = *emo;
	(*emo)->tila = 0;
	(*emo) = lapsi;
} else { /*LR-kierto*/
	lapsenlapsi = lapsi->oikea;
	lapsi->oikea = lapsenlapsi->vasen;
	lapsenlapsi->vasen = lapsi;
	(*emo)->vasen = lapsenlapsi->oikea;
	lapsenlapsi->oikea = *emo;

	switch (lapsenlapsi->tila) {
		case 1:
			(*emo)->tila = -1;
			lapsi->tila = 0;
			break;
		case 0:
			(*emo)->tila = 0;
			lapsi->tila = 0;
			break;
		case -1:
			(*emo)->tila = 0;
			lapsi->tila = 1;
			break;
	}
	*emo = lapsenlapsi;
}
(*emo)->tila = 0;
*etp = 0;
}








void oikea_kierto(puuosoitin *emo, int *etp) {

puuosoitin lapsi, lapsenlapsi;
lapsi = (*emo)->oikea;

if (lapsi->tila == -1) { /*R-kierto*/
	(*emo)->oikea = lapsi->vasen;
	lapsi->vasen = *emo;
	(*emo)->tila = 0;
	(*emo) = lapsi;

} else { /*RL-kierto*/
	lapsenlapsi = lapsi->vasen;
	lapsi->vasen = lapsenlapsi->oikea;
	lapsenlapsi->oikea = lapsi;
	(*emo)->oikea = lapsenlapsi->vasen;
	lapsenlapsi->vasen = *emo;

	switch (lapsenlapsi->tila) {
		case 1:
			(*emo)->tila = 0;
			lapsi->tila = -1;
			break;
		case 0:
			(*emo)->tila = 0;
			lapsi->tila = 0;
			break;
		case -1:
			(*emo)->tila = 1;
			lapsi->tila = 0;
			break;
	}
	*emo = lapsenlapsi;
}
(*emo)->tila = 0;
*etp = 0;
}


/*Tulostaa puun avaimet sisäjärjestyksessä.*/

void sisajarjestys(puuosoitin solmu) {

if (solmu == NULL) {
	return;
}

sisajarjestys(solmu->vasen);
printf("%d ", solmu->avain);
sisajarjestys(solmu->oikea);

}


/*Tulostaa puun avaimet esijärjestyksessä.*/

void esijarjestys(puuosoitin solmu) {

if (solmu == NULL) {
	return;
}

printf("%d ", solmu->avain);
esijarjestys(solmu->vasen);
esijarjestys(solmu->oikea);
}


/*Tulostaa puun avaimet jälkijärjestyksessä.*/

void jalkijarjestys(puuosoitin solmu) {

if (solmu == NULL) {
	return;
}

jalkijarjestys(solmu->oikea);
jalkijarjestys(solmu->vasen);
printf("%d ", solmu->avain);
}




lista_solmu *lisaa_alkio(lista_solmu *pAlku, puuosoitin juuri) {

lista_solmu *ptr, *ptrUusi;

if ((ptrUusi = (lista_solmu *) malloc(sizeof(lista_solmu))) == NULL) {
	perror("Muistin varaaminen eoäonnistui. Ohjelma suljetaan.");
	exit(1);
}

ptrUusi->solmu = juuri;
ptrUusi->seuraava = NULL;

if (pAlku == NULL) {
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	while (ptr->seuraava != NULL) {
		ptr = ptr->seuraava;
	}
	ptr->seuraava = ptrUusi;
}
return pAlku;
}





void tulosta_puu_tasottain(int lkm, int lkm_taulukko[], puuosoitin juuri) {

if (lkm == 0) {
	printf("Puu on tyhjä.\n");
	return;
}

int i, tasot, solmut, a, b, t;

for (i = 0; i < 18; i++) {
	a = lkm_taulukko[i];
	b = lkm_taulukko[i + 1];
	
	if ((lkm >= a) && (lkm < b)) {
		tasot = i + 2;
		solmut = lkm_taulukko[i + 1];
	}
}
int avaimet[solmut];

for (i = 0; i < solmut; i++) {
	avaimet[i] = -1;
}

lista_solmu *alku = NULL;
alku = lisaa_alkio(alku, juuri);
int n = 0;

while (alku != NULL) {
	alku = lue_taso(alku, avaimet, &n, solmut);
}



for (i = 0; i < tasot; i++) {
	
	if (i == 0) {
		printf("%d", avaimet[i]);
	} else {
		n = lkm_taulukko[i - 1];
		t = lkm_taulukko[i];
		
		while (n < t) {
			if (avaimet[n] == -2) {
				printf("- ");
			} else {
				printf("%d ", avaimet[n]);
			}
			n = n + 1;
		}
	}
	printf("\n");
}


}




lista_solmu *lue_taso(lista_solmu *p1, int A[], int *n, int raja) {

lista_solmu *ptr;
lista_solmu *p2 = NULL;
int v, o;

while (p1 != NULL) {

	puuosoitin Solmu = p1->solmu;
	
	if ((Solmu->vasen != NULL) && (Solmu->oikea != NULL)) {
		p2 = lisaa_alkio(p2, Solmu->vasen);
		p2 = lisaa_alkio(p2, Solmu->oikea);
		
		if (A[*n] == -1) {
			A[*n] = Solmu->avain;
			*n = *n + 1;
		} else {
			while (A[*n] != -1) {
				*n = *n + 1;
			}
			A[*n] = Solmu->avain;
			*n = *n + 1;
		}
	} else if ((Solmu->vasen != NULL) && (Solmu->oikea == NULL)) {

		p2 = lisaa_alkio(p2, Solmu->vasen);

		if (A[*n] == -1) {
			A[*n] = Solmu->avain;
		} else {
			while (A[*n] != -1) {
				*n = *n + 1;
			}
			A[*n] = Solmu->avain;
		}

		v = (*n)*2 + 1;
		o = (*n)*2 + 2;

		if (o < raja) {
			A[o] = -2;
			if ((2*o + 1) < raja) {
				A[2*o + 1] = -2;
				A[2*o + 2] = -2;
			}
		}
		*n = *n + 1;

	} else if ((Solmu->vasen == NULL) && (Solmu->oikea != NULL)) {

		p2 = lisaa_alkio(p2, Solmu->oikea);

		if (A[*n] == -1) {
			A[*n] = Solmu->avain;
		} else {
			while (A[*n] != -1) {
				*n = *n + 1;
			}
			A[*n] = Solmu->avain;
		}

		v = (*n)*2 + 1;
		o = (*n)*2 + 2;

		if (v < raja) {
			A[v] = -2;
			if ((2*v + 1) < raja) {
				A[2*v + 1] = -2;
				A[2*v + 2] = -2;
			}
		}
		*n = *n + 1;

	} else if ((Solmu->vasen == NULL) && (Solmu->oikea == NULL)) {

		if (A[*n] == -1) {
			A[*n] = Solmu->avain;
		} else {
			while (A[*n] != -1) {
				*n = *n + 1;
			}
			A[*n] = Solmu->avain;
		} 

		v = (*n)*2 + 1;
		o = (*n)*2 + 2;

		if (v < raja) {
			A[v] = -2;
			A[o] = -2;
			if ((2*v + 1) < raja) {
				A[2*v + 1] = -2;
				A[2*v + 2] = -2;
				A[2*v + 1] = -2;
				A[2*o + 2] = -2;
			}
		}
			*n = *n + 1;
	}
	ptr = p1;
	p1 = p1->seuraava;
	free(ptr);
}
p1 = p2;

return p1;
}



void tyhjenna_puu(puuosoitin p) {

if (p == NULL) {
	return;
}

tyhjenna_puu(p->vasen);
tyhjenna_puu(p->oikea);
free(p);
}




void etsi_avain(puuosoitin p, int luku, int *tulos) {

if (p == NULL) {
	*tulos = 0;
	return;
} else if (p->avain == luku) {
	*tulos = 1;
} else if (p->avain > luku) {
	etsi_avain(p->vasen, luku, tulos);
} else if (p->avain < luku) {
	etsi_avain(p->oikea, luku, tulos);
}
}











