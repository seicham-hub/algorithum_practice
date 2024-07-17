// https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d

// 2024_07_10もう一度
// 2024_07_12もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, n;
    cin >> d >> n;

    vector<array<int, 3>> clothes(n);

    vector<int> temp(d + 1);
    for (int i = 1; i <= d; i++)
        cin >> temp[i];

    for (int i = 0; i < n; i++)
        cin >> clothes[i][0] >> clothes[i][1] >> clothes[i][2];

    vector<vector<long long>> dp(d + 1, vector<long long>(n, -1));

    for (int day = 1; day <= d; day++)
    {
        for (int cur = 0; cur < n; cur++)
        {
            for (int prev = 0; prev < n; prev++)
            {
                if (clothes[cur][0] <= temp[day] && temp[day] <= clothes[cur][1])
                {
                    if (day == 1)
                        dp[day][cur] = 0;
                    else if (dp[day - 1][prev] != -1)
                        dp[day][cur] = max(dp[day][cur], dp[day - 1][prev] + abs(clothes[cur][2] - clothes[prev][2]));
                }
            }
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, dp[d][i]);

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int d, n;
//     cin >> d >> n;

//     vector<int> temp(d + 1);
//     for (int i = 1; i <= d; i++)
//         cin >> temp[i];

//     vector<array<int, 3>> clothes(n + 1);
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> clothes[i][0] >> clothes[i][1] >> clothes[i][2];
//     }

//     vector<vector<int>> dp(d + 1, vector<int>(n + 1, -1));

//     for (int day = 1; day <= d; day++)
//     {
//         for (int c = 1; c <= n; c++)
//         {
//             for (int i = 1; i <= n; i++)
//             {
//                 if (clothes[c][0] <= temp[day] && temp[day] <= clothes[c][1])
//                 {

//                     if (day == 1)
//                         dp[day][c] = 0;
//                     else if (dp[day - 1][i] != -1)
//                         dp[day][c] = max(dp[day][c], dp[day - 1][i] + abs(clothes[c][2] - clothes[i][2]));
//                 }
//             }
//         }
//     }

//     int ans = 0;
//     for (int i = 0; i <= n; i++)
//         ans = max(ans, dp[d][i]);

//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int d, n;
//     cin >> d >> n;

//     vector<int> temp(d + 1);

//     for (int i = 1; i <= d; i++)
//     {
//         cin >> temp[i];
//     }

//     vector<array<int, 3>> clothes(n + 1);

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> clothes[i][0] >> clothes[i][1] >> clothes[i][2];
//     }

//     vector<vector<long long>> dp(d + 1, vector<long long>(n + 1, -1));

//     for (int day = 1; day <= d; day++)
//     {
//         for (int cur = 1; cur <= n; ++cur)
//         {
//             for (int prev = 1; prev <= n; prev++)
//             {
//                 if (clothes[cur][0] <= temp[day] && temp[day] <= clothes[cur][1])
//                 {
//                     if (day == 1)
//                         dp[day][cur] = 0;
//                     else if (dp[day - 1][prev] != -1)
//                         dp[day][cur] = max(dp[day][cur], dp[day - 1][prev] + abs(clothes[cur][2] - clothes[prev][2]));
//                 }
//             }
//         }
//     }

//     long long ans = 0;

//     for (int i = 1; i <= n; i++)
//         ans = max(ans, dp[d][i]);

//     cout << ans << endl;

//     return 0;
// }
