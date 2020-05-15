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

int main(int argc, char *argv[]){
	struct t_request req;

	int n;
	int mailbox;

	mknod(FIFO_SHELL_SERVER, S_IFIFO | 0666, 0);

	int fd1;
	if((fd1 = open(FIFO_SHELL_SERVER, O_RDWR)) < 0)
		error("Client: open FIFO server!!");
	getPath();
	while(1){
		if((n = read(fd1, &req, sizeof(struct t_request))) <= 0)
			error("Client: read server box");
		if(strcmp(req.command, "mv") == 0){
			RequestTrace(&req);
			LevelUnlock(&req);
			UnlockTunnel(&req);
			Acknowledgement(&req);
		}else if(strcmp(req.command, "less") == 0){
			RequestTrace(&req);
			UnlockBackRoom(&req);
			Acknowledgement(&req);
		}else if(strcmp(req.command, "rm") == 0){
			RequestTrace(&req);
			UnlockFarm(&req);
			UnlockSlide(&req);
			UnlockCaveOfDisgruntedTrolls(&req);
			Acknowledgement(&req);
		}else if(strcmp(req.command, "touch") == 0){
			RequestTrace(&req);
			UnlockClearing(&req);
			Acknowledgement(&req);
		}else if(strcmp(req.command, "sudo") == 0){
			RequestTrace(&req);
			ParadiseUnlockAck(&req);
			Acknowledgement(&req);
		}else{
		RequestTrace(&req);
		Acknowledgement(&req);
		}
	}
}
