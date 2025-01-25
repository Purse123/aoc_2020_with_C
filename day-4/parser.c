#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HEIGHT parse_height(char *height_str) {
  HEIGHT hgt;
  sscanf(height_str, "%d%s", &hgt.measure, hgt.unit);
  return hgt;
}

bool PASSPORT_PARSER(char *passport_str, PASSPORT *passport) {
  char *token = strtok(passport_str, " \n");
  while (token != NULL) {
    char key[MAX_FIELD_SIZE], value[MAX_FIELD_SIZE];
    sscanf(token, "%[^:]:%s", key, value);

    if (strcmp(key, "byr") == 0) {
      passport->byr = atoi(value);
    } else if (strcmp(key, "iyr") == 0) {
      passport->iyr = atoi(value);
    } else if (strcmp(key, "eyr") == 0) {
      passport->eyr = atoi(value);
    } else if (strcmp(key, "hgt") == 0) {
      passport->hgt = parse_height(value);
    } else if (strcmp(key, "hcl") == 0) {
      strcpy(passport->hcl, value);
    } else if (strcmp(key, "ecl") == 0) {
      strcpy(passport->ecl, value);
    } else if (strcmp(key, "pid") == 0) {
      strcpy(passport->pid, value);
    } else if (strcmp(key, "cid") == 0) {
      strcpy(passport->cid, value);
    }
    token = strtok(NULL, " \n");
  }
  return true;
}
