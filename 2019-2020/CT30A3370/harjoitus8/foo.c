#include <stdio.h>

int main(void) {
int i, j;

printf("Anna jokin kokonaisluku, niin ohjelma kertoo sen kahdella.\n");
printf("Anna luku 0, mikäli haluat lopettaa ohjelman.\n");
while (i != 0){
	printf("Anna jokin kokonaisluku: ");
	scanf("%d", &i);
	j = 2 * i;
	printf("%d * 2 = %d\n", i, j);
}

return 0;
}
