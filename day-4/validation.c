#include "validation.h"
#include <ctype.h>
#include <string.h>

bool is_valid_byr(int byr) { return byr >= 1920 && byr <= 2002; }

bool is_valid_iyr(int iyr) { return iyr >= 2010 && iyr <= 2020; }

bool is_valid_eyr(int eyr) { return eyr >= 2020 && eyr <= 2030; }

bool is_valid_hgt(HEIGHT hgt) {
  if (strcmp(hgt.unit, "cm") == 0) {
    return hgt.measure >= 150 && hgt.measure <= 193;
  } else if (strcmp(hgt.unit, "in") == 0) {
    return hgt.measure >= 59 && hgt.measure <= 76;
  }
  return false;
}

bool is_valid_hcl(char *hcl) {
  if (hcl[0] != '#' || strlen(hcl) != 7)
    return false;
  for (int i = 1; i < 7; i++) {
    if (!((hcl[i] >= '0' && hcl[i] <= '9') ||
          (hcl[i] >= 'a' && hcl[i] <= 'f'))) {
      return false;
    }
  }
  return true;
}

bool is_valid_ecl(char *ecl) {
  const char *valid_colors[] = {"amb", "blu", "brn", "gry",
                                "grn", "hzl", "oth"};
  for (int i = 0; i < 7; i++) {
    if (strcmp(ecl, valid_colors[i]) == 0)
      return true;
  }
  return false;
}

bool is_valid_pid(char *pid) {
  if (strlen(pid) != 9)
    return false;
  for (int i = 0; i < 9; i++) {
    if (!isdigit(pid[i]))
      return false;
  }
  return true;
}
