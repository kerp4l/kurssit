#include <stdio.h>
#include <string.h>
/*Topi Jussinniemi, 1.2.2018, harjoitus 4, tehtävä 2*/

#define LKM 50

struct user {
	char id[LKM];
	char pw[LKM];
};


int main(void) {

typedef struct user USER;
USER users[10];
int lkm = 0;
int lopeta = 0;
int valinta;
USER temp;
char tunnus[LKM];
char salasana[LKM];
int k;
int j;


printf("Käyttäjätunnusten hallinta.\n");

while (lopeta != 1) {

printf("Valitse alla olevasta valikosta haluamasi toiminto:\n");
printf("1) Lisää uusi tunnus\n");
printf("2) Tulosta tunnukset\n");
printf("0) Lopeta\n");
printf("Valintasi: ");
scanf("%d", &valinta);
printf("\n");

	switch (valinta) {
		case 1:
			printf("Anna käyttäjätunnus:");
			scanf("%s", tunnus);
			printf("Anna salasana: ");
			scanf("%s", salasana);
			
			strcpy(temp.id, tunnus);
			strcpy(temp.pw, salasana);
			printf("Tunnus '%s' lisättiin listaan.\n", temp.id);
			users[lkm] = temp;
			lkm = lkm + 1;
			printf("\n");
			break;
		case 2:
			j = 1;
			printf("Listalla olevat tunnukset:\n");
			
			for(k = 0; k < lkm; k++) {
				temp = users[k];
				printf("%d. tunnus '%s', salasana '%s', ID '%d'.\n", j, temp.id, temp.pw, k);
				j = j + 1;
			}
			printf("\n");
			break;
		case 0:
			lopeta = 1;
			break;
		default:
			printf("Tuntematon valinta.\n");
	}
}

return 0;
}

/*eof*/
