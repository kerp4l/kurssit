#include <stdio.h>
#include <string.h>

/*Topi Jussinniemi, 19.1.2018, harjoitus 2, tehtävä 5*/

int main(void) {

int valinta;
char merkki[1];
int lopeta = 0;
int koko;
char mjono[200] = "";
char tyhja[200] = "";
char temp[1] = "";
char tyhjaTemp[1] = "";


	
while (lopeta != 1) {

	printf("\n");
	printf("Valikko\n");
	printf("1) Lisää uusi merkki\n");
	printf("2) Tyhjennä merkkijono\n");
	printf("3) Tulosta merkkijono\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	scanf("%d", &valinta);
	printf("\n");


	
	koko = strlen(mjono);	


	switch (valinta) {
		case 1:
			if (koko >= 200) {
				printf("Merkkijonoon ei mahdu enempää merkkejä.\n");
			} else {
				printf("Anna jokin merkki: ");
				scanf("%s", merkki);
				temp[0] = merkki[0];
				strcat(mjono, temp);
				strcpy(temp, tyhjaTemp);
			}
			break;
		case 2:
			if (koko == 0) {
				printf("Merkkijono on tyhjä.\n");
			} else {
				strcpy(mjono, tyhja);
				printf("Merkkijono on tyhjennetty.\n");
			}
			break;
		case 3:
			if (koko == 0) {
				printf("Merkkijono on tyhjä.\n");
			} else {
				printf("Merkkijono: %s\n", mjono);
			}
			break;
		case 0:
			printf("Ohjelman lopetus.\n");
			lopeta = 1;
			break;
		default:
			printf("Tuntematon valinta.\n");
			break;
	}
	
}




return 0;
}

/*eof*/
