// https://atcoder.jp/contests/abc359/tasks/abc359_c
// 分からなかった...

// 2024_11_03もう一度
// こういう問題は代表の点で表す。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    ll sx, sy, tx, ty;

    cin >> sx >> sy >> tx >> ty;

    if ((sx + sy) % 2 == 1)
        sx--;
    if ((tx + ty) % 2 == 1)
        tx--;

    ll dx = abs(tx - sx);
    ll dy = abs(ty - sy);

    ll ans = 0;

    if (dy > dx)
    {
        ans = dy;
    }
    else
    {
        ans = (dx + dy) / 2;
    }

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     ll sx, sy, tx, ty;
//     cin >> sx >> sy >> tx >> ty;

//     if ((sx + sy) % 2 == 1)
//         sx--;
//     if ((tx + ty) % 2 == 1)
//         tx--;

//     ll ans = 0;

//     ll dx = abs(tx - sx);
//     ll dy = abs(ty - sy);

//     if (dy > dx)
//         ans = dy;
//     else
//         ans = (dx + dy) / 2;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     ll sx, sy, tx, ty;
//     cin >> sx >> sy >> tx >> ty;

//     if ((sx + sy) % 2 == 1)
//         sx--;
//     if ((tx + ty) % 2 == 1)
//         tx--;
//     ll dx = abs(tx - sx);
//     ll dy = abs(ty - sy);
//     ll ans = 0;

//     if (dy > dx)
//         ans = dy;
//     else
//         ans = (dx + dy) % 2;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     ll sx, sy, tx, ty;
//     cin >> sx >> sy >> tx >> ty;

//     ll ans = 0;
//     ans += abs(ty - sy);
//     ll dx = abs(tx - sx);
//     ans += dx;

//     if (sy == ty)
//     {
//         // 偶数地点に壁
//         if (sy % 2 == 0)

//             else
//     }
//     else if (sx == tx)
//     {
//     }

//     // 目的地右にあるとき
//     else if (sy - sx > 0)
//     {
//         // 偶数地点に壁
//         if (sy % 2 == 0)
//         {
//             // 左に壁
//             if (sx % 2 == 0)
//                 ans -= min(dx, abs(ty - sy) + 1);
//             // 右に壁
//             else
//                 ans -= min(dx, abs(ty - sy));
//         }
//         // 奇数地点に壁
//         else
//         {
//             // 左に壁
//             if (sx % 2 == 0)
//                 ans -= min(dx, abs(ty - sy));
//             // 右に壁
//             else
//                 ans -= min(dx, abs(ty - sy) + 1);
//         }
//     }
//     // 目的地左
//     else if (sy - sx > 0)
//     {
//         // 偶数地点に壁
//         if (sy % 2 == 0)
//         {
//             // 左に壁
//             if (sx % 2 == 0)
//                 ans -= min(dx, abs(ty - sy));
//             // 右に壁
//             else
//                 ans -= min(dx, abs(ty - sy) + 1);
//         }
//         // 奇数地点に壁
//         else
//         {
//             // 左に壁
//             if (sx % 2 == 0)
//                 ans -= min(dx, abs(ty - sy) + 1);
//             // 右に壁
//             else
//                 ans -= min(dx, abs(ty - sy));
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }