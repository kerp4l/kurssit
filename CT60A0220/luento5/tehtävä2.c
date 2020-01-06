/*Topi Jussinniemi, 11.2.2018, harjoitus 5, tehtävä 2*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int tarkistaSyote(char *merkki[]);
int* varaaMuisti(int x);
void taytaTaulukko(int *x, int y);
void tulostaTaulukko(int *, int);
void vapautaMuisti(int *);


int main(int argc, char *args[]) {

if (argc == 1) {
	printf("Et antanut taulukon kokoa.\n");
	exit(0);
}

int koko = tarkistaSyote(args);

if (koko == 0) {
	printf("Parametri ei ole positiivinen kokonaisluku.\n");
	exit(0);
}

int* muisti = varaaMuisti(koko);

taytaTaulukko(muisti, koko);

tulostaTaulukko(muisti, koko);

vapautaMuisti(muisti);


return 0;
}

int tarkistaSyote(char *merkki[]) {
int x = atoi(merkki[1]);

if (x < 0) {
	x = 0;
}

return x;
}


int* varaaMuisti(int x) {
int* muisti = (int *) malloc(x * sizeof(int));
return muisti;
}

void taytaTaulukko(int *muisti, int x) {

int i;

printf("Taulukossa on tilaa %d alkiolle.\n", x);
for (i = 0; i < x; i++) {
	printf("Anna %d. luku: ", i+1);
	scanf("%d", &muisti[i]);
}
}

void tulostaTaulukko(int *muisti, int koko) {

int i;
printf("Taulukossa on luvut:");
for (i = 0; i < koko; i++) {
	printf(" %d", muisti[i]);
}
printf("\n");
}

void vapautaMuisti(int *muisti) {
free(muisti);
}

/*eof*/
