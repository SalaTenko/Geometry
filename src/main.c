#include "check_data_strokes.h"
#include "get_count_strokes.h"
#include "get_data.h"
#include "print_rezult.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int countStr;
    char fileName[] = "input.txt";

    if (check_data_strokes(fileName) == 0) {
        countStr = get_count_strokes(fileName);
        float coordsX[countStr], coordsY[countStr], rad[countStr];

        get_data(fileName, countStr, coordsX, coordsY, rad);
        print_rezult(countStr, coordsX, coordsY, rad);
    }

    return 0;
}
