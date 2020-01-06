#include <stdio.h>
/*Topi Jussinniemi, 16.1.2018*/
/*Harjoitus 1, tehtävä 2*/

int main(void){
int luku1;
float luku2;

printf("Anna kokonaisluku: ");
scanf("%d", &luku1);
printf("Anna liukuluku: ");
scanf("%f", &luku2);

printf("Annoit luvut %d ja %.2f.\n", luku1, luku2);

return 0;
}

/*eof*/
