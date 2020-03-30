#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 2000

void match(char* argv[]){
  int fd;
  int n;
  int j = 0;
  char buffer[BUFSIZE];
  char temp;
  char l [30];
  int line = 0;
  if((fd=open(argv[2],O_RDONLY)) > 0){
  	while((n = read(fd, &temp, sizeof(char)))>0){
		if(temp != '\n'){
			l[j] = temp;
			j++;
		}else{
			line++;
			if(strstr(l, argv[1])!= NULL)
				printf("%s, line:%d\n", argv[1], line);
				memset(l, 0, sizeof(l));
				j = 0;
			}
		}
  	}
}


int main(int argc, char *argv[]){
  struct stat stt;
  if(argc == 3){
  	if(stat(argv[2], &stt) == 0){
  		match(argv);
  	}
  }
}