// https://atcoder.jp/contests/abc369/tasks/abc369_d

// 解けたが、コードの書き方が悪かった

// 2025_01_13もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    rep(i, n) cin >> a[i];

    const ll INF = 1e18;
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));

    dp[0][0] = 0;

    rep(i, n)
    {
        rep(j, 2)
        {
            int ni = i + 1;
            {
                int nj = (j + 1) % 2;
                int X = nj == 0 ? 2 * a[i] : a[i];
                dp[ni][nj] = max(dp[ni][nj], dp[i][j] + X);
            }
            {
                int nj = j;
                dp[ni][nj] = max(dp[ni][nj], dp[i][j]);
            }
        }
    }

    ll ans = max(dp[n][0], dp[n][1]);

    cout << ans << endl;

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
//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

//     for (int i = 1; i <= n; i++)
//     {
//         if (i > 1)
//         {
//             dp[i][0] = max(dp[i][0], dp[i - 1][0]);
//             dp[i][0] = max(dp[i][0], dp[i - 1][1] + 2 * a[i - 1]);
//         }

//         dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i - 1]);
//         dp[i][1] = max(dp[i][1], dp[i - 1][1]);
//     }

//     ll ans = max(dp[n][0], dp[n][1]);
//     cout << ans << endl;
//     return 0;
// }