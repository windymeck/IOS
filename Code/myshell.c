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

#include "defines.h"

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 250
#define path 20000

static char gamepath[5000]; 


////// reading commands: //////


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

int cd(int argc, char**argv){
  char od[path+1];
  char new[path+1];
  int res = 0;

  //getcwd(od, path);
  //printf("pwd: %s\n", od);
  //printf("cd: %s\n", argv[1]);
  res = chdir(argv[1]);
  //getcwd(new, path);

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
  return res;
}


int execute(int argc, char *argv[])
{
  int id;
  char a[10000];
  int val;
  /**/
  



  if (strcmp(argv[0], "cd") == 0){
    cd(argc, argv);
 /* }else if(strcmp(argv[0], "ls") == 0){
    ls(argc, argv);
  */}else if(strcmp(argv[0], "exit") == 0){
      val = open("pipe", O_WRONLY);
      write(val, argv[0], sizeof(argv[0]));
      printf("bye!!\n");
      exit(0);
  }else{

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
   int valp;
   int valarg;

   char a[100];
   getcwd(a, path);
   strcpy(gamepath, a);
   strcat(gamepath, "/Commands/"); 

    int fd1, fd2, ni, n;
    struct t_request Request; 
    struct t_answer Answer;

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
    char pp[path+1];
    char arggg[100];
    char ans[500];
      getcwd(p, path);
      strcpy(pp, p);
      green();
      printf("You are located in: %s\n", p);
      write(0,Prompt, strlen(Prompt));
      printf("\033[0m");
      if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {
         execute(argc, args);
         if(strcmp(args[0], "ls") != 0){

            printf("+-----------------------------------------------------------------------------------------------------+\n");
            if ((fd1= open(FIFO_SHELL_SERVER, O_RDWR)) < 0) 
              error("Client: open FIFO Server");

            ni= getpid();
   
            sprintf(Request.answerBox, "/tmp/MAILBOX_clnt%06d", ni);
  
            unlink(Request.answerBox);
            if (mkfifo(Request.answerBox, 0660) < 0) 
              error("Client: mkfifo");
            chmod(Request.answerBox, 0660);

            if ((fd2= open(Request.answerBox, O_RDWR)) < 0) 
              error("Client: opening client box");
           //write(val, args[0], sizeof(args[0]));
           //write(valp, pp, sizeof(pp));
           //write(valarg, args[1], sizeof(args[1]));
              strcpy(Request.command, args[0]);
              strcpy(Request.location, pp);
              strcpy(Request.argument, args[1]);

            // Send petition message to the SERVER
            if ((n= write(fd1, &Request, sizeof(struct t_request))) < 0) 
              error("Client: write server box");
  
            // Wait answer from SERVER
            if ((n= read(fd2, &Answer, sizeof(struct t_answer))) <= 0) 
              error("Client: read answer box");
      
            printf("[1]Server's ack: %s\n", Answer.message);
  
            close(fd1);
            close(fd2);
   
            unlink(Request.answerBox);
            printf("[2]Answer box %s deleted\n", Request.answerBox);
            printf("+-----------------------------------------------------------------------------------------------------+\n");
         }
      }
         
      if (eof) exit(0);
   }
}


//
