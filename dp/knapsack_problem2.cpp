// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_C&lang=ja

// 2024_07_02もう一度

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

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {

            if (j - w[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i - 1]] + v[i - 1]);
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

//     vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j <= W; j++)
//         {

//             if (j - w[i] >= 0)
//                 dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
//             else
//                 dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
//         }
//     }

//     cout << dp[n][W] << endl;
// }