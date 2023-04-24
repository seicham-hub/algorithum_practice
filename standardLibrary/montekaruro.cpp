// 点を打って円周率を求める
// (πr^2)/(2r)^2 = π/4面積比。
// 点を打った個数と全体の点の数の比も面積比に一致するはず。

#include <iostream>
#include <ctime>
using namespace std;

const int NUMBER_OF_SAMPLES = 100;

int main()
{
    srand((unsigned)time(NULL));

    // 円周率を計算する
    int cnt = 0;
    for (int i = 0; i < NUMBER_OF_SAMPLES; i++)
    {
        // gcc, Visual Studio 両方に対応させています (後者では 32767 までの乱数しか出ません)
        double px = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
        double py = 1.0 * (rand() % 32768 + 0.5) / 32768.0;
        if (px * px + py * py <= 1.0)
            cnt++;
    }
    printf("PI = %.5lf\n", 4.0 * cnt / NUMBER_OF_SAMPLES);
    return 0;
}