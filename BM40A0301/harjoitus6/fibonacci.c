/*
BM40A0301 Tietorakenteet ja algoritmit
Harjoitus 6, tehtävä 1
Topi Jussinniemi 0401301
*/

#include <stdio.h>


int main(void) {


int n, i, temp;
int fib1 = 1;
int fib2 = 1;

printf("Ohjelma laskee Fibonaccin lukuja.\n");
printf("MMontako Fibonaccin lukua lasketaan: ");
scanf("%d",&n);

if (n <= 0) {
	printf("Annoit virheellisen syötteen! Ohjelma suljetaan.\n");
} if (n == 1 || n == 2) {
	for (i = 1; i < (n + 1); i++) {
		printf("%d. %d\n", i, fib1);
	}
} else {
	
	printf("1. 1\n");
	printf("2. 1\n");
	
	for (i = 3; i <= n; i++) {
		temp = fib1 + fib2;
		fib1 = fib2;
		fib2 = temp;
		
		printf("%d. %d\n", i, temp);
	}
}

printf("Kiitos ohjelman käytöstä. Ohjelma suljetaan.\n");

return 0;
}

/*eof*/
