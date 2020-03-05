#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	DIR *dirp;
	struct dirent *dp;
	struct stat fstats;
	char *loc = NULL;
	char *pointer = NULL;
	char bar[1] = "/";

	pointer = getenv("PWD");
	if(argc == 1){
		dirp = opendir((const char*)pointer);
		loc = pointer;
		printf("You are located in %s\n", loc);
		while((dp=readdir(dirp))!=NULL){
			if(dp->d_name[0] != '.'){
				stat(dp->d_name, &fstats);
				//printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
				if(fstats.st_mode & S_IFDIR)
					printf("---->%s/ \n",dp->d_name);
				else
					printf("#%s\n", dp->d_name);
			}
		}
		printf("\n");
	}
	else{
		strcat(pointer, bar);
		strcat(pointer, argv[1]);
		dirp = opendir((const char*)pointer);
		loc = pointer;
		printf("You are located in %s\n", loc);
		while((dp=readdir(dirp))!=NULL){
			if(dp->d_name[0] != '.'){
				chdir(pointer);
				stat(dp->d_name, &fstats);
				//printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
				if(fstats.st_mode & S_IFDIR)
					printf("---->%s/ \n",dp->d_name);
				else
					printf("#%s\n", dp->d_name);
			}
		}
		printf("\n");
	}
	return 0;
}
