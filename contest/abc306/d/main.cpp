// https://atcoder.jp/contests/abc306/tasks/abc306_d
// 0619もう一度
// 計算量はdp[i][p] O(N×2)
// 0620もう一度
// 0622もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

void chmax(ll &x, ll y)
{
    x = max(x, y);
}

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }

    ll INF = 1e18;

    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[0][0] = 0;

    rep(i, n)
    {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
        if (x[i] == 0)
        {
            chmax(dp[i + 1][0], dp[i][0] + y[i]);
            chmax(dp[i + 1][0], dp[i][1] + y[i]);
        }
        else
        {
            chmax(dp[i + 1][1], dp[i][0] + y[i]);
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// void chmax(ll &x, ll y)
// {
//     x = max(x, y);
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> x(n), y(n);

//     rep(i, n)
//     {
//         cin >> x[i] >> y[i];
//     }

//     ll INF = 1e18;

//     // 何個目？毒？のときの価値の最大値
//     vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));

//     dp[0][0] = 0;

//     rep(i, n)
//     {
//         // 何も食べないとき
//         chmax(dp[i + 1][0], dp[i][0]);
//         chmax(dp[i + 1][1], dp[i][1]);

//         if (x[i] == 1)
//         {
//             chmax(dp[i + 1][1], dp[i][0] + y[i]);
//         }
//         else
//         {
//             chmax(dp[i + 1][0], dp[i][0] + y[i]);
//             chmax(dp[i + 1][0], dp[i][1] + y[i]);
//         }
//     }

//     ll ans = max(dp[n][0], dp[n][1]);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// void chmax(ll &x, ll y)
// {
//     x = max(x, y);
// }

// int main()
// {
//     int n;
//     vector<int> x(n), y(n);
//     rep(i, n) cin >> x[i] >> y[i];

//     const ll INF = 1e18;
//     vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));

//     // 今何個目？毒かどうかの状態。
//     dp[0][0] = 0;

//     rep(i, n)
//     {
//         chmax(dp[i + 1][0], dp[i][0]);
//         chmax(dp[i + 1][1], dp[i][1]);

//         if (x[i] == 0)
//         {
//             chmax(dp[i + 1][0], dp[i][0] + y[i]);
//             chmax(dp[i + 1][0], dp[i][1] + y[i]);
//         }
//         else
//         {
//             chmax(dp[i + 1][1], dp[i][0] + y[i]);
//         }
//     }

//     ll ans = max(dp[n][0], dp[n][1]);
//     cout << ans << endl;

//     return 0;
// }

// 本番のコード

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> x(n);
//     vector<long long> y(n);

//     rep(i, n)
//     {
//         cin >> x[i] >> y[i];
//     }

//     int status = 0;
//     bool poipu = false;
//     bool sickpu = false;
//     long long poiM = 0;
//     long long sickD = 0;
//     long long ans = 0;

//     rep(i, n)
//     {
//         if (x[i] == 0 && y[i] >= 0)
//         {
//             ans += y[i];
//             continue;
//         }
//         if (x[i] == 1 && y[i] < 0)
//         {
//             continue;
//         }

//         if (sickpu)
//         {
//             if (y[i] > sickD || i == n - 1)
//             {

//                 ans -= sickD;
//                 status = 0;
//                 sickD = 0;
//                 sickpu = false;
//             }
//         }

//         if (poipu && x[i] == 0)
//         {
//             if (poiM > abs(y[i]) || i == n)
//             {
//                 ans += poiM + y[i];
//                 status = 0;
//             }
//             else
//             {
//                 status = 1;
//             }

//             poiM = 0;
//             poipu = false;

//             continue;
//         }

//         if (status == 0)
//         {

//             if (x[i] == 1 && y[i] > 0)
//             {
//                 poipu = true;
//                 poiM = max(y[i], poiM);
//             }
//         }
//         else if (status == 1)
//         {
//             if (x[i] == 0 && y[i] < 0)
//             {
//                 sickD = abs(y[i]);
//                 sickpu = true;
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }