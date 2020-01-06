/*Topi Jussinniemi, 26.2.2018, harjoitus 7, tehtävä 4*/

struct Node {
	int luku;
	struct Node *pNext;
};

typedef struct Node Solmu;

Solmu *lisaaSolmu(Solmu *pAlku, int i);
void tulosta(Solmu *pAlku);
Solmu *tyhjenna(Solmu *pAlku);
Solmu *lisaaKeskelle(Solmu *, int, int, int);
Solmu *poistaAlkio(Solmu *, int);
