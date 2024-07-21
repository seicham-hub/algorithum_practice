// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
// 2024_07_17もう一度
// 2024_07_18もう一度

#include <bits/stdc++.h>
using namespace std;

int count_cost(int &column, char &color, vector<vector<char>> &s)
{
    int result = 0;
    for (int i = 1; i <= 5; i++)
        if (s[i][column] != color)
            result++;

    return result;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> s(6, vector<char>(n + 1));
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
    for (int i = 0; i < 3; i++)
        dp[0][i] = 0;

    vector<char> colors = {'R', 'B', 'W'};

    for (int col = 1; col <= n; col++)
        for (int i = 0; i < 3; i++)
            for (int before = 0; before < 3; before++)
                if (i != before)
                    dp[col][i] = min(dp[col][i], dp[col - 1][before] + count_cost(col, colors[i], s));

    int ans = INT_MAX;
    for (int i = 0; i < 3; i++)
        ans = min(ans, dp[n][i]);

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n;

// int reverse_count(int col, char &color, vector<vector<char>> &s)
// {
//     int result = 0;
//     for (int i = 1; i < 6; i++)
//     {
//         if (s[i][col] != color)
//             result++;
//     }

//     return result;
// }

// int main()
// {

//     cin >> n;

//     vector<vector<char>> s(6, vector<char>(n + 1));

//     for (int i = 1; i <= 5; i++)
//     {
//         for (int j = 1; j <= n; j++)
//             cin >> s[i][j];
//     }

//     vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
//     for (int i = 0; i < 3; i++)
//         dp[0][i] = 0;

//     vector<char> colors = {'R', 'B', 'W'};

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             for (int before = 0; before < 3; before++)
//             {
//                 if (before != j)
//                     dp[i][j] = min(dp[i][j], dp[i - 1][before] + reverse_count(i, colors[j], s));
//             }
//         }
//     }

//     int ans = INT_MAX;
//     for (int i = 0; i < 3; i++)
//         ans = min(ans, dp[n][i]);

//     cout << ans << endl;

//     return 0;
// }

// 自分で書いたコード
// めっちゃ時間かかったし、条件が複雑で追いにくい

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<char>> s(6, vector<char>(n + 1));

//     for (int i = 1; i <= 5; i++)
//     {
//         for (int j = 1; j <= n; j++)
//             cin >> s[i][j];
//     }

//     vector<char> colors = {'R', 'B', 'W', '#'};
//     vector<vector<vector<int>>> dp(6, vector<vector<int>>(n + 1, vector<int>(3, INT_MAX)));

//     for (int i = 0; i <= n; i++)
//         for (int j = 0; j < 3; j++)
//             dp[0][i][j] = 0;
//     for (int i = 0; i <= 5; i++)
//         for (int j = 0; j < 3; j++)
//             dp[i][0][j] = 0;

//     for (int j = 1; j <= n; j++)
//     {
//         for (int i = 1; i <= 5; i++)
//         {
//             for (int k = 0; k < 3; k++)
//             {

//                 if (i == 1)
//                     for (int prev = 0; prev < 3; prev++)
//                     {
//                         if (k != prev)
//                             if (colors[k] != s[i][j])
//                                 dp[i][j][k] = min(dp[i][j][k], dp[5][j - 1][prev] + 1);
//                             else
//                                 dp[i][j][k] = min(dp[i][j][k], dp[5][j - 1][prev]);
//                     }

//                 else
//                 {
//                     if (colors[k] != s[i][j])
//                         dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + 1);
//                     else
//                         dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
//                 }
//             }
//         }
//     }

//     int ans = INT_MAX;

//     for (int i = 0; i < 3; i++)
//         ans = min(ans, dp[5][n][i]);

//     cout << ans << endl;

//     return 0;
// }