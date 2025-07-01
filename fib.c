#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

uint64_t fib(int n, int i, bool init) {
  static int calls = 0;
  static int calls_b = 0;
  static uint64_t context;

  if (init) {
    context = 0;
  } else {
    context++;
  }
  calls++;

  if (calls % 1000000000 == 0) {
    calls = 0;
    calls_b++;
    printf("-- %d -- Number of fib function calls: %d Billion, current "
           "context: %llu\n",
           i, calls_b, context + 1);
  }

  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;

  return fib(n - 1, i, 0) + fib(n - 2, i, 0);
}

__uint128_t fast_fib(uint64_t n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  __uint128_t a = 0;
  __uint128_t b = 1;
  __uint128_t c = 1;

  __uint128_t tempc;

  for (int i = 3; i <= n; i++) {
    tempc = c;
    c = c + b;
    a = b;
    b = tempc;
  }

  return c;
}

void print_uint128(__uint128_t value) {
  if (value == 0) {
    printf("0");
    return;
  }

  char buffer[40];
  int pos = 39;
  buffer[pos] = '\0';

  while (value > 0) {
    buffer[--pos] = '0' + (value % 10);
    value /= 10;
  }

  printf("%s", &buffer[pos]);
}

int main(int argc, char *argv[]) {
  int x = 10;
  __uint128_t y;
  bool f = 1;
  char *rec = "-r";
  char *noloop = "-nl";
  char *help = "-h";
  int i = 0;

  if (argc > 4)
    return 1;

  if (argc == 2) {
    x = atoi(argv[1]);

    if (strcmp(argv[1], help) == 0) {
      printf("Pass the num first, pass -f or -r for fast or recursive and then "
             "pass -nl if you only want one loop\n if you only pass the num it "
             "does fast else you must pass evrything in the order specified");
      return 1;
    }
  }
  if (argc == 3) {
    x = atoi(argv[1]);
    if (strcmp(argv[2], rec) == 0)
      f = 0;
  }

  if (argc == 4) {
    x = atoi(argv[1]);
    if (strcmp(argv[2], rec) == 0)
      f = 0;
    if (strcmp(argv[3], noloop) == 0)
      i = x;
  }

  if (x > 185) {
    puts("we are brushing against the limitations of 128 bit unsigned integers "
         "output erronious");
    i = x;
  }

  if (f) {
    printf("using fast fib\n");
    for (; i <= x; i++) {
      clock_t start_f = clock();
      y = fast_fib(i);
      clock_t stop_f = clock();
      if (y < 0) {
        puts("integer overflow");
        return 1;
      }
      printf("-- %2d -- Computed at: ", i);
      print_uint128(y);
      printf(", in %lf seconds", (double)(stop_f - start_f) / CLOCKS_PER_SEC);
      puts("");
    }
  } else {
    printf("using oh so slow fib(recusrive)\n");
    for (; i <= x; i++) {
      clock_t start_r = clock();
      y = fib(i, i, 1);
      clock_t stop_r = clock();
      if (y < 0) {
        puts("integer overflow");
        return 1;
      }
      printf("-- %2d -- Computed at: %" PRIu64 ", in %lf seconds\n", i, y,
             (double)(stop_r - start_r) / CLOCKS_PER_SEC);
    }
  }

  return 0;
}
