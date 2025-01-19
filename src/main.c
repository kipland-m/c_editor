#include <stdio.h>
#include <string.h>

void edit_line(char* buffer, int current_line){
  int i;
  for (i = 0; i < current_line; i++){
    buffer = strchr(buffer, '\n') + 1;
  }

  char* line_end = strchr(buffer, '\n');
  char saved[1024] = {0};

  strcpy(saved, line_end);
  scanf("%s", buffer);
  strcpy(buffer + strlen(buffer), saved);
}

int main(int argc, char** argv){
  char buffer[1024] = {0};
  FILE* f = fopen(argv[1], "r");

  fread(buffer, 1024, 1, f);
  fclose(f);

  printf("Contents:\n%s\n", buffer);

  int current_line = 0;
  scanf("%d", &current_line);
  edit_line(buffer, current_line);

  f = fopen(argv[1], "w");
  fwrite(buffer, strlen(buffer), 1, f);
  fclose(f);

  return 0;
}

