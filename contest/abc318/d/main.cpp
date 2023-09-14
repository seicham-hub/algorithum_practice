// https://atcoder.jp/contests/abc318/tasks/abc318_d

// 分からなかった
// 0814もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> d(n - 1, vector<int>(n - 1));

    rep(i, n - 1)
    {
        rep(j, n - i - 1) cin >> d[i][j];
    }

    // dp[b] bの立っているビット＝選んでいる端点としたときの重みの最大値

    vector<long long> dp(1 << n);
    dp[0] = 0ll;

    rep(b, 1 << n)
    {

        rep(i, n)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!(b & i << 1) && !(b & j << 1))
                {
                    int next = (b | i << 1) | j << 1;
                    dp[next] = max(dp[next], dp[b] + d[i][j]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << endl;

    return 0;
}

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