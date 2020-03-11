#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 2000

int main(int argc, char *argv[]){
	int fd1, fd2;
	int n;
	char buffer[BUFSIZE];

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while((n = read(fd1, buffer, BUFSIZE)) > 0)
		write(fd2, buffer, n);
	close(fd1);
	close(fd2);
}
