// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja

// 2024_07_04もう一度

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> c(m);

    for (int i = 0; i < m; i++)
        cin >> c[i];

    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
            if (i - c[j] >= 0)
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
    }

    cout << dp[n] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> coins(m);
//     for (int i = 0; i < m; i++)
//         cin >> coins[i];

//     vector<int> dp(n + 1, INT_MAX);
//     dp[0] = 0;

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = coins[i]; j <= n; ++j)
//         {
//             if (j - coins[i] >= 0)
//                 dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//         }
//     }

//     cout << dp[n] << endl;

//     return 0;
// }

// 自分で書いたコード

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> c(m);

//     for (int i = 0; i < m; i++)
//     {
//         cin >> c[i];
//     }

//     int INF = 1e9;
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));

//     for (int i = 1; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             if (j % c[i - 1] == 0)
//                 dp[i][j] = j / c[i - 1];
//             else
//             {
//                 if (j - c[i - 1] >= 0)
//                     dp[i][j] = min(dp[i - 1][j], dp[i][j - c[i - 1]] + 1);
//                 else
//                     dp[i][j] = min(dp[i - 1][j], dp[i - 1][j]);
//             }
//         }
//     }

//     cout << dp[m][n] << endl;

//     return 0;
// }