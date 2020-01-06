#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Topi Jussinniemi, 11.2.2018, harjoitus 5, tehtävä 1*/

void korotus(int *x);

int main(int argc, char *args[]) {

int luku;

if (argc == 1) {
	printf("Et antanut lukua!\n");
} else {
	luku = atoi(args[1]);
	printf("Luku on %d.\n", luku);
	korotus(&luku);
	printf("Luvun neliö on %d.\n", luku);
}


return 0;
}

void korotus(int *x) {
int temp = *x;
*x = temp*temp;
}

/*eof*/
