#include <stdio.h>
#include <string.h>

int check_data_strokes(char *name) {
  FILE *input;
  char *p;
  char a[100], str[10] = "circle(";
  int i, flag, countSpaces, countCommas;
  flag = 0;
  countSpaces = 0;
  countCommas = 0;

  input = fopen(name, "r");
  p = fgets(a, 100, input);

  while (p != NULL) {
    if (strncmp(str, p, 7) != 0) {
      printf("Error: unknow figure \'");

      for (i = 0; p[i]; i++) {
        if (p[i] == '(')
          break;

        printf("%c", p[i]);
      }
      printf("\'\n");
      flag = 1;
    }

    for (i = 0; p[i]; i++) {
      if (p[i] == ' ')
        countSpaces++;
      if (p[i] == ',')
        countCommas++;
    }

    if (countSpaces != 2 || countCommas != 1) {
      printf("Error: invalid input format %s", p);
      flag = 1;
    }
    countSpaces = 0;
    countCommas = 0;

    p = fgets(a, 100, input);
  }
  fclose(input);
  return flag;
}
