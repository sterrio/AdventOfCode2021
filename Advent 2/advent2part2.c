// Stephen Terrio
// Advent of Code - Day 2

// PACKAGES -
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  FILE *file = fopen("inputs.txt", "r");
  if (file == NULL){
    printf("No such file: inputs.txt could not be read.");
    return 1;
  }
  int hPos = 0;
  int depth = 0;
  char input[20];
  int aim = 0;

  // reading and comparing commands from file -
  while(fgets(input, sizeof(input), file)){
    int pos = 0;
    char* command = NULL;
    char *split = strtok(input, " ");

    while(split != NULL){
      if(command == NULL){
        command = split;
        continue;
      }
      if(pos == 0){
        split = strtok(NULL, " ");
        char temp = split[0];
        pos = atoi(&temp);
        break;
      }
    }
    if(!strcmp(command, "forward")){
      hPos = pos + hPos;
      depth += aim * pos;
    }
    if(!strcmp(command, "down")){
      //depth = depth + pos;
      aim += pos;
    }
    if(!strcmp(command, "up")){
      //depth = depth - pos;
      aim -= pos;
    }
  }
  fclose(file);
  printf("Final Horizontal Movement: %d\n", hPos);
  printf("Final Depth: %d\n", depth);
  int mult = hPos * depth;
  printf("Final Multiplication: %d\n", mult);
}
