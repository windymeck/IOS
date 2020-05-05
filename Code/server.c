#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 1000000

int main(){
	int val;
	int valp;
	int valarg;
	char msg[SIZE];
	char arg[SIZE];
	char path[SIZE];
	const char newline[]="\n";	

	val = open("pipe", O_RDONLY);
	valp = open("pipe2", O_RDONLY);
	while(strcmp(msg, "potato") != 0){
		//valarg = open("pipe1", O_RDONLY);
		read(val, msg, sizeof(msg));
		//read(valarg, arg, sizeof(arg));
		read(valp, path, sizeof(path));
		printf("command: %s\n", msg);
		printf("location: %s\n", path);
		//printf("argument: %s\n", arg);
		if(strcmp(msg, "ls") == 0){
			printf("Hello\n");
		}else if(strcmp(msg, "rm") == 0){
			if(strcmp(path, "/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS") == 0){
			write(1, "new level unlocked", 18);
			write(1, newline, strlen(newline));
		}
		}else if(strcmp(msg, "exit") == 0){
			write(1, "bye!", 4);
			exit(0);
		}
	}
	return 0;
}
