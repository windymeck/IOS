#include <stdio.h>
#include <dirent.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dp;
	char *loc = NULL;
	char *pointer = NULL;
	pointer = getenv("PWD");
	if(argc == 1){
		dirp = opendir((const char*)pointer);
		loc = pointer;
		printf("You are located in the %s", loc);
		while((dp=readdir(dirp))!=NULL){
			printf("%s \n",dp->d_name);
		}
		printf("\n");
	}
	else{
		dirp = opendir(argv[1]);
		loc = argv[1];
		printf("You are located in the %s", loc);
		while((dp=readdir(dirp))!=NULL){
			printf("%s \n",dp->d_name);
		}
		printf("\n");
	}
	return 0;
}
