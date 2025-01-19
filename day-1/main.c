#include <stdio.h>
#define MAX_SIZE 220

int input_value[MAX_SIZE];
int count = 0;

void opening_file(char *file_path) {
  int x;
  printf("Input source file: %s\n", file_path);

  FILE *f = fopen(file_path, "r");
  if (f == NULL) {
    perror("Error opening file\n");
    return;
  }

  while (fscanf(f, "%d", &x) == 1) {
    if (count < MAX_SIZE) {
      input_value[count++] = x;
    } else {
      printf("Array size limit exceeded.\n");
      break;
    }
  }
  fclose(f);
  printf("Number of element: %d\n", count);
}

void find_num() {
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      for (int k = 0; k < count; k++) {
        if ((input_value[i] + input_value[j] + input_value[k]) == 2020) {
          printf("%d\n", input_value[i]* input_value[j]*
                 input_value[k]);
          return;
        }
      }
    }
  }
}
int main() {
  opening_file("sample.txt");
  find_num();
}
