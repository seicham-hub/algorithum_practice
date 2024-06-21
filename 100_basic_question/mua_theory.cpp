// https://atcoder.jp/contests/arc054/tasks/arc054_b
// 分からなかった

// 2024_06_20もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double f(double &x, double &p)
{
    return x + p / pow(2.0, x / 1.5);
}

double find_min_time(double &p)
{
    double left = 0;
    double right = 1e18;

    while (right - left > 1e-9)
    {

        double l1 = (2 * left + right) / 3;
        double l2 = (left + 2 * right) / 3;

        if (f(l1, p) > f(l2, p))
            left = l1;
        else
            right = l2;
    }

    return f(left, p);
}

int main()
{

    double p;
    cin >> p;

    double ans = find_min_time(p);

    printf("%.10f", ans);
}

// #include <bits/stdc++.h>
// using namespace std;

// double f(double &x, double &p)
// {

//     return x + p / pow(2.0, x / 1.5);
// }

// double find_minmun_time(double &p)
// {

//     double left = 0;
//     double right = 1e18;

//     while (right - left > 1e-9)
//     {
//         double l1 = (2 * left + right) / 3;
//         double l2 = (left + 2 * right) / 3;

//         if (f(l1, p) > f(l2, p))
//             left = l1;
//         else
//             right = l2;
//     }

//     return f(left, p);
// }

// int main()
// {

//     double p;
//     cin >> p;

//     double ans = find_minmun_time(p);

//     printf("%.10f\n", ans);

//     return 0;
// }

// お手本コード
// #include <iostream>
// #include <cmath>
// #include <iomanip>
// using namespace std;

// double f(double x, double P)
// {
//     return x + P / pow(2.0, x / 1.5);
// }

// double find_minimum_time(double P)
// {
//     double left = 0.0, right = P; // right を P にしているのは、最悪でも P 年後に計算を始める
//     while (right - left > 1e-9)
//     { // 精度を高めるため、1e-9 まで繰り返す
//         double l1 = (2 * left + right) / 3;
//         double l2 = (left + 2 * right) / 3;
//         if (f(l1, P) > f(l2, P))
//         {
//             left = l1;
//         }
//         else
//         {
//             right = l2;
//         }
//     }
//     return f(left, P); // left でも right でもほぼ同じ値
// }

// int main()
// {
//     double P;
//     cin >> P;
//     double result = find_minimum_time(P);
//     cout << fixed << setprecision(10) << result << endl; // 出力の精度を指定
//     return 0;
// }
