// myShell3
//////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "history_table.h"

/* compiliing:
gcc myShell3.c history_table.c -o myShell3 
 */

#define error(a) {perror(a); exit(1);};
#define MAXLINE 200
#define MAXARGS 20

/////////// reading commands:

int read_args(int* argcp, char* args[], int max, int* eofp){
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

int main ()
{
   int eof = 0;
   int argc;
   char *args[MAXARGS];
   int pid;

   /***** Create pipe *****/
   int pfd[2];
   if ( pipe(pfd) == -1 ) error("pipe");

   /***** Launch myShell1 with input redirection *****/
   switch ( pid = fork() ){
   		
   		case -1: error("fork"); break;
   		
   		case 0: /* myShell1 child*/
   			
   			if ( close(0) == -1 ) error("close");
   			if ( dup(pfd[0]) != 0 ) error("dup");
   			if ( (close(pfd[0]) == -1) || close(pfd[1]) == -1 ) error("close");

   			execlp("./myShell1", "./myShell1", (char *)NULL);
   			error("execlp");
   }

   while (1) {

      	if (read_args(&argc, args, MAXARGS, &eof) && argc > 0) {

         	if ( strncmp(args[0], "!", 1) == 0 ){

         		char * command = args[0];
         		command++;
         		
         		/***** find command in history *****/
         		char *input = search_command (command);

         		/***** write command in pipe *****/
         		write(pfd[1], input, strlen(input));
         		write(pfd[1], "\n", strlen("\n") );


         	}else if ( strcmp(args[0], "exit") == 0 ){

         		/***** finih both processed *****/
         		kill(pid, SIGTERM);
         		exit(0);

         	}else if ( strcmp(args[0], "hist") == 0 ){
         		
         		/***** write history *****/
         		print_list();

         		write(1, "myShell>", strlen("myShell>"));

         	
         	}else{
         		
         		/***** write command in pipe *****/
         		char com[MAXARGS]="";
         		
         		for (int i = 0; i < argc; ++i){
         		 	write( pfd[1], args[i], strlen(args[i]) );
         		 	write( pfd[1], " ", strlen(" ") );
         		 	strcat(com, args[i]);
         		 	strcat(com, " ");
         		}
         		write( pfd[1], "\n", strlen("\n") );
         		insert_command (com);
         		
         	}
      	}
   }
}
