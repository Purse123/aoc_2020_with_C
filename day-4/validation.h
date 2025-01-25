#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>

#define MAX_FIELD_SIZE 20

typedef struct {
  int measure;
  char unit[3];
} HEIGHT;

typedef struct {
  int byr, iyr, eyr;
  HEIGHT hgt;
  char hcl[MAX_FIELD_SIZE];
  char ecl[MAX_FIELD_SIZE];
  char pid[MAX_FIELD_SIZE];
  char cid[MAX_FIELD_SIZE];
} PASSPORT;

bool is_valid_byr(int byr);
bool is_valid_iyr(int iyr);
bool is_valid_eyr(int eyr);
bool is_valid_hgt(HEIGHT hgt);
bool is_valid_hcl(char *hcl);
bool is_valid_ecl(char *ecl);
bool is_valid_pid(char *pid);

#endif
