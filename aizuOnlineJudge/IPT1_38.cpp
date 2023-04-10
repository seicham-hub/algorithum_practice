// Distance
// 0319もう一度

// doubleをscanfで受け取る場合は%fで受け取る。
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{

    double x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    // 小数点以下5桁まで表示
    printf("%.5f", sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));

    return 0;
}
