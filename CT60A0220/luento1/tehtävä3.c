#include <stdio.h>

/*Topi Jussinniemi, 16.1.2018, Harjoitus 1, tehtävä 3*/

int main(void) {

int luku1;
int luku2;
int summa;
int jako;

printf("Anna ensimmäinen kokonaisluku: ");
scanf("%d", &luku1);

printf("Anna toinen kokonaisluku: ");
scanf("%d", &luku2);

summa = (luku1 + luku2) * 2;
jako = luku1 / luku2 - 3;

printf("(%d + %d) * 2 = %d\n", luku1, luku2, summa);
printf("(%d / %d) - 3 = %d\n", luku1, luku2, jako);

int jj = 17%3;
printf("17 %% 3 = %d\n", jj);


return 0;
}

/*eof*/
