/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekijä: Topi Jussinniemi
 * Opiskelijanumero: 0401301
 * Päivämäärä: 28.2.2018
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*****************************************************************************/

struct NodeNimi {
	char nimi[30];
	long int lkm;
	struct NodeNimi *pNext;
};

typedef struct NodeNimi NimiSolmu;


NimiSolmu *lueTiedosto(NimiSolmu *, char tiedosto[]);
NimiSolmu *lisaaNimiSolmu(NimiSolmu *, char *, char *);
NimiSolmu *tyhjennaNimilista(NimiSolmu *);
long int laskeNimilistanPituus(NimiSolmu *);
int maxPituusNimilista(NimiSolmu *);
int minPituusNimilista(NimiSolmu *);
int kaPituusNimilista(NimiSolmu *, long int);
int varattuMuistiNimilistaKB(int);
int kaytettyMuistiNimilista(NimiSolmu *, long int);


/*****************************************************************************/
/* eof */
