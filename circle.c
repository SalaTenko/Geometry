#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define Pi 3.14

typedef struct {
    float R;
    int x;
    int y;

} Circle;

void Output_circle(Circle* qwerty_1)
{
    int i = 1;
    printf("%d. Окружность: ", i);
    printf("(%d %d, %.1f)\n", qwerty_1->x, qwerty_1->y, qwerty_1->R);
    i++;
}

void Input_circle(Circle* qwerty, int n)
{
    int err;
    for (int i = 0; i < n; i++) {
        printf("Введите координаты центра X и Y: \n");
        err = scanf("%d %d", &qwerty->x, &qwerty->y);
        if (err != 2) {
            printf("Введено неверно...\n");
            exit(0);
        }
        printf("Введите радиус: \n");
        err = scanf("%f", &qwerty->R);
        if ((err != 1) || (qwerty->R <= 0)) {
            printf("Введено неверно...\n");
            exit(0);
        } else {
            Output_circle(qwerty);
        }
    }
}

int main()
{
    int n, err;
    printf("Введите количество кругов: \n");
    err = scanf("%d", &n);
    if (err != 1) {
        printf("Введено неверно...\n");
        exit(0);
    }

    Circle first;
    Input_circle(&first, n);

    return 0;
}
