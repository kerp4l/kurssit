#include <stdio.h>

int main(void) {

int i, j;

printf("Ohjelma tulostaa sanan \"foobar\" niin monta kertaa, kuin käyttäjä haluaa.\n");
printf ("Syöte 0 lopettaa ohjelman.\n");

while (i != 0){
	printf("Montako kertaa tulostetaan sana \"Foobar\": ");
	scanf("%d", &j);
	for(i = 0; i < j; i++) {
		printf("Foobar\n");
	}
}

return 0;
}
