#include <stdio.h>

/*Topi Jussinniemi, 19.1.2018, harjoitus 2, tehtävä 3*/

int main(void) {

int luku;
int kierros = 1;

printf("Anna jokin kokonaisluku väliltä 1-10: ");
scanf("%d", &luku);

if ((luku <= 10) && (luku > 0)) {
	while (luku >= kierros) {
		printf("%d kierros.\n", kierros);
		kierros = kierros + 1;
		}
} else {
	printf("Antamasi luku ei ole välillä 1-10.\n");
}

return 0;
}

/*eof*/
