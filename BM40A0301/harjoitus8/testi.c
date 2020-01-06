#include <stdio.h>

void ali(int *);

void ali(int *);

int main() {


int i = 5;
int *p = &i;

printf("Eka %d\n", *p);

ali(p);

printf("Toka %d\n", *p);
printf("Viimeinen on: %d\n", i);



return 0;
}

void ali(int *ptr) {
*ptr = 666;
}
