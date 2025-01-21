#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 100
#define MAX_DATA_SIZE 1000
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
typedef struct {
  char key[6];
  char value[20];
} KEY_VALUE;

typedef struct {
  KEY_VALUE data_member[MAX_DATA_SIZE];
  int data_counter;
} SINGLE_PASSPORT;

/*
 * NOT NEEDED
 *
 *
bool is_valid_data(SINGLE_PASSPORT *data) {
  int required_key = 0;
  bool has_cid = false;

  for (int i = 0; i < data->data_counter; i++) {
    if (strcmp(data->data_member[i].key, "byr") == 0 ||
        strcmp(data->data_member[i].key, "ecl") == 0 ||
        strcmp(data->data_member[i].key, "iyr") == 0 ||
        strcmp(data->data_member[i].key, "eyr") == 0 ||
        strcmp(data->data_member[i].key, "hgt") == 0 ||
        strcmp(data->data_member[i].key, "hcl") == 0 ||
        strcmp(data->data_member[i].key, "pid") == 0) {
      required_key++;
    } else if (strcmp(data->data_member[i].key, "cid") == 0) {
      has_cid = true;
      required_key++;
    }
  }
  return required_key == 8 || (required_key == 7 && has_cid);
}
*
*
*/

void PARSER(FILE *fp) {
  char line[MAX_LINE_SIZE];
  SINGLE_PASSPORT passports[MAX_DATA_SIZE];
  int PASSPORT_COUNT = 0;
  int required_key = 0;
  bool has_cid = false;
  int valid_passport_count = 0;

  // read file line by line *fgets(char *str, int n, FILE *stream);
  while (fgets(line, sizeof(line), fp)) {

    // Remove trailing newline
    line[strcspn(line, "\n")] = '\0'; // README.MD

    // check if blank line
    if (strlen(line) == 0) {
      PASSPORT_COUNT++;
      passports[PASSPORT_COUNT].data_counter = 0;
    }

    else {
      /*
       * There is great alternative to it
       * which i dont know ;(
       *
       *
       * You can use token realted function
       * I guess
       */
      char key[5], value[20];
      int i = 0, j = 0;

      // @{ EXTRACTING_THE_KEYS }
      while (line[i] == '\0') {
        while (line[i] != ':' && line[i] != '\0') {
          key[j++] = line[i++];
        }
        key[j] = '\0';
        i++; // skipping colon
        j = 0;

        // @{ EXTRACTING_THE_VALUE}
        while (line[i] != ' ' && line[i] != '\0') {
          value[j++] = line[i++];
        }
        value[j] = '\0';
        j = 0;

        if (strcmp(key, "byr") == 0 || strcmp(key, "ecl") == 0 ||
            strcmp(key, "iyr") == 0 || strcmp(key, "eyr") == 0 ||
            strcmp(key, "hgt") == 0 || strcmp(key, "hcl") == 0 ||
            strcmp(key, "pid") == 0) {
          required_key++;
        } else if (strcmp(key, "cid") == 0) {
          has_cid = true;
          required_key++;
        }
      }
    }
  }
  if (required_key == 8 || (required_key == 7 && has_cid)) {
    valid_passport_count++;
  }

  printf("Total valid passports: %d\n", valid_passport_count);
}

void INPUT_FILE(char *c) {
  printf("Input file: %s\n", c);
  FILE *fp = fopen(c, "r");
  if (fp == NULL) {
    perror("Input file error");
  }

  PARSER(fp);
  fclose(fp);
}

int main() {
  INPUT_FILE("sample.txt");
  /*INPUT_FILE("input.txt");*/
}
