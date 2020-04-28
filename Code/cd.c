#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <fcntl.h>

#define path 200
int main(int argc, char**argv){
  char od[path+1];
  char new[path+1];
  int res = 0;

  getcwd(od, path);
  //printf("pwd: %s\n", od);
  //printf("cd: %s\n", argv[1]);
  res = chdir(argv[1]);
  getcwd(new, path);
  printf("%s\n", new);

  if(res < 0){
    switch(res){
      case EACCES: perror("Permission denied");
      break;
      case EIO:  perror("An input output error occured");
      break;
      case ENOTDIR: perror("A component of path not a directory"); 
      break;
      case ENOENT: perror("No such file or directory"); printf("enoent\n");
      
      default: perror("Couldn't change directory");
    }
  }
  //printf("pwd %s\n", new);
  return 1;
}