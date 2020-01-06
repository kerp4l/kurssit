/*Topi Jussinniemi, 19.2.2018, harjoitus 6, tehtävä 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char merkki[20];
	int vuosimalli;
	struct Node *pNext;
};

typedef struct Node Solmu;

Solmu *lisaaSolmu(Solmu *pAlku, char merkki[], int vuosimalli);
void tulosta(Solmu *pAlku);
Solmu *tyhjenna(Solmu *pAlku);

int main(int argc, char *args[]) {

if(argc == 1) {
	printf("Et antanut tiedoston nimeä.\n");
} else {

	Solmu *pAlku = NULL;
	char jono[20];
	int luku;
	char rivi[50];
	char *temp1;
	char *temp2;
	FILE *tiedosto;
	
	printf("Luetaan tiedot tiedostosta %s.\n", args[1]);
	
	if ((tiedosto = fopen(args[1], "r")) == NULL){
		printf("Tiedoston avaus epäonnistui.\n");
		exit(0);
	}
	

	while(fgets(rivi, 49, tiedosto)) {
		temp1 = strtok(rivi, " ");
		strcpy(jono, temp1);
		temp2 = strtok(NULL, " ");
		luku = atoi(temp2);
		pAlku = lisaaSolmu(pAlku, jono, luku);
	}
	fclose(tiedosto);
	
	printf("Tiedot luettu linkitettyyn listaan.\n");
	tulosta(pAlku);
	
	pAlku = tyhjenna(pAlku);
}


return 0;
}


Solmu *lisaaSolmu(Solmu *pAlku, char merkkijono[], int luku) {

Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	perror("Muistinvaraaminen epäonnistui");
	exit(1);
}

strcpy(ptrUusi->merkki, merkkijono);
ptrUusi->vuosimalli = luku;
ptrUusi->pNext = NULL;

if (pAlku == NULL) {
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	while(ptr->pNext != NULL)
		ptr = ptr->pNext;
	ptr->pNext = ptrUusi;
}

return pAlku;

}

void tulosta(Solmu *pAlku) {
Solmu *ptr = pAlku;
int i = 1;

while(ptr != NULL) {
	printf("%d. ajoneuvo: %s vuosimalli %d.\n", i, ptr->merkki, ptr->vuosimalli);
	ptr = ptr->pNext;
	i = i + 1;
}

}

Solmu *tyhjenna(Solmu *pAlku) {
Solmu *ptr = pAlku;

while(ptr != NULL) {
	pAlku = ptr->pNext;
	free(ptr);
	ptr = pAlku;
}

printf("Muisti vapautettu.\n");

return pAlku;

}

/*eof*/
