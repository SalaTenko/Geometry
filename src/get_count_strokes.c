#include <stdio.h>
int get_count_strokes(char *name) {
  FILE *input;
  char *p;
  char a[100];
  int count;
  count = 0;

  input = fopen(name, "r");
  p = fgets(a, 100, input);

  while (p != NULL) {
    count++;
    p = fgets(a, 100, input);
  }
  fclose(input);
  return count;
}
