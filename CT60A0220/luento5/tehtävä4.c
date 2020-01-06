/*Topi Jussinniemi, 12.2.2018, harjoitus 5, tehtävä 4*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* muutaKokoa(int koko);
void tulosta(int *lista, int koko);


int main(void) {

int valinta;
int koko = 0;
int lopetus = 0;
int temp;
int *lista = (int *) malloc(0);


while(lopetus != 1) {

printf("1) Tulosta taulukon alkiot\n");
printf("2) Muuta taulukon kokoa\n");
printf("0) Lopeta\n");
printf("Anna valintasi: ");
scanf("%d", &valinta);

switch(valinta) {
		case 1:
			if (koko == 0) {
				printf("Taulukko on tyhjä.\n");
			} else {
				tulosta(lista, koko);
			}
			break;
		case 2:
			printf("Anna taulukon uusi koko: ");
			scanf("%d", &temp);
			if (temp < 0) {
				printf("Taulukon koko ei voi olla negatiivinen.\n");
			} else {
				koko = temp;
				free(lista);
				lista = muutaKokoa(koko);
			}
			break;
		case 0:
			lopetus = 1;
			free(lista);
			printf("Kiitos ohjelman käytöstä.\n");
			break;
		default:
			printf("Virheellinen syöte.\n");
			break;
}
}




return 0;
}


int* muutaKokoa(int koko) {
int i;


int *uusi = (int *) malloc(koko * sizeof(int));

for(i = 0; i < koko; i++) {
	uusi[i] = i;
}
return uusi;
}

void tulosta(int *lista, int koko) {
int i;
printf("Taulukon alkiot ovat:");
for(i = 0; i < koko; i++) {
	printf(" %d", lista[i]);
}

printf("\n");
}



/*eof*/
