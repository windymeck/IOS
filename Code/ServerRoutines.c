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

void LevelUnlockAck(struct t_request *req){
	int fd;
	struct t_answer Answer;

	strcpy(Answer.message, "NorthernMeadow Unlocked!!");
	Answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("Server: open: Server Box");

	write(fd, &Answer, sizeof(struct t_answer));
	close(fd);	
}

void TunnelUnlockAck(struct t_request *req){
	int fd;
	struct t_answer Answer;

	strcpy(Answer.message, "Tunnel Unlocked!!");
	Answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("Server: open: Server Box");

	write(fd, &Answer, sizeof(struct t_answer));
	close(fd);	
}

void BackRoomUnlockAck(struct t_request *req){
	int fd;
	struct t_answer Answer;

	strcpy(Answer.message, "You opened the back room!!");
	Answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("Server: open: Server Box");

	write(fd, &Answer, sizeof(struct t_answer));
	close(fd);	
}

void FarmUnlockAck(struct t_request *req){
	int fd;
	struct t_answer Answer;

	strcpy(Answer.message, "You revealed the farm!!");
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
		strcat(north, "/Game/Home/NorthernMeadow");
		chmod(north, S_IRWXU);
		LevelUnlockAck(req);
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

void UnlockTunnel(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom");
	if(strcmp(req->command, "mv") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "Boulder") == 0){
		char tunnel[500];
		strcpy(tunnel, gamepath);
		strcat(tunnel, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel");
		chmod(tunnel, S_IRWXU);
		TunnelUnlockAck(req);
	}
}

void UnlockBackRoom(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TowSquare/Library");
	if(strcmp(req->command, "less") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "InconscpicuousLever") == 0){
		char lib[500];
		strcpy(lib, gamepath);
		strcat(lib, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library/BackRoom");
		chmod(lib, S_IRWXU);
		BackRoomUnlockAck(req);
	}
}

void UnlockFarm(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TowSquare/RockyPath");
	if(strcmp(req->command, "rm") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "LargeBoulder") == 0){
		char f[500];
		strcpy(f, gamepath);
		strcat(f, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TowSquare/RockyPath/Farm");
		chmod(f, S_IRWXU);
		FarmUnlockAck(req);
	}
}
