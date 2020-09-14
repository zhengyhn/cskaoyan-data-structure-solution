#include <stdio.h>

struct {
  int a;
  char b;
  short c;
} record;

int main() {
  printf("%p\n", &record);
  printf("%p\n", &record.c);
  float f = -8.25;
  for (int i = 3; i >= 0; --i) {
    char c = *((char *)(&f) + i);
    for (int i = 7; i >= 0; --i) {
      printf("%d ", (c >> i) & 1);
      if (i == 4) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}