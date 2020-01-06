#include <stdio.h>

#define tilavuus(R,h) (((3.14159*(R/2)*(R/2))*h)/1000)


/*Topi Jussinniemi, 28.1.2018, harjoitus 3, tehtävä 4*/

int main(void) {

int halkaisija;
int korkeus;
float pii = 3.14159;

printf("Ohjelma laskee sylinterin tilavuuden.\n");
printf("Anna sylinterin halkaisija millimetreissä: ");
scanf("%d", &halkaisija);
printf("Anna sylinterin korkeus millimetreissä: ");
scanf("%d", &korkeus);
printf("Sylinterin tilavuus on %.2f cm\n³.", tilavuus(halkaisija,korkeus));


return 0;
}

/*eof*/
