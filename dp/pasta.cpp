// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d

// 2024_07_06もう一度

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<pair<int, int>> decided(k + 1);

//     for (int i = 1; i <= k; i++)
//         cin >> decided[i].first >> decided[i].second;

//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(3, 0)));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= 3; j++)
//         {
//             for (int k = 0; k < 3; k++)
//             {

//                 if (j == 1)
//                 {
//                     for (int l = 1; l <= 3; l++)
//                         if (l != j)
//                             dp[i][j][1] += dp[i - 1][l][k];
//                 }
//                 else if (j == 2 || j == 3)
//                     dp[i][j][k] += dp[i - 1][j][k - 1];
//             }
//         }
//     }

//     long long ans = 0;

//     for (int i = 1; i <= 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             ans += dp[n][i][j];
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }