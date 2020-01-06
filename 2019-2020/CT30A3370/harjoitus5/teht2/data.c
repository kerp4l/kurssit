/*
CT30A33170 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitus 5, tehtävä 2
Topi Jussinniemi
data.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int *ptr;
ptr = (int *) malloc(100 * sizeof(int));

if (ptr == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}

ptr[100] = 0;

return 0;
}

/*eof*/
