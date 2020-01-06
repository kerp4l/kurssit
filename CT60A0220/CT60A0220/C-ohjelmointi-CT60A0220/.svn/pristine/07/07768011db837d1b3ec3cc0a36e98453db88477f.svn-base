/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekijä: Topi Jussinniemi
 * Opiskelijanumero: 0401301
 * Päivämäärä: 28.2.2018
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*****************************************************************************/

struct NodeTulos {
	char nimi[50];
	long int lkm;
	int max;
	int min;
	int keskiarvo;
	int varattuMuisti;
	int kaytettyMuisti;
	struct NodeTulos *pNext;
};

typedef struct NodeTulos TulosSolmu;

TulosSolmu *lisaaTulosSolmu(TulosSolmu *, char nimi[], long int, int, int, int, int, int);
TulosSolmu *tyhjennaTuloslista(TulosSolmu *);
void tulostaTuloslista(TulosSolmu *);
void tallennaTuloslista(TulosSolmu *, char tiedostonNimi[]);


/*****************************************************************************/
/* eof */
