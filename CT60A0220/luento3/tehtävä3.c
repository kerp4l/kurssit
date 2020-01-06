#include <stdio.h>

/*Topi Jussinniemi, 27.1.2018, harjoitus 3, tehtävä 3*/

void kirjoita(char mjono1[31], char* mjono2);

int main(void) {

char jono1[31];
char jono2[31];

printf("Anna ensimmäinen merkkijono: ");
gets(jono1);

kirjoita(jono1, jono2);

printf("Merkkijono 1 on '%s'.\n", jono1 );
printf("Merkkijono 2 on '%s'.\n", jono2);

return 0;
}

void kirjoita(char mjono1[31], char* mjono2) {

int koko = 0;
char temp;
temp = mjono1[0];

while (temp != '\0') {
	mjono2[koko] = temp;
	mjono2[koko + 1] = '\0';
	koko = koko + 1;
	temp = mjono1[koko];
}

}
