#include <stdio.h> 
#include <string.h>




int main(int argc, char *argv[]) 
{

 
  char **ap = argv +1;
  char **ep = argv + argc;
char **testi = argv + 3;



printf("ARGC on: %d\n", argc);


  for ( ; ap < ep ; ap++ ) {


      printf("%d, %s\n", strlen(*ap), *ap);
  } 




return 0;
}












