//////MYSHELL1////////////////////////////////////
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20
#define path 200
#define command "/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS/Commands/"

/////////// reading commands:

int read_args(int* argcp, char* args[], int max, int* eofp)
{
   static char cmd[MAXLINE];
   char* cmdp;
   int ret,i;

   *argcp = 0;
   *eofp = 0;
   i=0;
   while ((ret=read(0,cmd+i,1)) == 1) { 
      if (cmd[i]=='\n') break;  // correct line
      i++;
      if (i>=MAXLINE) {
         ret=-2;        // line too long
         break;
      }
   }

   switch (ret)
   {
     case 1 : cmd[i+1]='\0';    // correct reading 
              break;
     case 0 : *eofp = 1;        // end of file
              return 0;
              break;
     case -1 : *argcp = -1;     // reading failure
              fprintf(stderr,"Reading failure \n");
              return 0;
              break;
     case -2 : *argcp = -1;     // line too long
              fprintf(stderr,"Line too long -- removed command\n");
              return 0;
              break;
   }
   // Analyzing the line
   cmdp= cmd;
   for (i=0; i<max; i++) {  /* to show every argument */
      if ((args[i]= strtok(cmdp, " \t\n")) == (char*)NULL) break;
      cmdp= NULL;
   }
   if (i >= max) {
      fprintf(stderr,"Too many arguments -- removed command\n");
      return 0;
   }
   *argcp= i;
   return 1;
}

///////////////////////////////////////

int execute(int argc, char *argv[])
{
	int id;
  char a[100] = command;

  if (strcmp(argv[0], "cd") == 0){
    cd(argc, argv);
  }else if(strcmp(argv[0], "ls") == 0){
    ls(argc, argv);
  }else{

  strcat(a, argv[0]);
	
	switch(id = fork()){
		  case -1:
          perror("fork");
    	    break;
      case 0:
       	  if( execv(a, argv) == -1 )
       		fprintf(stderr, "The program %s couldn't be executed.\n", command);
          break; 	    
      default:
      	wait(NULL);
	}
}
}

int cd(int argc, char**argv){
  char od[path+1];
  char new[path+1];

  getcwd(od, path);
  printf("pwd: %s\n", od);
  printf("cd: %s\n", argv[1]);
  chdir(argv[1]);
  getcwd(new, path);
  printf("pwd %s\n", new);
  return 1;
}


void red () {
    printf("\033[1;31m");
}

int ls(int argc, char *argv[])
{
  DIR *dirp;
  struct dirent *dp;
  struct stat fstats;
  char *loc = NULL;
  char pointer[path+1];
  char bar[1] = "/";

  getcwd(pointer, path);
  if(argc == 1){
    dirp = opendir((const char*)pointer);
    loc = pointer;
    printf("You are located in %s\n", loc);
    while((dp=readdir(dirp))!=NULL){
      if(dp->d_name[0] != '.'){
        stat(dp->d_name, &fstats);
        //printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
        if(fstats.st_mode & S_IFDIR){
          red();
          printf("%s",dp->d_name);
          printf("\033[0m");
          printf("/\n");
        }else
          printf("%s\n", dp->d_name);
      }
    }
    printf("\n");
  }
  else{
    strcat(pointer, bar);
    strcat(pointer, argv[1]);
    dirp = opendir((const char*)pointer);
    loc = pointer;
    printf("You are located in %s\n", loc);
    while((dp=readdir(dirp))!=NULL){
      if(dp->d_name[0] != '.'){
        chdir(pointer);
        stat(dp->d_name, &fstats);
        //printf("Mode: %s%lo\n", dp->d_name, (unsigned long) fstats.st_mode);
        if(fstats.st_mode & S_IFDIR){
          red();
          printf("%s",dp->d_name);
          printf("\033[0m");
          printf("/\n");
        }else
          printf("%s\n", dp->d_name);
      }
    }
    printf("\n");
  }
  return 0;
}



int main ()
{
   char * Prompt = "[Terminus]>> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];

   while (1) {
      write(0,Prompt, strlen(Prompt));
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         execute(argc, args);
      }
      if (eof) exit(0);
   }
}
