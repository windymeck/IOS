#include <stdio.h>
#include <unistd.h>
#include <errno.h>

void main (int argc, char **argv)
{
if (argc!=3){
  printf("Introduce the correct parameters\n");
  
  }else {  
//    int r = rename(argv[1],argv[2]);
    int r = link(argv[1], argv[2]);
    unlink(argv[1]);
    if(r==0){
    printf("You have moved from %s to %s\n", argv[1], argv[2]);
    }
  else { perror("mv:"); }
    }
  }

