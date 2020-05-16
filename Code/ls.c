#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#define path 500

void red () {
    printf("\033[1;31m");
}

int main(int argc, char *argv[])
{
  DIR *dirp;
  struct dirent *dp;
  struct stat fstats;
  char *loc = NULL;
  char pointer[path+1];
  char bar[1] = "/";

  getcwd(pointer, path);
  if(argc == 1){
    dirp = opendir((const char*)pointer);
    loc = pointer;
    //printf("You are located in %s\n", loc);
    printf("\n");
    while((dp=readdir(dirp))!=NULL){
      if(dp->d_name[0] != '.'){
        stat(dp->d_name, &fstats);
        //printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
        if(fstats.st_mode & S_IFDIR){
          red();
          printf("%s",dp->d_name);
          printf("\033[0m");
          printf("/\n");
        }else
          printf("%s\n", dp->d_name);
      }
    }
    printf("\n");
  }
  else if(argc > 1){
    if (stat(argv[1], &fstats) == -1) {
      perror("stat");
    }else{
      strcat(pointer, "/");
      strcat(pointer, argv[1]);
      dirp = opendir((const char*)pointer);
      loc = pointer;
      //printf("You are located in %s\n", loc);
	  printf("\n");
      while((dp=readdir(dirp))!=NULL){
        if(dp->d_name[0] != '.'){
          chdir(pointer);
          stat(dp->d_name, &fstats);
          //printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
          if(fstats.st_mode & S_IFDIR){
            red();
            printf("%s",dp->d_name);
            printf("\033[0m");
            printf("/\n");
          }else
           printf("%s\n", dp->d_name);
        }
      }
      printf("\n");
    }
  } 
  return 1;
}
