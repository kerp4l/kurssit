#include <stdio.h>
#include <stdlib.h>

struct Node {
	int luku;
	struct Node *seuraava;
};
typedef struct Node Solmu;
typedef Solmu *osoitin;

void lisaa(osoitin *, int);
void tulosta(osoitin);
void poista(osoitin *);





int main() {

osoitin p = NULL;


lisaa(&p, 5);
lisaa(&p, 10);
lisaa(&p, 15);

tulosta(p);

poista(&p);
tulosta(p);
lisaa(&p, 666);
tulosta(p);

}








void lisaa(osoitin *p, int i) {

osoitin temp;
osoitin uusi;
uusi = (osoitin) malloc(sizeof(Solmu));
uusi->luku = i;
uusi->seuraava = NULL;

if ((*p) == NULL) {
	(*p) = uusi;
} else {
	temp = (*p);
	while (temp->seuraava != NULL) {
		temp = temp->seuraava;
	}
	temp->seuraava = uusi;
}






}




void tulosta(osoitin p) {

while (p != NULL) {
	printf("%d ", p->luku);
	p = p->seuraava;
}

printf("\n");
}



void poista(osoitin *p) {

osoitin temp = (*p);
(*p) = (*p)->seuraava;
free(temp);
}




































