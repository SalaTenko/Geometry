#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
const float PI = 3.14;

void get_data(char *name, int countStr, float coordsX[], float coordsY[],
              float rad[]) {
  FILE *input;
  char *p1, *p, *g, *coords, *coord;
  char coords1[countStr][20], rad1[countStr][20];
  char symForBraeking[] = "()";
  int i, sizeStr, leftBracketCode, k, j;
  sizeStr = 100;
  leftBracketCode = 40;

  char a[sizeStr];

  input = fopen(name, "r");
  p = fgets(a, sizeStr, input);
  i = 0;
  j = 0;
  k = 0;

  while (p1 != NULL) {
    a[strlen(a) - 1] = '\0';
    g = strnset(a, leftBracketCode, 6);
    p = strtok(g, symForBraeking);
    coords = strtok(p, ",");

    while (coords != NULL) {
      if (k == 1) {
        strcpy(rad1[j], coords);
        j++;
        k = 0;
      } else {
        strcpy(coords1[i], coords);
        i++;
        k = 1;
      }
      coords = strtok(NULL, ",");
    }
    p1 = fgets(g, sizeStr, input);
  }
  fclose(input);

  for (i = 0; i < countStr; i++) {
    coord = strtok(coords1[i], " ");
    k = 0;
    while (coord != NULL) {
      if (k == 0)
        coordsX[i] = atof(coord);
      else
        coordsY[i] = atof(coord);
      k++;

      coord = strtok(NULL, " ");
    }
  }

  for (i = 0; i < countStr; i++)
    rad[i] = atof(rad1[i]);
}
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
int get_sum(int a, int b) { return a + b; }
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
void print_rezult(int countStr, float coordsX[], float coordsY[], float rad[]) {
  int i, j;
  float circleDistance;

  for (i = 0; i < countStr; i++) {
    printf("%d circle(%.2f %.2f, %.2f) \n", i + 1, coordsX[i], coordsY[i],
           rad[i]);
    printf("   perimetr = %.2f\n   area = %.2f\n   intersects:\n",
           2 * PI * rad[i], PI * rad[i] * rad[i]);

    for (j = 0; j < countStr; j++) {
      if (j == i)
        continue;

      circleDistance = sqrt(pow(coordsX[i] - coordsX[j], 2) +
                            pow(coordsY[i] - coordsY[j], 2));

      if (circleDistance < rad[i] + rad[j])
        printf("    %d. circle\n", j + 1);
    }
    printf("\n");
  }
}
