testi: program.o lista.o
	gcc program.o lista.o -o testi -std=c99 -Wall -pedantic
program.o: program.c lista.h
	gcc program.c -c -std=c99 -Wall -pedantic
lista.o: lista.c lista.h
	gcc lista.c -c -std=c99 -Wall -pedantic
