// https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_d
// 2024_07_12もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> dist[i];
    }

    vector<int> wether(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> wether[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int city = 1; city <= n; city++)
    {
        for (int day = city; day <= m; day++)
        {
            dp[city][day] = min(dp[city][day - 1], dp[city - 1][day - 1] + wether[day] * dist[city]);
        }
    }

    ll ans = 1e18;
    for (int i = n; i <= m; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << endl;

    return 0;
}

// 自分で書いたコード、遷移が冗長
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> dist(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> dist[i];
//     }

//     vector<int> wether(m + 1);
//     for (int i = 1; i <= m; i++)
//         cin >> wether[i];

//     vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 1e18));
//     for (int i = 0; i <= m; i++)
//         dp[0][i] = 0;

//     for (int city = 1; city <= n; city++)
//     {
//         for (int day = city; day <= m; day++)
//         {
//             for (int prev = 0; prev < day; ++prev)
//             {
//                 if (dp[city][day] == 1e18)
//                     dp[city][day] = dp[city - 1][prev] + wether[day] * dist[city];
//                 else
//                     dp[city][day] = min(dp[city][day], dp[city - 1][prev] + wether[day] * dist[city]);
//             }
//         }
//     }

//     ll ans = 1e18;
//     for (int i = n; i <= m; i++)
//         ans = min(ans, dp[n][i]);
//     cout << ans << endl;

//     return 0;
// }