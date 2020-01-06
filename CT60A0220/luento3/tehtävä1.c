#include <stdio.h>

/*Topi Jussinniemi, 27.1.2018, harjoitus 3, tehtävä 1*/


int korotus(int x, int y);

int main(void) {

int luku;
int potenssi;
int tulos;

printf("Ohjelma laskee luvun potenssin.\n");
printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
scanf("%d", &luku);
printf("Anna potenssi, jonka haluat laskea: ");
scanf("%d", &potenssi);

tulos = korotus(luku, potenssi);

printf("%d ^ %d = %d.\n", luku, potenssi, tulos);


return 0;
}

int korotus(int x, int y) {
int tulos = 1;
int i;

for (i = 0; i < y; i++) {
	tulos = tulos * x;
}

return tulos;

}



/*eof*/
