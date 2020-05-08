#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
