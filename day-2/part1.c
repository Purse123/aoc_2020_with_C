#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 200

/*int INPUT_FILE_LINE[MAX_LINE_SIZE];*/
int VALID_PASS = 0, NO_OF_PASS = 0;
int count_line = 0;

int COUNT_LETTER(char letter, char string[50]) {
  int count_letter = 0;
  for (int i = 0; i < strlen(string); i++) {
    if (letter == string[i]) {
      count_letter++;
    }
  }
  return count_letter;
}

void CHECK_POLICY(int min, int max, char letter, char password[50]) {
  int x = COUNT_LETTER(letter, password);
  if (x >= min && x <= max) {
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

  while(fscanf(fp, "%d-%d %c: %s", &x0, &x1, &c0, c1) == 4) {
    if(count_line < MAX_LINE_SIZE) {
      CHECK_POLICY(x0, x1, c0, c1);
      NO_OF_PASS++;
    }
    else {
      return;
    }
  }
}

int main() {
  INPUT_FILE("sample.txt");
  printf("Total password: %d\nValid password: %d\n", NO_OF_PASS, VALID_PASS);
}
