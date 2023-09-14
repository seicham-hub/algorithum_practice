// https://atcoder.jp/contests/abc317/tasks/abc317_d
// 分からなかった

// 0904もう一度
// 0907もう一度
// 0710もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, z_sum = 0;

    cin >> n;

    vector<int> x(n), y(n), z(n);

    rep(i, n)
    {
        cin >> x[i] >> y[i] >> z[i];
        z_sum += z[i];
    }

    // dp[i] i議席獲得するのに必要な最小鞍替えコスト
    vector<long long> dp(z_sum + 1, 1e18);

    dp[0] = 0;

    rep(i, n)
    {
        int xi = x[i], yi = y[i], zi = z[i];

        long long w = max(0, (xi + yi) / 2 - xi + 1);

        for (int j = z_sum; j >= zi; j--)
        {
            dp[j] = min(dp[j], dp[j - zi] + w);
        }
    }

    long long ans = 1e18;

    for (int i = z_sum / 2 + 1; i <= z_sum; i++)
    {
        ans = min(dp[i], ans);
    }

    cout << ans << endl;
}

/*
9/4　やり直し分
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, z_sum = 0;
//     cin >> n;

//     vector<int> x(n), y(n), z(n);

//     rep(i, n)
//     {
//         cin >> x[i] >> y[i] >> z[i];
//         z_sum += z[i];
//     }

//     // 獲得議席がnの時の最小の鞍替え人数
//     vector<long long> dp(z_sum + 1, 1e18);
//     dp[0] = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int xi = x[i], yi = y[i], zi = z[i];

//         int w = max(0, (xi + yi) / 2 + 1 - xi);

//         for (int j = z_sum; j >= zi; j--)
//         {
//             dp[j] = min(dp[j], dp[j - zi] + w);
//         }
//     }

//     long long ans = 1e18;

//     for (int i = z_sum; i >= z_sum / 2 + 1; i--)
//     {
//         ans = min(ans, dp[i]);
//     }

//     cout << (long long)ans << endl;

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
//     long long inf = 1e18;

//     int n;
//     cin >> n;
//     vector<int> x(n), y(n), z(n);
//     rep(i, n) cin >> x[i] >> y[i] >> z[i];

//     int z_sum = accumulate(begin(z), end(z), 0);
//     vector<long long> dp(z_sum + 1, inf);

//     rep(i, n)
//     {
//         int X = x[i], Y = y[i], Z = z[i];
//         int w = max(0, (X + Y) / 2 + 1 - X);

//         for (int j = z_sum; j >= Z; Z--)
//         {
//             dp[j] = min(dp[j], dp[j - Z] + w);
//         }
//     }

//     long long ans = inf;
//     for (int j = z_sum / 2 + 1; j <= z_sum; j++)
//         ans = min(ans, dp[j]);

//     cout << ans << endl;

//     return 0;
// }