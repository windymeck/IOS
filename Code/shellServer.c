#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define error(a) {perror(a);_exit(1);}

#include "ServerRoutines.c"
//#include "defines.h"

int main(int argc, char *argv[]){
	struct t_request req;

	int n;
	int mailbox;

	mknod(FIFO_SHELL_SERVER, S_IFIFO | 0666, 0);

	int fd1;
	if((fd1 = open(FIFO_SHELL_SERVER, O_RDWR)) < 0)
		error("Client: open FIFO server!!");
	while(1){
		if((n = read(fd1, &req, sizeof(struct t_request))) <= 0)
			error("Client: read server box");
		RequestTrace(&req);
		LevelUnlock(&req);
		Acknowledgement(&req);
	}
}
