/*
CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
Harjoitus 5, tehtävä 2
Topi Jussinniemi
foo.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

char *merkkijono;
merkkijono = (char *) malloc(7);
strcpy(merkkijono, "Foobar");
printf("%s\n", merkkijono);


return 0;
}

/*eof*/
