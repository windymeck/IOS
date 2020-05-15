#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char*argv[]){
	if(argc==2) {
		if(strcmp(argv[1], "IHTFP")==0){
			printf("Password is correct\n");
		}else{
			printf("Incorrect password!\n");
		}
	}else{
		printf("Incorrect format of the command!\n");
	}
}
