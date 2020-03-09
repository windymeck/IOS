/*#include <mcheck.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int
main (void)
{
  char *dir;
  mtrace ();
  dir = getcwd ((char *) NULL, 0);
  if (dir == NULL)
    perror ("getcwd");
  else
    {
      puts (dir);
      free (dir);
    }
  return (dir == NULL ? EXIT_FAILURE : EXIT_SUCCESS);
}*/
 
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

void red () {
	  printf("\033[1;31m");
}

int main(int argc, char *argv[])
{
	char *loc = NULL;
	char *pointer = NULL;

	pointer = getenv("PWD");
	if(argc == 1){
		loc = pointer;
		printf("You are located in %s\n", loc);
	}
		printf("\n");
}