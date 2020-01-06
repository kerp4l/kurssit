/*
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitustyö, projekti 2, wish.c
Topi Jussinniemi 0401301
*/
/*
LÄHTEET:
1. 
https://c-for-dummies.com/blog/?p=1112
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h> 

struct Node {
	char sijainti[30];
	struct Node *pSeuraava;
};

typedef struct Node Solmu;

Solmu *lisaa_solmu(Solmu *, char *);
Solmu *tyhjenna_lista(Solmu *);
void tulosta_lista(Solmu *);




int main() {

char foo[] = "/bin";
char foo2[] = "usr/bin";
Solmu *pAlku = NULL;

pAlku = lisaa_solmu(pAlku, foo);
pAlku = lisaa_solmu(pAlku, foo2);

tulosta_lista(pAlku);
return 0;
}



Solmu *lisaa_solmu(Solmu *pAlku, char *uusiSijainti) {

Solmu *ptr, *ptrUusi;

if ((ptrUusi = (Solmu *) malloc(sizeof(Solmu))) == NULL) {
	perror("Muistin varaaminen epäonnistui!\n");
	exit(1);
}


strcpy(ptrUusi->sijainti, uusiSijainti);
ptrUusi->pSeuraava = NULL;


if (pAlku == NULL) {
	pAlku = ptrUusi;
} else {
	ptr = pAlku;
	while (ptr->pSeuraava != NULL) {
		ptr = ptr->pSeuraava;
	}
	ptr->pSeuraava = ptrUusi;
}

return pAlku;

}


Solmu *tyhjenna_lista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	pAlku = ptr->pSeuraava;
	free(ptr);
	ptr = pAlku;
}

return pAlku;
}





void tulosta_lista(Solmu *pAlku) {

Solmu *ptr = pAlku;

while (ptr != NULL) {
	printf("%s\n", ptr->sijainti);
	ptr = ptr->pSeuraava;
}

}







