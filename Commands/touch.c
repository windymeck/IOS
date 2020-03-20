#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFSIZE 2000


int main(int argc, char *argv[]){
	int fd;
	char buffer[BUFSIZE];

	fd = open (argv[1], O_WRONLY | O_CREAT | O_TRUNC , 0664);
	close(fd);
}
