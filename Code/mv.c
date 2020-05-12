#include <stdio.h>
#include <unistd.h>

void main (int argc, char **argv)
{
if (argc!=3){
  printf("Introduce the correct parameters\n");
  
  }else {  
    int r = rename(argv[1],argv[2]);
    if(r==0){
    printf("You have moved to %s\n", argv[1], argv[2]);
    }
  else { printf("An error has occurred\n"); }
    }
  }
}
