#include <stdio.h>
#include <stdlib.h>

int main() {





int *ptr;
ptr = (int *) malloc(sizeof(int)*3);

int i;

*(ptr+0) = 123;
*(ptr+1) = 78;
*(ptr+2)= 666;


for (i=0; i<3; i++){
	printf("%d\n", *(ptr+i));
}


int *p = (int *) malloc(sizeof(int));
p = &ptr[2];

printf("Pointteri osoittaa lukuun: %d\n", *p);


free(p);



return 0;
}
