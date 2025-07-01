#include <stdio.h>

int stringSize(char *str) {
  int size = 0;
  while (*str != '\0') {
    size++;
    *str++;
  }

  return size;
}

int main(int argc, char *argv[]) {

  if (argc != 2)
    return 1;

  int i = stringSize(argv[1]);
  int slash_1 = 0;

  for (; i >= 0; i--) {
    if (argv[1][i] == '/') {
      slash_1 = i;
      break;
    }
  }

  // printf("%s %d", argv[1], slash_1);

  for (int j = slash_1 + 1; j < stringSize(argv[1]); j++) {
    printf("%c", argv[1][j]);
  }

  return 0;
}
