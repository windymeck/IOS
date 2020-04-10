#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFSIZE 2000

/*void less(FILE *fp)
{
  char buf[BUFSIZ]; //The size of the stdio.h buffer

//buf = pointer to an array
//sizeof(buf) = maximum number of characters to be reading
//fp = pointer to a file
  while(fgets(buf, sizeof(buf), fp))
    fputs(buf, stdout);
    //buf = the array containing the null-terminated sequence of characters to be written.
    //stdout = pointer to a file  pero stdout --> salida estandar
}

int main(int argc, char **argv)
{
  if(argc < 2)
    less(stdin); //stdin --> entrada estandar
  else
  {
    int i;
    FILE *fp;

    for(i = 1;argv[i];++i)
    {
      if(!(fp = fopen(argv[i], "r")))
      //stderr --> standard error
      //strerror --> returns a pointer to a string that describes the error code passed in the argument
        fprintf(stderr, "myless: %s: %s\n", argv[i], strerror(errno));
      else
      {
        less(fp);
        fclose(fp);
      }
    }
  }

  return 0;
}*/


int main(int argc, char *argv[]){
  int fd;
  int n;
  char buffer[BUFSIZE];

  fd = open(argv[1], O_RDONLY);
  if(fd != 0){
      switch(fd){
          case EACCES: perror("Permission denied");
          break;
          case EIO:  perror("An input output error occured");
          break;
          case ENOTDIR: perror("A component of path not a directory"); 
          break;
          case ENOENT: perror("No such file or directory"); printf("enoent\n");
      
          default: perror("Couldn't read the file");
      }
  }
  while((n = read(fd, buffer, BUFSIZE))>0)
    printf("%s\n", buffer);
}
