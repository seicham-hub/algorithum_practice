// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=ja
// ナップサック問題
// 重さも全探索する必要あり

// 2024_07_01もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> v(n), w(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (j - w[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, W;
//     cin >> n >> W;

//     vector<int> v(n), w(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> v[i] >> w[i];
//     }

//     // dp[i][j] 品物をi番目まで選ぶか決め、重さがj以下の価値の最大値

//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= W; j++)
//         {
//             if (j - w[i - 1] >= 0)
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
//             else
//                 dp[i][j] = dp[i - 1][j];
//         }
//     }

//     cout << dp[n][W] << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, wLimit;
//     cin >> n;

//     vector<int> w(n), v(n);

//     for (int i = 0; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         w[i] = a;
//         v[i] = b;
//     }
//     cin >> wLimit;

//     vector<vector<int>> dp(n + 1, vector<int>(0));

//     for (int wi = 0; wi <= wLimit; wi++)
//         dp[0][wi] = 0;

//     for (int i = 0; i < n; i++)
//     {
//         for (int wi = 0; wi <= wLimit; wi++)
//         {
//             // wi - w[i]が0以上の時
//             if (wi >= w[i])
//                 dp[i + 1][wi] = max(dp[i][wi - w[i]] + v[i], dp[i][wi]);
//             else
//                 dp[i + 1][wi] = dp[i + 1][wi];
//         }
//     }

//     cout << dp[n][wLimit] << endl;
//     return 0;
// }
