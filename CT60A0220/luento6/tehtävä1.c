/*Topi Jussinniemi, 18.2.2018, harjoitus 6, tehtävä 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
	int luku;
	struct Node *pNext;
};

typedef struct Node Solmu;

int main(void) {

Solmu *pAlku = NULL, *pLoppu = NULL, *ptr;
int valinta = 1;

printf("Anna listan luvut.\n");

while (valinta != 0) {

	printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
	scanf("%d", &valinta);
	
	if (valinta == 0) {
		printf("Listassa on seuraavat luvut:");
		ptr = pAlku;
		while(ptr != NULL) {
			printf(" %d", ptr->luku);
			ptr = ptr->pNext;
		}

		ptr = pAlku;
		while (ptr != NULL) {
			pAlku = ptr->pNext;
			free(ptr);
			ptr = pAlku;
		}
		printf("\n");
		printf("Kiitos ohjelman käytöstä.\n");
	} else {
		if ((ptr = (Solmu*) malloc(sizeof(Solmu))) == NULL) {
			perror("Muistin varaaminen epäonnistui!");;
			exit(1);
		}
		ptr->luku = valinta;
		ptr->pNext = NULL;
		
		if (pAlku == NULL) {
			pAlku = ptr;
			pLoppu = ptr;
		} else {
			pLoppu->pNext = ptr;
			pLoppu = ptr;
		}
}
}


return 0;
}

/*eof*/
