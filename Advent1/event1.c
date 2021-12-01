// Stephen Terrio
// Advent of Code - Day 1

// PACKAGES -
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAIN -
int main(){
  FILE *file = fopen("report.txt", "r");
  if (file == NULL){
    printf("No such file: report.txt could not be read.");
    return 1;
  }
  // reading from file, supporting 50 000 inputs
  int depth[50000];
  char input[5000];
  int count = 0;
  // Looping till no more inputs
  while(fgets(input, sizeof(input), file)){
    // using strdup so value is not overritten by fgets
    depth[count] = atoi(strdup(input));
    count+= 1;
    }
  // done reading from file
  fclose(file);
  int current = depth[0];
  int increments = 0;
  printf("%d (N/A - no previous measurement)\n", current);
  for(int i = 1; i < count; i ++){
    if(depth[i] > current){
      printf("%d (increased)\n", current);
      increments++;
    }
    if(depth[i] < current){
      printf("%d (decreased)\n", current);
    }
    current = depth[i];
  }
  printf("Total increment measurements: %d\n", increments);
}
