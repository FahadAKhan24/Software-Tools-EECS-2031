#include <stdio.h>
#include <string.h>

/*
Fahad Ahmed Khan
214468888
*/
int main(int argc, char *argv[]) {

	if (argc == 2){
       if (!strcmp(argv[1], "42")) {
	 /* printf("similar \n");*/
          return 0;
       }
       else {
	 /* printf("not similar \n"); */
            return 1; 	 
       }
    }
    else {
      /*	printf("no arguments or more than 2 arguments\n"); */
    	return 1;
    }	
}
