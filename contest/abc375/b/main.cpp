// https://atcoder.jp/contests/abc375/tasks/abc375_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    int n;
    cin >> n;

    vector<int> x(n + 1), y(n + 1);
    x[0] = 0;
    y[0] = 0;

    rep(i, n) cin >> x[i] >> y[i];

    auto calc = [&](double x, double y, double ex, double ey)
    {
        double dx = ex - x;
        double dy = ey - y;

        return sqrt(dx * dx + dy * dy);
    };

    double ans = 0;
    rep(i, n + 1)
    {

        int next = (i + 1) % (n + 1);

        ans += calc(x[i], y[i], x[next], y[next]);
    }

    printf("%.10f", ans);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// struct Point
// {
//     int x, y;
// };

// int main()
// {
//     int n;
//     cin >> n;

//     vector<Point> xy;
//     Point init;
//     init.x = 0;
//     init.y = 0;
//     xy.push_back(init);

//     rep(i, n)
//     {
//         Point txy;
//         cin >> txy.x >> txy.y;
//         xy.push_back(txy);
//     }

//     auto dist = [&](Point s, Point e)
//     {
//         ll xx = ll(e.x - s.x) * ll(e.x - s.x);
//         ll yy = ll(e.y - s.y) * ll(e.y - s.y);
//         return sqrt(xx + yy);
//     };

//     double ans = 0;

//     rep(i, n + 1)
//     {
//         int next = (i + 1) % (n + 1);
//         ans += dist(xy[i], xy[next]);
//     }

//     cout << printf("%.10f", ans) << endl;

//     return 0;
// }