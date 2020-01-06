ht: paaohjelma.o nimilista.o tuloslista.o
	gcc paaohjelma.o nimilista.o tuloslista.o -o ht -lm -std=c99 -Wall -pedantic
paaohjelma.o: paaohjelma.c nimilista.h tuloslista.h
	gcc paaohjelma.c -c -std=c99 -Wall -pedantic
nimilista.o: nimilista.c nimilista.h
	gcc nimilista.c -c -std=c99 -Wall -pedantic
tuloslista.o: tuloslista.c tuloslista.h
	gcc tuloslista.c -c -std=c99 -Wall -pedantic
