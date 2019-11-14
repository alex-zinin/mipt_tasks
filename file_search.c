#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>




int print_dir(int argc, char* argv)
{


  //    /home/alex..
    DIR* dir = opendir(argv);
    struct stat * buf;
    int errno = 0;
  struct dirent * ent;
    while ((ent = readdir(dir))) {

      printf("%s\n", ent->d_name);
    //  printf("%d %s", stat(ent->d_name, buf), buf->st_ino);
     /* сбросить errno, поскольку puts() может модифицировать ее */

     errno = 0;

    }

}


int search_file(char* name, char * direct)
{
  printf("\n");
//  print_dir(1, direct);
  printf("%s\n", direct);
    struct stat buf;
    struct dirent * ent;
    DIR* dir = opendir(direct);
    while ((ent = readdir(dir))) {

      if(strcmp(ent->d_name, name) == 0)
         return 1;
       stat(ent->d_name, &buf);
       if(S_ISDIR(buf.st_mode))
        {
          printf("trrrr%s\n", ent->d_name);
          if(search_file(name, ent->d_name) == 1)
            return 1;
        }
       /* сбросить errno, поскольку puts() может модифицировать ее */

      // errno = 0;

      }
      return 0;

}


int main(int argc, char** argv)
{
//    /home/alex..
  DIR* dir = opendir(argv[1]);
  struct stat * buf;
  int errno = 0;
  struct dirent * ent;

if(search_file("pp", argv[1]) == 1)
printf("Found\n");
else
printf("Not Found\n");
  //printf("%d", search_file("filellq", argv[1]));
   /* сбросить errno, поскольку puts() может модифицировать ее */




}
