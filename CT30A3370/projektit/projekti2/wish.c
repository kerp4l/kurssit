#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

	char *puskuri;
	size_t puskuri_koko = 32;

	if (argc == 1) {

		puskuri = (char *) malloc(puskuri_koko*sizeof(char));
		if (puskuri == NULL) {
			perror("Memory allocation failed.\n");
			exit(1);
		}

		printf("wish> ");
		getline(&puskuri, &puskuri_koko, stdin);;

		char *token = strtok(puskuri, " \t\n");
		while (token != NULL) {
			printf("%s\n", token);
			token = strtok(NULL, " \t\n");
		}


		free(puskuri);
		

	}
	else if (argc == 2) {
	}







	return 0;
}
