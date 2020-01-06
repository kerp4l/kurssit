#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *args[]) {

char jono[20];
int luku;
FILE *tiedosto;
char rivi[50];
tiedosto = fopen(args[1], "r");

while(fgets(rivi, 49, tiedosto)) {
	char *sana1 = strtok(rivi, " ");
	char *sana2 = strtok(NULL, " ");
	strcpy(jono, sana1);
	luku = atoi(sana2);
	printf("Merkkijono on: %s ja kokonaisluku on: %d\n", jono, luku);
}

fclose(tiedosto);



return 0;
}
