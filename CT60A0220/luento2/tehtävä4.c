#include <stdio.h>

/*Topi Jussinniemi, 19.1.2018, harjoitus 2, tehtävä 4*/

int main(void) {

float pii = 3.141;
float luku;
int valinta;
float tulo;
float jako;

printf("Anna liukuluku: ");
scanf("%f", &luku);

printf("\n");
printf("Valikko\n");
printf("1) Kerro piin arvo luvulla %.3f.\n", luku);
printf("2) Jaa piin arvo luvulla %.3f.\n", luku);
printf("Valitse: ");
scanf("%d", &valinta);
printf("\n");

switch (valinta) {
	case 1:
		tulo = pii * luku;
		printf("Pii * %.3f = %.3f.\n", luku, tulo);
		break;
	case 2:
		jako = pii / luku;
		printf("Pii / %.3f = %.3f.\n", luku, jako);
		break;
	default:
		printf("Tuntematon valinta.\n");
		break;
}





return 0;
}

/*eof*/
