// https://atcoder.jp/contests/abc318/tasks/abc318_d

// 分からなかった
// 0814もう一度
// 0928もう一度
// 1002もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> d(n - 1, vector<int>(n));

    rep(i, n - 1)
    {
        rep(j, n - i - 1)
        {
            cin >> d[i][j + i + 1];
        }
    }

    // rep(i, n - 1)
    // {
    //     for (int j = i + 1; j <= n - 1; j++)
    //         cin >> d[i][j];
    // }

    vector<long long> dp(1 << n);
    dp[0] = 0ll;

    rep(i, 1 << n)
    {
        rep(j, n)
        {
            for (int k = j + 1; k < n; k++)
            {

                if (!(i & (1 << j)) && !(i & (1 << k)))
                {
                    int next = i | (1 << j) | (1 << k);
                    dp[next] = max(dp[next], dp[i] + d[j][k]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> d(n - 1, vector<int>(n));

//     rep(i, n)
//     {
//         rep(j, n - 1 - i)
//         {
//             cin >> d[i][i + 1 + j];
//         }
//     }

//     vector<ll> dp(1 << n);
//     dp[0] = 0ll;

//     rep(i, 1 << n)
//     {
//         rep(j, n)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 if (!(i & (1 << j)) && !(i & (1 << k)))
//                     dp[i | (1 << j) | (1 << k)] = max(dp[i | (1 << j) | (1 << k)], dp[i] + d[j][k]);
//             }
//         }
//     }

//     cout << dp[(1 << n) - 1] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> d(n, vector<int>(n));

//     rep(i, n - 1)
//     {
//         rep(j, n - i - 1)
//         {
//             cin >> d[i][j + i + 1];
//         }
//     }

//     // dp[b] bの立っているビット＝選んでいる端点としたときの重みの最大値

//     vector<long long> dp(1 << n);
//     dp[0] = 0ll;

//     rep(b, 1 << n)
//     {

//         rep(i, n)
//         {
//             for (int j = i + 1; j < n; j++)
//             {
//                 if (!(b & (1 << i)) && !(b & (1 << j)))
//                 {
//                     int next = b | (1 << i) | (1 << j);
//                     dp[next] = max(dp[next], dp[b] + d[i][j]);
//                 }
//             }
//         }
//     }

//     cout << dp[(1 << n) - 1] << endl;

//     return 0;
// }

/*
解答のコード
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;
//     vector d(n, vector(n, 0));

//     rep(i, n)
//     {
//         for (int j = i + 1; j < n; j++)
//             cin >> d[i][j];
//     }

//     vector dp(1 << n, 0ll);

//     rep(b, (1 << n) - 1)
//     {
//         int l = -1;
//         rep(i, n) if (!(b >> i & 1))
//         {
//             l = i;
//             break;
//         }

//         rep(i, n) if (!(b >> i & 1))
//         {
//             int nb = b | (1 << l) | (1 << i);
//             dp[nb] = max(dp[nb], dp[b] + d[l][i]);
//         }
//     }

//     cout << dp.back() << endl;

//     return 0;
// }