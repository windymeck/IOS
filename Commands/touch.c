#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>



int main(int argc, char *argv[]){
	int fd;

	fd = open (argv[1], O_WRONLY | O_CREAT | O_TRUNC , 0664);
	close(fd);
}