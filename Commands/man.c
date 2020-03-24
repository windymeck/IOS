#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 2000

int main(int argc, char *argv[]){
  int fd;
  int n;
  char buffer[BUFSIZE];
  char a[30] = "manfolder/";

  strcat(a, argv[1]);

  fd = open(a, O_RDONLY);
  while((n = read(fd, buffer, BUFSIZE))>0)
    printf("%s\n", buffer);
}
