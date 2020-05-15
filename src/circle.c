#include <math.h>
#include <stdio.h>

int function(float x1, float y1, float r1, float x2, float y2, float r2)
{
    float d, sr;
    int f = 0;
    if ((x1 == x2) && (y1 == y2)) {
        f = 1;
    } else {
        d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        sr = r1 + r2;
        if ((d <= sr) && (d >= fabs(r1 - r2))) {
            f = 1;
        } else {
            f = 0;
        }
    }
    return f;
}

float circle(float x, float y, float r, float* p, float* s)
{
    float r2;
    *p = 2 * 3.14 * r;
    r2 = pow(r, 2);
    *s = 3.14 * r2;
    return 0;
}

