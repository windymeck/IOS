#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 2000

int main(int argc, char *argv[]){
  FILE *fd;
  int n;
  char buffer[BUFSIZE];
  char temp [300];

  fd = open(argv[1], "r");
  while((n = read(fd, buffer, BUFSIZE))>0){
    fgets(temp, 1000, fd);
	if(strstr(temp, argv[2]))
		printf("%s",temp);
  }
  fclose(fd);
}