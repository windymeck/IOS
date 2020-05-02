#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 1000000

main(){
	int val;
	int valp;
	int valarg;
	char msg[SIZE];
	char arg[SIZE];
	char path[SIZE];
	
	while(strcmp(msg, "exit") != 0){
		val = open("pipe", O_RDONLY);
		//valarg = open("pipe1", O_RDONLY);
		valp = open("pipe2", O_RDONLY);
		read(val, msg, sizeof(msg));
		//read(valarg, arg, sizeof(arg));
		read(valp, path, sizeof(path));
		printf("command: %s\n", msg);
		printf("location: %s\n", path);
		//printf("argument: %s\n", arg);
		if(strcmp(msg, "ls") == 0){
			printf("Hello\n");
		}else if(strcmp(msg, "rm") == 0){
			if(strcmp(path, "/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS") == 0)
				printf("new level unlocked\n");
		}
	}
}
