// https://atcoder.jp/contests/abc354/tasks/abc354_d

// わからなかった...
// 負の値は下駄をはかせる
// 左下を(0,0)に帰着させて考える
// 2024_11_17もう一度
// 2024_11_23もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

ll f(ll a, ll b)
{
    ll res = 0;

    int ra = a % 4;
    int rb = b % 2;

    a -= ra;
    b -= rb;

    res += a * b;

    if (rb)
    {
        res += a;
    }

    if (ra >= 1)
    {
        res += (3 * b / 2);
        if (rb)
            res += 2;
    }
    if (ra >= 2)
    {
        res += (3 * b / 2);
        if (rb)
            res += 1;
    }
    if (ra >= 3)
    {
        res += (1 * b / 2);
    }

    return res;
}

int main()
{

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a += 1e9;
    b += 1e9;
    c += 1e9;
    d += 1e9;

    cout << f(c, d) << endl;
    cout << f(a, d) << endl;
    cout << f(c, b) << endl;
    cout << f(a, b) << endl;

    ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// ll f(ll a, ll b)
// {
//     ll ra = a % 4;
//     a -= ra;
//     ll rb = b % 2;
//     b -= rb;
//     ll res = a * b;

//     if (rb)
//         res += a;

//     if (ra >= 1)
//     {
//         res += b * 3 / 2;
//         if (rb)
//             res += 2;
//     }
//     if (ra >= 2)
//     {
//         res += b * 3 / 2;
//         if (rb)
//             res += 1;
//     }
//     if (ra >= 3)
//     {
//         res += b * 1 / 2;
//     }
//     return res;
// };

// int main()
// {
//     ll a, b, c, d;
//     cin >> a >> b >> c >> d;
//     a += 1e9;
//     b += 1e9;
//     c += 1e9;
//     d += 1e9;

//     ll ans = f(c, d) - f(a, d) - f(c, b) + f(a, b);
//     cout << ans << endl;

//     return 0;
// }