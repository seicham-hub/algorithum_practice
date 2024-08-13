// https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b
//
// めちゃくちゃ時間かけたのにうまくできなかった
// 2024_08_13もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

//

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int iPlusOne(int iPlusOne, int n)
// {
//     if (iPlusOne > n)
//         return iPlusOne % n;
//     else
//         return iPlusOne;
// }
// int jPlus(int iPlusOne, int n, int l)
// {
//     l--;
//     if (iPlusOne > n)
//         return iPlusOne % n + l - 1;
//     else
//         return iPlusOne + l - 1;
// }

// int main()
// {

//     ll n;
//     cin >> n;

//     vector<ll> a(2 * n + 1);

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//         a[i + n] = a[i];
//     }
//     a[0] = a[n];

//     vector<vector<ll>> dp(2 * n + 1, vector<ll>(2 * n + 1));

//     for (int i = 1; i <= 2 * n; i++)
//         dp[i][i] = a[i];

//     for (int l = 2; l <= n; l++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             int j = i + l - 1;

//             if (l == n)
//             {
//                 if (l % 2 == 0)
//                     dp[i][j] = max(dp[i][j - 1], dp[iPlusOne(i + 1, n)][jPlus(i + 1, n, l)]);
//                 else
//                     dp[i][j] = max(dp[i][j - 1] + a[j], dp[iPlusOne(i + 1, n)][jPlus(i + 1, n, l)] + a[i]);
//             }
//             if (l % 2 == 0)
//             {
//                 if (a[i - 1] < a[j])
//                     dp[i][j] = dp[i][j - 1];
//                 if (a[i] > a[j + 1])
//                     dp[i][j] = max(dp[i][j], dp[iPlusOne(i + 1, n)][jPlus(i + 1, n, l)]);
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i][j - 1] + a[j], dp[iPlusOne(i + 1, n)][jPlus(i + 1, n, l)] + a[i]);
//             }
//         }
//     }

//     ll ans = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         ans = max(ans, dp[i][i + n - 1]);
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     ll n;
//     cin >> n;

//     vector<ll> a(n * 2);
//     vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));

//     rep(i, n)
//     {
//         cin >> a[i];
//         a[i + n] = a[i];
//         // iから始まって長さが1のところ
//         dp[i][1] = a[i];
//     }

//     for (ll i = 2; i <= n; i++)
//     {
//         for (ll j = 0; j < n; j++)
//         {
//             // if (i == n)
//             // {
//             //     if (i % 2 == 0)
//             //         dp[j][i] = max(dp[j][i - 1], dp[(j + 1) % n][i - 1]);
//             //     else
//             //         dp[j][i] = max(dp[j][i - 1] + a[j + i - 1], dp[(j + 1) % n][i - 1] + a[j]);
//             // }

//             if (i % 2 == 0)
//             {
//                 if (a[j + i - 1] >= a[j + n - 1])
//                     dp[j][i] = dp[j][i - 1];
//                 if (a[j] >= a[j + i])
//                     dp[j][i] = max(dp[j][i], dp[(j + 1) % n][i - 1]);
//             }
//             else
//             {
//                 dp[j][i] = max(dp[(j + 1) % n][i - 1] + a[j], dp[j][i - 1] + a[j + i - 1]);
//             }
//         }
//     }

//     ll ans = 0;
//     rep(i, n)
//     {
//         ans = max(ans, dp[i][n]);
//     }
//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> cake(2 * n + 2);

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> cake[i];
//         cake[n + i] = cake[i];
//     }
//     cake[0] = cake[n];
//     cake[2 * n + 1] = cake[1];

//     vector<vector<ll>> dp(2 * n + 1, vector<ll>(2 * n + 1, -1));

//     for (int i = 0; i <= n; i++)
//         dp[i][i] = cake[i];

//     for (int l = 2; l <= n; l++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             int j = i + l - 1;

//             if (l % 2 == 1)
//             {
//                 int a = i + 1;
//                 int b = j - 1;
//                 if (dp[a][j] != -1 && dp[i][b] != -1)
//                     dp[i][j] = max(dp[a][j] + cake[i], dp[i][b] + cake[j]);
//                 else if (dp[a][j] = !-1)
//                     dp[i][j] = max(dp[i][j], dp[a][j] + cake[i]);
//                 else if (dp[i][b] != -1)
//                     dp[i][j] = max(dp[i][j], dp[i][b] + cake[j]);
//             }
//             else
//             {
//                 int a = i - 1;
//                 int b = j + 1;

//                 int c = i + 1;
//                 int d = j - 1;

//                 if (cake[a] <= cake[j] && cake[i] >= cake[b])
//                     dp[i][j] = max(dp[i][d], dp[c][j]);
//                 else if (cake[a] <= cake[j])
//                     dp[i][j] = max(dp[i][j], dp[i][d]);
//                 else if (cake[i] >= cake[b])
//                     dp[i][j] = max(dp[i][j], dp[c][j]);
//             }
//         }
//     }

//     ll result = 0;

//     for (int i = 1; i <= n; i++)
//         result = max(result, dp[i][i + n - 1]);

//     cout << result << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// vector<ll> a(4009);
// ll dp[2009][2009] = {};
// int main()
// {
//     // 入力
//     ll n;
//     cin >> n;
//     rep(i, n)
//     {
//         cin >> a[i];
//         dp[i][1] = a[i];
//         a[i + n] = a[i];
//     }
//     for (ll i = 2; i <= n; i++)
//     {
//         for (ll j = 0; j < n; j++)
//         {
//             if (i == n)
//             {
//                 if (i % 2 == 0)
//                     dp[j][i] = max(dp[j][i - 1], dp[(j + 1) % n][i - 1]);
//                 else
//                     dp[j][i] = max(dp[j][i - 1] + a[j + i - 1], dp[(j + 1) % n][i - 1] + a[j]);
//             }
//             else if (i % 2 == 0)
//             {
//                 if (a[j + i - 1] >= a[j + n - 1])
//                     dp[j][i] = dp[j][i - 1];
//                 if (a[j] >= a[j + i])
//                     dp[j][i] = max(dp[j][i], dp[(j + 1) % n][i - 1]);
//             }
//             else
//             {
//                 dp[j][i] = max(dp[(j + 1) % n][i - 1] + a[j], dp[j][i - 1] + a[j + i - 1]);
//             }
//         }
//     }
//     ll ans = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         ans = max(ans, dp[i][n]);
//     }
//     cout << ans << endl;

//     return 0;
// }
