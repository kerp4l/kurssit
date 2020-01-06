#include <stdio.h>
#include <string.h>




int main() {


	char asd[] = "eka toka kolmas";
	char *token = strtok(asd, " ");
	while (token != NULL) {
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}







return 0;
}
