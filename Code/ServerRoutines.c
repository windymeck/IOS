#include <sys/types.h>		/*ServerRoutines.c */
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define error(a) {perror(a); _exit(1);}
#include "defines.h"

void Acknowledgement(struct t_request *req){
	int fd;
	struct t_answer Answer;

	strcpy(Answer.message, "OK!");
	Answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("Server: open: Server Box");

	write(fd, &Answer, sizeof(struct t_answer));
	close(fd);	
}

void LevelUnlock(struct t_request *req){
	if(strcmp(req->command, "rm") == 0 && (strcmp(req->location, "/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS") == 0 && strcmp(req->argument, "ola") == 0)){
		chmod("/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS/Game/Home/NorthernMeadow", S_IRWXU);
		printf("Level unlocked\n");
	}

}

void RequestTrace(struct t_request *req){
	printf("Server: Request read, Command=%s Location=%s Argument=%s\n", req->command, req->location, req->argument);
}
