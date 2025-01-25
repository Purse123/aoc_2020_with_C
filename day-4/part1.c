#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 256
#define REQUIRED_KEYS 7
#define MAX_KEYS 8

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

int count_required_keys(char *line) {
  int required_key = 0;
  char *key = strtok(line, " ");
  while (key != NULL) {
    if (strncmp(key, "byr", 3) == 0 || strncmp(key, "iyr", 3) == 0 || 
        strncmp(key, "eyr", 3) == 0 || strncmp(key, "hgt", 3) == 0 || 
        strncmp(key, "hcl", 3) == 0 || strncmp(key, "ecl", 3) == 0 || 
        strncmp(key, "pid", 3) == 0) {
      required_key++;
    }
    key = strtok(NULL, " ");
  }
  return required_key;
}

void PARSER(FILE *fp) {
  char line[MAX_LINE_SIZE];
  int required_key = 0;
  int valid_passport_count = 0;
  bool has_cid = false;

  while (fgets(line, sizeof(line), fp)) {
    line[strcspn(line, "\n")] = '\0';

    if (strlen(line) == 0) {
      if (required_key == REQUIRED_KEYS) {
        valid_passport_count++;
      }
      required_key = 0;
      has_cid = false;
    } else {
      required_key += count_required_keys(line);

      if (strstr(line, "cid:") != NULL) {
        has_cid = true;
      }
    }
  }

  if (required_key == REQUIRED_KEYS) {
    valid_passport_count++;
  }

  printf("Total valid passports: %d\n", valid_passport_count);
}

void INPUT_FILE(char *c) {
  FILE *fp = fopen(c, "r");
  if (fp == NULL) {
    perror("Input file error");
    exit(EXIT_FAILURE);
  }

  PARSER(fp);
  fclose(fp);
}

int main() {
  /*INPUT_FILE("sample.txt");*/
  INPUT_FILE("input.txt");
}
