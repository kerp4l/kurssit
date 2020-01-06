/*
CT30A33170 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitus 5, tehtävä 3
Topi Jussinniemi
failed_free.c
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

int i;
int j = 0;
int *data;

data = (int *) malloc(sizeof(int)*100);
	if (data == NULL) {
		perror("Muistin varaaminen epäonnistui!\n");
		exit(1);
	}

for (i = 0; i < 100; i++) {
	data[i] = i;
}


printf("Listassa olevat luvut:\n");
for (i = 0; i < 100; i++) {
	if (j == 24) {
		printf("\n");
		j = 0;
	} else {
		printf("%d ", data[i]);
		j = j + 1;
	}
}

int *ptr = (int *) malloc(sizeof(int));
ptr = &data[49];
printf("Listan 50. luku on: %d\n", *ptr);

printf("Seuraavaksi räjähtää galaksit, kun koitetaan vapauttaa muistia keskeltä listaa.\n");
free(ptr);

return 0;
}

/*eof*/
