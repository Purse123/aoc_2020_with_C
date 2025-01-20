#include <stdio.h>
#include <string.h>

int NO_OF_TREE = 0, NO_OF_LINE = 0;

void CHECK_TREE(char string[50], int x_pos) {
  if (string[x_pos % strlen(string)] == '#') {
    NO_OF_TREE++;
  }
}

void INPUT_FILE(char *c) {
  char s1[50];
  int x = 0;

  printf("Input file: %s\n", c);
  FILE *fp = fopen(c, "r");
  if (fp == NULL) {
    perror("File unable to open");
  }

  while (fscanf(fp, "%s", s1) == 1) {
    CHECK_TREE(s1, x);
    x += 3;
    NO_OF_LINE++;
  }
}

int main() {
  /*INPUT_FILE("sample.txt");*/
  INPUT_FILE("input.txt");
  printf("no of line: %d\n", NO_OF_LINE);
  printf("no of tree: %d\n", NO_OF_TREE);
}
