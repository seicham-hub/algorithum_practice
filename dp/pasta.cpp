// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d

// 2024_07_06もう一度
// 2024_07_08もう一度
// 2024_07_09もう一度

#include <bits/stdc++.h>
using namespace std;

const int MOD = 10000;

int main()
{

    int n, k;
    cin >> n >> k;

    unordered_map<int, int> pre;

    for (int i = 0; i < k; i++)
    {
        int day, taste;
        cin >> day >> taste;

        pre[day] = taste;
    }

    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(3, vector<long long>(3, 0)));
    dp[0][0][0] = 1;

    for (int day = 1; day <= n; ++day)
    {
        for (int cur = 0; cur < 3; ++cur)
        {
            for (int prev = 0; prev < 3; ++prev)
            {
                for (int prevprev = 0; prevprev < 3; ++prevprev)
                {

                    if (day != 1 && day != 2 && cur == prev && prev == prevprev)
                        continue;

                    if (!pre.count(day))
                        dp[day][cur][prev] = (dp[day][cur][prev] + dp[day - 1][prev][prevprev]) % MOD;
                    else
                    {
                        if (pre[day] - 1 == cur)
                            dp[day][cur][prev] = (dp[day][cur][prev] + dp[day - 1][prev][prevprev]) % MOD;
                    }
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            ans = (ans + dp[n][i][j]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 10000;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     unordered_map<int, int> pre;

//     for (int i = 0; i < k; i++)
//     {
//         int day, taste;
//         cin >> day >> taste;

//         pre[day] = taste;
//     }

//     vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(3, vector<long long>(3, 0)));
//     dp[0][0][0] = 1;

//     for (int day = 1; day <= n; ++day)
//     {
//         for (int cur = 0; cur < 3; ++cur)
//         {
//             for (int prev = 0; prev < 3; ++prev)
//             {
//                 for (int prevprev = 0; prevprev < 3; ++prevprev)
//                 {

//                     if (day != 1 && day != 2 && cur == prev && prev == prevprev)
//                         continue;

//                     if (pre[day])
//                     {
//                         if (pre[day] - 1 == cur)
//                             dp[day][cur][prev] = (dp[day][cur][prev] + dp[day - 1][prev][prevprev]) % MOD;
//                     }
//                     else
//                     {
//                         dp[day][cur][prev] = (dp[day][cur][prev] + dp[day - 1][prev][prevprev]) % MOD;
//                     }
//                 }
//             }
//         }
//     }

//     long long ans = 0;

//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             ans = (ans + dp[n][i][j]) % MOD;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 10000;

// int main()
// {
//     int N, K;
//     cin >> N >> K;
//     vector<int> pasta(N + 1, 0); // 各日付のパスタの種類を格納

//     for (int i = 0; i < K; ++i)
//     {
//         int A, B;
//         cin >> A >> B;
//         pasta[A] = B; // A日目のパスタはBに決定
//     }

//     // DPテーブルの初期化
//     vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(4, vector<int>(4, 0)));

//     // 初日の設定
//     if (pasta[1] != 0)
//     {
//         dp[1][pasta[1]][0] = 1;
//     }
//     else
//     {
//         for (int i = 1; i <= 3; ++i)
//         {
//             dp[1][i][0] = 1;
//         }
//     }

//     // DPの遷移
//     for (int day = 2; day <= N; ++day)
//     {
//         for (int prev = 1; prev <= 3; ++prev)
//         {
//             for (int prevprev = 0; prevprev <= 3; ++prevprev)
//             {
//                 if (pasta[day] != 0)
//                 {
//                     if (pasta[day] != prev || pasta[day] != prevprev)
//                     {
//                         dp[day][pasta[day]][prev] = (dp[day][pasta[day]][prev] + dp[day - 1][prev][prevprev]) % MOD;
//                     }
//                 }
//                 else
//                 {
//                     for (int curr = 1; curr <= 3; ++curr)
//                     {
//                         if (curr != prev || curr != prevprev)
//                         {
//                             dp[day][curr][prev] = (dp[day][curr][prev] + dp[day - 1][prev][prevprev]) % MOD;
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     // 結果を集計
//     int result = 0;
//     for (int i = 1; i <= 3; ++i)
//     {
//         for (int j = 1; j <= 3; ++j)
//         {
//             result = (result + dp[N][i][j]) % MOD;
//         }
//     }

//     cout << result << endl;
//     return 0;
// }

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