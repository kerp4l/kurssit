#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char *argv[]) {
	
	int i, j, k, n, rivi_lkm, lkm, t;
	char merkki;

	if (argc == 1) {
		printf("my-unzip: file1 [file2 ..]\n");
		exit(1);
	} else {
		for (i = 1; i < argc; i++) {
			
			FILE *tiedosto;
			tiedosto = fopen(argv[i], "rb");
			
			if (tiedosto == NULL) {
				perror("my-unzip cannot open file.\n");
				exit(1);
			}
			
			fseek(tiedosto, -4, SEEK_END);
			fread(&rivi_lkm, 4, 1, tiedosto);
			fseek(tiedosto, 0, SEEK_SET);
			
			for (j = 0; j < rivi_lkm; j++) {

				fread(&n, 4, 1, tiedosto);

				for (k = 0; k < n; k++) {

					fread(&lkm, 4, 1, tiedosto);
					fread(&merkki, 1, 1, tiedosto);
					
					for(t = 0; t < lkm; t++) {
						printf("%c", merkki);
					}
					
				}
				fread(&merkki, 1, 1, tiedosto);
				printf("%c", merkki);
			}

			fclose(tiedosto);
		}
		
	}













	return 0;
}
