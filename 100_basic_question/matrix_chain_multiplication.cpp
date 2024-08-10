// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_B&lang=ja

// 分からなかった
// 2024_08_08もう一度
// 2024_08_11もう一度

#include <bits/stdc++.h>
using namespace std;

int count_min(int &start, int &end, vector<pair<int, int>> &m, vector<vector<int>> &dp)
{
    int result = INT_MAX;
    for (int i = start; i < end; i++)
    {
        result = min(result, dp[start][i] + dp[i + 1][end] + m[start].first * m[i].second * m[end].second);
    }

    return result;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> m(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> m[i].first >> m[i].second;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i <= n; i++)
        dp[i][i] = 0;

    for (int l = 1; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;

            dp[i][j] = min(dp[i][j], count_min(i, j, m, dp));
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int matrixChainMultiplication(vector<int> &p, int n)
// {

//     vector<vector<int>> dp(n, vector<int>(n, 0));

//     // lは連鎖の長さ
//     for (int l = 1; l < n; l++)
//     {
//         for (int i = 0; i <= n - 1 - l; i++)
//         {
//             int j = i + l;
//             dp[i][j] = INT_MAX;
//             for (int k = i; k <= j - 1; k++)
//             {
//                 int q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
//                 if (q < dp[i][j])
//                 {
//                     dp[i][j] = q;
//                 }
//             }
//         }
//     }

//     return dp[0][n - 1];
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> p(n + 1);
//     vector<int> r(n), c(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> r[i] >> c[i];
//         p[i] = r[i];
//         if (i == n - 1)
//             p[i + 1] = c[i];
//     }

//     cout << matrixChainMultiplication(p, n) << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int matrixChainMultiplication(vector<int> &p, int n)
// {
//     vector<vector<int>> m(n, vector<int>(n, 0));

//     for (int l = 2; l < n; l++)
//     { // l is chain length
//         for (int i = 1; i < n - l + 1; i++)
//         {

//             int j = i + l - 1;
//             m[i][j] = INT_MAX;
//             for (int k = i; k <= j - 1; k++)
//             {
//                 int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
//                 if (q < m[i][j])
//                 {
//                     m[i][j] = q;
//                 }
//             }
//         }
//     }

//     return m[1][n - 1];
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> p(n + 1);
//     vector<int> r(n), c(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> r[i] >> c[i];
//         p[i] = r[i];
//         if (i == n - 1)
//         {
//             p[i + 1] = c[i];
//         }
//     }

//     cout << matrixChainMultiplication(p, n + 1) << endl;
//     return 0;
// }

// 自分のコード改良したもの(あまりよくない)
// #include <bits/stdc++.h>
// using namespace std;

// int count_scalar(int start, int end, vector<pair<int, int>> &matrix, vector<vector<int>> &dp)
// {
//     int result = INT_MAX;
//     for (int i = start; i < end; i++)
//     {
//         result = min(result, dp[start][i] + dp[i + 1][end] + matrix[start].first * matrix[i].second * matrix[end].second);
//     }

//     return result;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<pair<int, int>> matrix(n + 1);

//     for (int i = 1; i <= n; i++)
//     {
//         int r, c;
//         cin >> r >> c;
//         matrix[i] = {r, c};
//     }

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
//     for (int i = 0; i <= n; i++)
//         dp[i][i] = 0;

//     for (int length = 1; length <= n; length++)
//     {
//         for (int i = 1; i <= n - length; i++)
//         {
//             int j = i + length;

//             dp[i][j] = min(dp[i][j], count_scalar(i, j, matrix, dp));
//         }
//     }

//     cout << dp[1][n] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<pair<int, int>> matrix;
//     for (int i = 0; i < n; i++)
//     {
//         int r, c;
//         cin >> r >> c;
//         matrix.push_back({r, c});
//     }
//     return 0;
// }