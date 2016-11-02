#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  DIR *dir;
  struct dirent *directory;
  struct stat stats;
  int size = 0;
  char dirs[1000] = "Directories:\n";
  char files[1000] = "Regular files:\n";
  dir = opendir(".");
  while ((directory = readdir(dir)) != NULL) {
    if (directory->d_type) {
      strcat(files, "\t");
      strcat(files, directory->d_name);
      stat(directory->d_name, &stats);
      size += stats.st_size;
      strcat(files, "\n");
    }
    else {
      strcat(dirs, "\t");
      strcat(dirs, directory->d_name);
      strcat(dirs, "\n");
    }
    }
  printf("Statistics for directory: .\n");
  printf("Total Directory Size: %d Bytes\n", size);
  printf("%s", dirs);
  printf("%s", files);
  closedir(dir);
  return 0;
}
    
