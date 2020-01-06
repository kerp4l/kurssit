#include <stdio.h>
#include <unistd.h>

int main(void) {

int i = 1;

while (i != 0) {
	printf("Foobar nro: %d\n", i);
	i = i + 1;
	sleep(1);
}

return 0;
}
