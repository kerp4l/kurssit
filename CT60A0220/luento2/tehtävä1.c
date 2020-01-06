#include <stdio.h>

/*Topi Jussinniemi, 18.1.2018, harjoitus 2, tehtävä 1*/

int main(void) {

int luku;
int kertyma = 0;
int i;

printf("Anna jokin luku väliltä 10 - 200: ");
scanf("%d", &luku);

if (luku < 10 || luku > 200){
	printf("Antamasi luku ei ole annetulla välillä.\n");
	} else {
	for (i = 0; i <= luku; i++) {
		kertyma = kertyma + i;		
	}
	printf("Lukujen 0 - %d summa on %d.\n", luku, kertyma);
	}







return 0;
}

/*eof*/
