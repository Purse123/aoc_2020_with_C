/*Copyright (c) 2025 Purse321. All Rights Reserved.*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 200

int VALID_PASS = 0, NO_OF_PASS = 0;
int count_line = 0;

void CHECK_POLICY(int pos1, int pos2, char letter, char password[50]) {
  bool a = password[pos1 - 1] == letter;
  bool b = password[pos2 - 1] == letter;
  if ((!a || !b) && (a || b)) {
  /*if (a != b) {*/
    VALID_PASS++;
  }
}

void INPUT_FILE(char *c) {
  int x0, x1;
  char c0;
  char c1[50];
  printf("Input file: %s\n", c);
  FILE *fp;
  fp = fopen(c, "r");

  if (fp == NULL) {
    perror("Input file error");
  }

  while (fscanf(fp, "%d-%d %c: %s", &x0, &x1, &c0, c1) == 4) {
    if (count_line < MAX_LINE_SIZE) {
      CHECK_POLICY(x0, x1, c0, c1);
      NO_OF_PASS++;
    } else {
      return;
    }
  }
}

int main() {
  INPUT_FILE("sample.txt");
  printf("Total password: %d\nValid password: %d\n", NO_OF_PASS, VALID_PASS);
}
