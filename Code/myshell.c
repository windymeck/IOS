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
#define MAXARGS 250
#define path 20000

static char gamepath[5000]; 
//#define pathls 200
//#define command "/home/unai/Uni/2.MAILA/ISO/PROJECT/IOS/Commands/"

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
  char a[10000];
  /**/
  



  if (strcmp(argv[0], "cd") == 0){
    cd(argc, argv);
 /* }else if(strcmp(argv[0], "ls") == 0){
    ls(argc, argv);
  */}else if(strcmp(argv[0], "exit") == 0){
    printf("bye!!\n");
    exit(0);
  }else{

 /* chdir("Commands");
  getcwd(a, 100);
  //printf("%s\n", a);
  chdir("..");
  //printf("%s\n", a);
  strcat(a, "/");
  strcat(a, argv[0]);
	printf("\n");*/
  strcpy(a, gamepath);
  printf("%s\n", a);
  strcat(a, argv[0]);

	switch(id = fork()){
		  case -1:
          perror("fork");
    	    break;
      case 0:
       	  if( execv(a, argv) == -1 )
       		fprintf(stderr, "The program %s couldn't be executed.\n", a);
          break; 	    
      default:
      	wait(NULL);
	}
}
}


int cd(int argc, char**argv){
  char od[path+1];
  char new[path+1];
  int res = 0;

  getcwd(od, path);
  //printf("pwd: %s\n", od);
  //printf("cd: %s\n", argv[1]);
  res = chdir(argv[1]);
  getcwd(new, path);

  if(res != 0){
    switch(res){
      case EACCES: perror("Permission denied");
      break;
      case EIO:  perror("An input output error occured");
      break;
      case ENOTDIR: perror("A component of path not a directory"); 
      break;
      case ENOENT: perror("No such file or directory"); printf("enoent\n");
      
      default: perror("Couldn't change directory");
    }
  }
  //printf("pwd %s\n", new);
  return 1;
}


/*int ls(int argc, char *argv[])
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
    //printf("You are located in %s\n", loc);
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
  else if(argc > 1){
    if (stat(argv[1], &fstats) == -1) {
      perror("stat");
    }else{
      strcat(pointer, "/");
      strcat(pointer, argv[1]);
      dirp = opendir((const char*)pointer);
      loc = pointer;
      //printf("You are located in %s\n", loc);
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
  } 
  return 1;
}*/
void red () {
    printf("\033[1;31m");
}

void green(){
    printf("\033[32m");
}





int main ()
{
   char * Prompt = "[Terminus] >> ";
   int eof= 0;
   int argc;
   char *args[MAXARGS];
   int val;

   char a[100];
   getcwd(a, path);
   strcpy(gamepath, a);
   strcat(gamepath, "/Commands/");
   printf("%s\n", gamepath);

   red();
   printf("\n");
   printf("\n");
   printf("Welcome! If you are new to the game, here are some tips:\n");
   printf("Look at your surroundings with the command 'ls'.\n");
   printf("Move to a new location with the command 'cd LOCATION'\n");
   printf("You can backtrack with the command 'cd ..'.\n");
   printf("Interact with things in the world with the command 'less ITEM' \n");
   printf("\n");
   printf("If you forget where you are, type 'pwd'\n");
   printf("\n");
   printf("Go ahead, explore. We hope you enjoy what you find. Do ls as your first command.\n");
   printf("\n");
   printf("To Start the game please ENTER Game folder\n");
   printf("\n");
   printf("\n");
   printf("\033[0m");

   while (1) {
	  char p[path+1];
      getcwd(p, path);
      green();
      printf("You are located in: %s\n", p);
      write(0,Prompt, strlen(Prompt));
      printf("\033[0m");
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         execute(argc, args);
      }
      if(strcmp(args[0], "cd") != 0){
        mkfifo("pipe", 0666);
        val = open("pipe", O_WRONLY);
        write(val, args[0], sizeof(args[0]));
      } 
      if (eof) exit(0);
   }
}


//
