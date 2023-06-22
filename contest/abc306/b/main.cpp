// https://atcoder.jp/contests/abc306/tasks/abc306_b

// 0620もう一度
// 0621もう一度

// long long型は64bit→2^63-1までしか表現できない　先頭bitが符号を表す為

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ull = unsigned long long;

int main()
{
    ull ans = 0;
    int a;

    rep(i, 64)
    {
        cin >> a;
        ans += (1ull << i) * a;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ull = unsigned long long;

// int main()
// {
//     ull ans = 0;

//     rep(i, 64)
//     {
//         ull a;
//         cin >> a;
//         ans += a * (1ull << i);
//     }

//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     vector<int> a(64);
//     unsigned long long ans = 0;

//     rep(i, 64)
//     {
//         cin >> a[i];
//     }

//     for (int i = 63; i >= 0; i--)
//     {
//         if (a[i] == 1)
//         {

//             ans = ans | (1LL << i);
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }