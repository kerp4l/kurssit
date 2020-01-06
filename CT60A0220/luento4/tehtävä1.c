#include <stdio.h>


/*Topi Jussinniemi, 1.2.2018, harjoitus 4, tehtäcä1*/

struct kirja {
	char nimi[50];
	int painovuosi;
	int hylly;
};

int main(void) {

struct kirja book;

printf("Anna kirjan nimi: ");
gets(book.nimi);

printf("Anna kirjan painovuosi: ");
scanf("%d", &book.painovuosi);

printf("Anna kirjan hyllypaikka: ");
scanf("%d", &book.hylly);

printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", book.nimi, book.painovuosi, book.hylly);







return 0;
}

/*eof*/
