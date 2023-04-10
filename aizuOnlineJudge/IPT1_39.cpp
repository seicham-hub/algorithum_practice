// Triangle
// 0319もう一度

#include <iostream>
#include <stdio.h>
#define USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main()
{

    double a, b, C, S, L, h;

    cin >> a >> b >> C;

    S = (0.5) * a * b * sin(C / 180 * M_PI);
    L = sqrt(a * a + b * b - 2 * a * b * cos(C / 180 * M_PI)) + a + b;
    h = S * 2 / a;
    printf("%.5f\n%.5f\n%.5f\n", S, L, h);

    return 0;
}
