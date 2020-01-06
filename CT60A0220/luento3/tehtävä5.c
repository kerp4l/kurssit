#include <stdio.h>
#include <stdlib.h>

void kirjoita(void);
void lue(void);

/*Topi Jussinniemi, 28.1.2018, harjoitus 3, tehtävä 5*/

int main(void) {

kirjoita();
lue();

return 0;
}


void kirjoita(void) {

srand(40);
int luku;
int i;
FILE *tiedosto;
tiedosto = fopen("luvut.bin", "wb");

for (i = 0; i < 20; i++) {
	luku = rand()%1000;
	fwrite(&luku, sizeof(luku), 1, tiedosto);
}
fclose(tiedosto);
printf("Lukujen tallennus onnistui.\n");

}

void lue(void) {

FILE *tiedosto;
int luku;
int i;
tiedosto = fopen("luvut.bin", "rb");

printf("Tiedostossa on seuraavat luvut:\n");

for (i = 0; i < 20; i++) {
	fread(&luku, sizeof(luku), 1, tiedosto);
	if (i < 19) {
		printf("%d ", luku);
	} else {
		printf("%d\n", luku);
	}
}
fclose(tiedosto);


}

/*eof*/
