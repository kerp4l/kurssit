/*
CT30A33170 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitus 5, tehtävä 3
Topi Jussinniemi
free_data.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int i;
int j = 0;
int *ptr;
ptr = (int *) malloc(100 * sizeof(int));

if (ptr == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}


for (i = 0; i < 100; i++) {
	ptr[i] = i;
}

printf("Listassa olevat luvut:\n");
for (i = 0; i < 100; i++) {
	if (j == 24) {
		printf("%d\n", ptr[i]);
		j = 0;
	} else {
		printf("%d ", ptr[i]);
		j = j + 1;
	}
}


printf("Vapautetaan muisti.\n");
free(ptr);

printf("Listan 50. luku on:\n");
printf("%d\n", ptr[49]);

return 0;
}

/*eof*/
