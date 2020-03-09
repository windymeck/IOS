#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

void red () {
	  printf("\033[1;31m");
}

int main(int argc, char *argv[])
{
	int res;
	char *pointer = NULL;

	pointer = getwd("PWD");
	if(argc == 1){
		chdir(pointer);
	}

	res = chdir(argv[1]);

	if(res == 0){
		printf("todo bien\n");
		exit(0);
	}else{
		switch(res){
			case EACCES: perror("Permission denied");
			break;
			case ENOENT: perror("No such file or directory"); printf("enoent\n");
			//default: perror("Couldn't change directory to %s", (char *)argv[1]); 
		}
	}
}
