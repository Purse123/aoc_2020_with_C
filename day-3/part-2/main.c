#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 350

int NO_OF_TREE = 0, NO_OF_LINE = 0;
char EACH_LINE[MAX_LENGTH][50];
int total = 1;

int slope[5][2] = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};

int CHECK_TREE(int dx, int dy) {
  int result = 0;
  int x = 0, y = 0;
  while (y < NO_OF_LINE) {
    if (EACH_LINE[y][x] == '#') {
      result++;
    }
    y += dy;
    x = (x + dx) % strlen(EACH_LINE[0]);
  }
  return result;
}

void INPUT_FILE(char *c) {
  char s1[50];

  printf("Input file: %s\n", c);
  FILE *fp = fopen(c, "r");
  if (fp == NULL) {
    perror("File unable to open");
  }

  while (fscanf(fp, "%s", s1) == 1) {
    strcpy(EACH_LINE[NO_OF_LINE], s1);
    NO_OF_LINE++;
  }

  for (int i = 0; i < 5; i++) {
    total *= CHECK_TREE(slope[i][0], slope[i][1]);
  }

  fclose(fp);
}

int main() {
  /*INPUT_FILE("sample.txt");*/
  INPUT_FILE("input.txt");
  printf("no of line: %d\n", NO_OF_LINE);
  
  printf("total: %d\n", total);
}
