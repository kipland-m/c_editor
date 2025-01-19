#include <stdio.h>
char buffer[1024] = {0};

int main(int argc, char** argv){
  FILE* f = fopen(argv[1], "r");

  fread(buffer, 1024, 1, f);
  fclose(f);

  return 0;
}
