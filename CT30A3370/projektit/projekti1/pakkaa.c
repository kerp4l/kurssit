#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	
	char *puskuri;
	size_t puskuri_koko = 32;
	size_t pituus;
	int i;

	if (argc < 3) {
		printf("my-zip: file1 [file2 ...]\n");
		exit(1);
	} else {
		for (i = 2; i < argc; i++) {
			
			FILE *pakattava;
			pakattava = fopen(argv[i], "r");
		
			if (pakattava == NULL) {
				perror("my-zip cannot open file.\n");
				exit(1);
			}
		
			while (!feof (pakattava)) {
				
				puskuri = (char *) malloc(puskuri_koko*sizeof(char));
				
				if (puskuri == NULL) {
					perror("Memory allocation failed.\n");
					exit(1);
				}
				
				pituus = getline(&puskuri, &puskuri_koko, pakattava);
				printf("%s", puskuri);
				free(puskuri);
			}
			fclose(pakattava);
		}
	
	}





	return 0;
}






