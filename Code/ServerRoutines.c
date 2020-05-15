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

void ClearingUnlockAck(struct t_request *req){
	int fd;
	struct t_answer answer;

	strcpy(answer.message, "clearing unlocked!!");
	answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("server: open: server box");

	write(fd, &answer, sizeof(struct t_answer));
	close(fd);	
}

void CaveUnlockAck(struct t_request *req){
	int fd;
	struct t_answer answer;

	strcpy(answer.message, "You revealed the caveOfDisgruntiedTrolls!!");
	answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("server: open: server box");

	write(fd, &answer, sizeof(struct t_answer));
	close(fd);	
}

void SlideUnlockAck(struct t_request *req){
	int fd;
	struct t_answer answer;

	strcpy(answer.message, "You defeated the Ugly trolls, now you can go to the slide!!");
	answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("server: open: server box");

	write(fd, &answer, sizeof(struct t_answer));
	close(fd);	
}

void ParadiseUnlockAck(struct t_request *req){
	int fd;
	struct t_answer answer;

	strcpy(answer.message, "GAME OVER!!");
	answer.Type  = REQUEST_SERVED;
	

	if((fd = open(req->answerBox, O_RDWR)) < 0)
		error("server: open: server box");

	write(fd, &answer, sizeof(struct t_answer));
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
	strcpy(gamepath, loc);
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
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/Library");
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
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath");
	if(strcmp(req->command, "rm") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "LargeBoulder") == 0){
		char f[500];
		strcpy(f, gamepath);
		strcat(f, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/RockyPath/Farm");
		chmod(f, S_IRWXU);
		FarmUnlockAck(req);
	}
}

void UnlockClearing(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge");
	if(strcmp(req->command, "touch") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "Plank") == 0){
		char cle[500];
		strcpy(cle, gamepath);
		strcat(cle, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing");
		chmod(cle, S_IRWXU);
		ClearingUnlockAck(req);
	}
}

void UnlockCaveOfDisgruntedTrolls(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath");
	if(strcmp(req->command, "rm") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "ThornyBrambles") == 0){
		char ca[500];
		strcpy(ca, gamepath);
		strcat(ca, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls");
		chmod(ca, S_IRWXU);
		CaveUnlockAck(req);
	}
}

void UnlockSlide(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls");
	if(strcmp(req->command, "rm") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "AbsolutelyHideousTroll") == 0){
		char s[500];
		strcpy(s, gamepath);
		strcat(s, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide");
		chmod(s, S_IRWXU);
		SlideUnlockAck(req);
	}
}

void UnlockParadise(struct t_request *req){
	char dr[500];
	strcpy(dr, gamepath);
	strcat(dr, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles");
	if(strcmp(req->command, "sudo") == 0 && strcmp(req->location, dr) == 0 && strcmp(req->argument, "IHTFP") == 0){
		char pa[500];
		strcpy(pa, gamepath);
		strcat(pa, "/Game/Home/NorthernMeadow/EasternMountains/Cave/DarkCorridor/DarkRoom/Tunnel/StoneChamber/Portal/TownSquare/BrokenBridge/Clearing/OminousLookingPath/CaveOfDisgruntiedTrolls/Slide/KernelFiles/Paradise");
		chmod(pa, S_IRWXU);
		ParadiseUnlockAck(req);
	}
}
