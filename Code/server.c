#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>
#include <stdlib.h>

main(){
	int val;
	char msg[200];
	
	while(strcmp(msg, "exit") != 0){
		val = open("pipe", O_RDONLY);
		read(val, msg, sizeof(msg));
		printf("location: %s\n", msg);
	}
	exit(0);
}
