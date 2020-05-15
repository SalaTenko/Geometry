#include "circle.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count, i, j;
    printf("Введите число окружностей\n");
    scanf("%d", &count);
    float x[count], y[count], r[count], p, s;
    int inter[count][count];
    for (i = 0; i < count; i++) {
        printf("Введите координаты центра X и Y, радиус R:\n");
        printf("X = ");
        scanf("%f", &x[i]);
        printf("Y = ");
        scanf("%f", &y[i]);
        printf("R = ");
        scanf("%f", &r[i]);
        printf("\n");
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            inter[i][j] = 0;
            if (i != j) {
                inter[i][j] = function(x[i], y[i], r[i], x[j], y[j], r[j]);
            }
        }
    }
    for (i = 0; i < count; i++) {
        circle(x[i], y[i], r[i], &p, &s);
        printf("%d. Окружность(%.2f %.2f, %.2f)\n", i + 1, x[i], y[i], r[i]);
        printf("    Перимтер = %.3f \n", p);
        printf("    Площадь = %.3f \n", s);
        printf("    Пересечение:\n");
        for (j = 0; j < count; j++) {
            if (inter[i][j] == 1) {
                printf("     %d. Окружность\n", j + 1);
            }
        }
    }
}
