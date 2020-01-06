#include <stdio.h>
/*Topi Jussinniemi, 18.1.2018, harjoitus 1, tehtävä 5*/

int main(void) {

char eNimi[20];
char sNimi[20];
int i;
float paino;

printf("Anna etunimesi: ");
scanf("%s", eNimi);

printf("Anna sukunimesi: ");
scanf("%s", sNimi);

printf("Anna ikäsi: ");
scanf("%d", &i);

printf("Anna painosi: ");
scanf("%f", &paino);

printf("Nimesi on %s %s, ikäsi on %d vuotta ja painat %.1f kg.\n", eNimi, sNimi, i, paino);





return 0;
}

/*eof*/
