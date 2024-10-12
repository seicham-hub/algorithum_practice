// https://atcoder.jp/contests/abc368/tasks/abc368_c

// 分からなかった...
// 2024_10_01もう一度
// 2024_10_13もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    ll t = 0;
    rep(i, n)
    {

        ll red = (h[i] / 5);
        h[i] -= red * 5;
        t += red * 3;

        while (h[i] > 0)
        {
            if ((t + 1) % 3 == 0)
                h[i] -= 3;
            else
                h[i] -= 1;

            t++;
        }
    }
    cout << t << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> h(n);
//     rep(i, n) cin >> h[i];

//     ll t = 0;
//     rep(i, n)
//     {
//         int x = h[i] / 5;
//         t += x * 3;

//         h[i] -= 5 * x;

//         while (h[i] > 0)
//         {
//             t++;
//             if (t % 3 == 0)
//                 h[i] -= 3;
//             else
//                 h[i] -= 1;
//         }
//     }

//     cout << t << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> h(n);
//     rep(i, n) cin >> h[i];

//     ll t = 0;

//     rep(i, n)
//     {
//         int x = h[i] / 5;
//         t += x * 3;

//         h[i] -= x * 5;

//         while (h[i] > 0)
//         {
//             t++;
//             if (t % 3 == 0)
//                 h[i] -= 3;
//             else
//                 h[i] -= 1;
//         }
//     }

//     cout << t << endl;
//     return 0;
// }