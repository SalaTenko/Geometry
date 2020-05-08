#include <math.h>
#include <stdio.h>
const float PI = 3.14;

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
