#include "parser.h"
#include "validation.h"
#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024
#define BUFFER_SIZE 4096

/*
@param key{
  int byr;  // birth year
  char ecl[5];  // Eye color
  int iyr;  // issue year
  int eyr;  // Expiration year
  char hgt[10]; // height
  char hcl[10]; // hair color
  long int pid; // passport ID
  int cid;  // country ID
};
*/

void VALID_PASSPORT_COUNTER(FILE *file) {
  char line[LINE_SIZE];
  char buffer[BUFFER_SIZE] = "";
  PASSPORT passport;
  int valid_count = 0;

  while (fgets(line, sizeof(line), file)) {
    if (line[0] == '\n') {
      PASSPORT_PARSER(buffer, &passport);
      if (is_valid_byr(passport.byr) && is_valid_iyr(passport.iyr) &&
          is_valid_eyr(passport.eyr) && is_valid_hgt(passport.hgt) &&
          is_valid_hcl(passport.hcl) && is_valid_ecl(passport.ecl) &&
          is_valid_pid(passport.pid)) {
        valid_count++;
      }
      memset(&passport, 0, sizeof(PASSPORT));
      buffer[0] = '\0';
    } else {
      strcat(buffer, line);
    }
  }

  if (buffer[0] != '\0') {
    PASSPORT_PARSER(buffer, &passport);
    if (is_valid_byr(passport.byr) && is_valid_iyr(passport.iyr) &&
        is_valid_eyr(passport.eyr) && is_valid_hgt(passport.hgt) &&
        is_valid_hcl(passport.hcl) && is_valid_ecl(passport.ecl) &&
        is_valid_pid(passport.pid)) {
      valid_count++;
    }
  }

  printf("Valid passports: %d\n", valid_count);
}

void INPUT_FILE(char *c) {
  printf("Input file: %s\n", c);
  FILE *fp = fopen(c, "r");
  if (fp == NULL) {
    perror("Input file error");
    return;
  }

  VALID_PASSPORT_COUNTER(fp);
  fclose(fp);
}

int main() {
  /*INPUT_FILE("sample.txt");*/
  INPUT_FILE("input.txt");
}
