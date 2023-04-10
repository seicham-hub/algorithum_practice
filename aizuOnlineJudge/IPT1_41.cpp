// Distance II
// 0319もう一度

// n乗はpowで乗数を1/nにしてやれば良い。double型気を付ける。
// 絶対値はfabs(x)

#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

double turnPlus(double num)
{

    if (num < 0)
    {
        num = num * (-1);
    }

    return num;
}

int main()
{
    int n;
    double x[101], y[101], p1 = 0, p2 = 0, p3 = 0, pinf = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
    }

    // p=1
    for (int i = 1; i <= n; i++)
    {
        p1 += turnPlus(x[i] - y[i]);
        p2 += turnPlus(x[i] - y[i]) * turnPlus(x[i] - y[i]);
        p3 += pow(turnPlus(x[i] - y[i]), 3);

        if (pinf < turnPlus(x[i] - y[i]))
            pinf = turnPlus(x[i] - y[i]);
    }

    p2 = sqrt(p2);
    // double指定してあげないと0乗になる
    p3 = pow(p3, (double)1 / (double)3);

    printf("%.6f\n%.6f\n%.6f\n%.6f\n", p1, p2, p3, pinf);

    return 0;
}
