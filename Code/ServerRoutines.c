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

static char gamepath[5000];

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
	char cloc[500];
	strcpy(cloc, gamepath);
	strcat(cloc, "/Game/Home/WesternForest/SpellCastingAcademy/PracticeRoom");
	if(strcmp(req->command, "mv") == 0 && (strcmp(req->location, cloc) == 0 && strcmp(req->argument, "PracticeDummy5") == 0)){
		char north[500];
		strcpy(north, gamepath);
		strcat(north, "Game/Home/NorthernMeadow");
		chmod(north, S_IRWXU);
		printf("Level unlocked\n");
	}

}

void RequestTrace(struct t_request *req){
	printf("Server: Request read, Command=%s Location=%s Argument=%s\n", req->command, req->location, req->argument);
}

void getPath(){
	char loc[500];
	getcwd(loc, 500);
	printf("%s\n", loc);
	strcpy(gamepath, loc);
	printf("%s\n", gamepath);
}
