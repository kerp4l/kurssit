/*Topi Jussinniemi, 25.2.2018, harjoitus 7, tehtävä 1*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* varaaMuistiaNumeroille(int koko) {

	int *lista;
	if ((lista = (int *) malloc(koko * sizeof(int))) == NULL) {
		printf("Muistin varaaminen epäonnistui.\n");
		exit(1);
	}
	return lista;

}

void vapautaMuisti(int *lista) {
free(lista);
}
