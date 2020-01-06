#include <stdio.h>

void ali(int k[]);


int main() {


int i[2]; i[0] = 5; i[1] = 10;
ali(i);

printf("Jee jee %d\n", i[1]);



return 0;
}


void ali(int k[]) {
	k[1] = 666;
}
