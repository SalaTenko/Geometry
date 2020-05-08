#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROW_SIZE 100
#define M_PI 3.14159265358979323846

//Вывод информации
void Output(float coordsX[], float coordsY[], float rad[], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%d circle(%.1f %.1f, %.1f) \n",
               i + 1,
               coordsX[i],
               coordsY[i],
               rad[i]);
        printf("    perimeter = %f\n", 2 * M_PI * rad[i]);
        printf("    area = %f\n", M_PI * rad[i] * rad[i]);
        printf("    intersects: \n");
        for (int j = 0; j < count; j++) {
            if (i != j) {
                if (rad[i] + rad[j]
                    >= sqrt((coordsX[i] - coordsX[j])
                                    * (coordsX[i] - coordsX[j])
                            + (coordsY[i] - coordsY[j])
                                    * (coordsY[i] - coordsY[j]))) {
                    printf("    %d. circle \n", j + 1);
                }
            }
        }
        printf("\n");
    }
}

int main()
{
    int i = 0, j = 0, k = 0, count = 0, b = 0, f = 0;
    char *p, *g, *p1, *coords, *coord;
    char a[ROW_SIZE], symForBreaking[] = "()";
    FILE* input;

    // Считаем кол-во строк в файле
    input = fopen("input.txt", "r");
    p1 = fgets(a, ROW_SIZE, input);

    while (p1 != NULL) {
        count++;
        p1 = fgets(a, ROW_SIZE, input);
    }
    fclose(input);

    char *coords1[count], *rad1[count];
    float coordsX[count], coordsY[count], rad[count];

    for (i = 0; i < count; i++)
        coords1[i] = (char*)malloc(count * sizeof(char));

    for (i = 0; i < count; i++)
        rad1[i] = (char*)malloc(count * sizeof(char));

    //Проверка входных данных
    //Первый кусок проверки (ФОРМАТ)
    input = fopen("input.txt", "r");
    p1 = fgets(a, ROW_SIZE, input);

    int q = 0, t = 0, spase = 0, comma = 0, bracket_1 = 0, bracket_2 = 0;
    while (p1 != NULL) {
        q++;
        while (a[t] != '\0') {
            t++;
        }
        for (i = 0; i <= t; i++) {
            if (a[i] == ' ') {
                spase++;
            }
            if (a[i] == ',') {
                comma++;
            }
            if (a[i] == '(') {
                bracket_1++;
            }
            if (a[i] == ')') {
                bracket_2++;
            }
        }

        if ((strncmp(a, "circle(", 7) != 0) || (spase != 2) || (comma != 1)
            || (bracket_1 != 1) || (bracket_2 != 1)) {
            printf("Error: Invalid input format: %d circle\n", q);
            f = 1;
            puts(a);
        }

        p1 = fgets(a, ROW_SIZE, input);
        spase = 0;
        comma = 0;
        bracket_1 = 0;
        bracket_2 = 0;
        t = 0;
    }
    fclose(input);
    q = 0;
    k = 0;
    j = 0;
    b = 0;
    i = 0;

    //Второй кусок проверки (РАДИУС)
    if (f == 0) {
        input = fopen("input.txt", "r");
        p1 = fgets(a, ROW_SIZE, input);

        while (p1 != NULL) {
            a[strlen(a) - 1] = '\0';
            g = strnset(a, 40, 6);
            p = strtok(g, symForBreaking);
            coords = strtok(p, ",");

            while (coords != NULL) {
                if (k == 1) {
                    strcpy(rad1[j], coords);
                    if (atof(rad1[j]) < 0) {
                        b = 1;
                        f = 1;
                    }
                    j++;
                    k = 0;
                } else {
                    strcpy(coords1[i], coords);
                    i++;
                    k = 1;
                }

                coords = strtok(NULL, ",");
            }
            q++;
            if (b == 1) {
                printf("Error: Invalid radius value: %d circle\n", q);
            }
            b = 0;
            p1 = fgets(g, ROW_SIZE, input);
        }

        fclose(input);
    }

    //Подготовка данных
    for (i = 0; i < count; i++) {
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

    for (i = 0; i < count; i++) {
        rad[i] = atof(rad1[i]);
    }

    //Вызов функции вывода информации
    if (f == 0) {
        Output(coordsX, coordsY, rad, count);
    } else {
        printf("\n");
        printf("Please correct the input data errors!!!\n");
        printf("Tip: Use error information\n");
    }

    return 0;
}
