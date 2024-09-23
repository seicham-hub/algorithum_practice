// https://atcoder.jp/contests/abc362/tasks/abc362_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {};

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
};

int norm2(Point a, Point b)
{
    Point p = b - a;
    return p.x * p.x + p.y * p.y;
}

int main()
{
    Point a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    int A = norm2(b, c);
    int B = norm2(b, c);
    int C = norm2(b, c);

    if (A + B == C || A + C == B || B + C == A)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// struct Point
// {
//     int x, y;
// };
// int cPow(int x, int e)
// {

//     return x * x;
// }

// int main()
// {
//     Point a, b, c;
//     cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

//     bool ans = false;

//     // aの対辺が斜辺の時
//     if (cPow(c.x - b.x, 2) + cPow(c.y - b.y, 2) == cPow(c.x - a.x, 2) + cPow(c.y - a.y, 2) + cPow(b.x - a.x, 2) + cPow(b.y - a.y, 2))
//         ans = true;

//     if (cPow(c.x - a.x, 2) + cPow(c.y - a.y, 2) == cPow(c.x - b.x, 2) + cPow(c.y - b.y, 2) + cPow(b.x - a.x, 2) + cPow(b.y - a.y, 2))
//         ans = true;

//     if (cPow(b.x - a.x, 2) + cPow(b.y - a.y, 2) == cPow(c.x - a.x, 2) + cPow(c.y - a.y, 2) + cPow(b.x - c.x, 2) + cPow(b.y - c.y, 2))
//         ans = true;

//     if (ans)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }