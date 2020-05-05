#include <stdio.h>
#include <sys/fcntl.h>
#include <string.h>
#include <stdlib.h>
#include<unistd.h> 
#define SIZE 1000000

char msg_S[SIZE];

int main(){
	
	int val;
	char msg[SIZE];

	val = open("pipe", O_RDONLY);
	read(val, msg, SIZE);
	
}
