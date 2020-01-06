#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Topi Jussinniemi, 2.2.2018, harjoitus 4, tehtävä 4*/

int main(int argc, char *args[]) {



if (argc == 1) {
	printf("Et antanut syötteitä!\n");
} else {
	switch(args[2][0]) {
		case '+':
			printf("%s + %s = %.2f\n", args[1], args[3], atof(args[1]) + atof(args[3]));
			break;
		case '-':
			printf("%s - %s = %.2f\n", args[1], args[3], atof(args[1]) - atof(args[3]));
			break;
		case 'x':
			printf("%s x %s = %.2f\n", args[1], args[3], atof(args[1]) * atof(args[3]));
			break;
		case '/':
			printf("%s / %s = %.2f\n", args[1], args[3], atof(args[1]) / atof(args[3]));
			break;
		default:
			printf("Virheellinen syöte.\n");
			break;
	}
}

return 0;
}

/*eof*/
