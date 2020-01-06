#include <stdio.h>

/*Topi Jussinniemi, 2.2.2018, harjoitus 4, tehtävä 5*/

int fibonacci(int k, int x1, int x2);

int main(void) {

int luku;
int fib;
int nolla = 0;
int yksi = 1;

printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
scanf("%d", &luku);

fib = fibonacci(luku, nolla, yksi );

printf("Luvun %d Fibonaccin luku on %d.\n", luku, fib);



return 0;
}

int fibonacci(int k, int x1, int x2) {

if(k > 0) {
	return fibonacci(k-1,x2, x1+x2);
}
}

/*eof*/
