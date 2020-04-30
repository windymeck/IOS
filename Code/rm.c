#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define path 200

int main (int argc, char *argv[]){
	char ptf[path+1];
	int e;
	int len;
	const char newline[]="\n";

	getcwd(ptf, path);
	strcat(ptf, "/");
	strcat(ptf, argv[1]);
	len = strlen(argv[1]);
	//printf("%s deleted\n", argv[1]);
	write(1, argv[1], len);
	write(1, " deleted\n", 8);
	write(1, newline, strlen(newline));
	e = unlink(ptf);
	if(e < 0){
		switch(e){
			case EACCES: perror("Permission denied");
          	break;
          	case EIO:  perror("An input output error occured");
          	break;
          	case ENOTDIR: perror("A component of path not a directory"); 
          	break;
          	case ENOENT: perror("No such file or directory"); printf("enoent\n");
      
          default: perror("Couldn't read the file");
		}
	}
}
