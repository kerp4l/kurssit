testi: program.o io.o muisti.o
	gcc program.o io.o muisti.o -o testi -std=c99 -Wall -pedantic
program.o: program.c muisti.h io.h
	gcc program.c -c -std=c99 -Wall -pedantic
muisti.o: muisti.c muisti.h
	gcc muisti.c -c -std=c99 -Wall -pedantic
io.o: io.c io.h
	gcc io.c -c -std=c99 -Wall -pedantic
