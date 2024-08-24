// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp
// 分からなかった..　連番にならないときどのように扱えばよいか分からなった
// 2024_08_17もう一度
// 2024_08_19もう一度
#include <bits/stdc++.h>
using namespace std;

int main()
{

    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> w(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> w[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int l = 2; l <= n; l++)
        {
            for (int i = 1; i <= n - l + 1; i++)
            {
                int j = i + l - 1;

                if (l % 2 == 0)
                {

                    if (dp[i + 1][j - 1] == l - 2 && abs(w[i] - w[j]) <= 1)
                        dp[i][j] = l;
                    else
                    {
                        for (int k = i; k < j; k++)
                        {
                            dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
                        }
                    }
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        cout << dp[1][n] << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     while (true)
//     {
//         int n;
//         cin >> n;
//         if (!n)
//             break;

//         vector<int> w(n + 1);
//         for (int i = 1; i <= n; i++)
//         {
//             cin >> w[i];
//         }

//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int l = 2; l <= n; l++)
//         {
//             for (int i = 1; i <= n - l + 1; i++)
//             {
//                 if (dp[i + 1][l - 2] == l - 2 && abs(w[i] - w[i + l - 1]) <= 1)
//                 {
//                     dp[i][l] = l;
//                 }

//                 for (int k = 1; k < l; k++)
//                     dp[i][l] = max(dp[i][l], dp[i][k] + dp[i + k][l - k]);
//             }
//         }
//         cout << dp[1][n] << endl;
//     }
//     return 0;
// }

// chatGPTの回答
// #include <iostream>
// #include <vector>
// #include <cstring>

// using namespace std;

// int dp[305][305];

// int main()
// {
//     while (true)
//     {
//         int n;
//         cin >> n;
//         if (n == 0)
//             break;

//         vector<int> w(n);
//         for (int i = 0; i < n; ++i)
//         {
//             cin >> w[i];
//         }

//         memset(dp, 0, sizeof(dp));

//         // lは範囲の長さを表す
//         for (int l = 2; l <= n; ++l)
//         {
//             for (int i = 0; i <= n - l; ++i)
//             {
//                 int j = i + l - 1;

//                 // 隣接する2つのブロックが取り除けるかどうか
//                 if (l == 2 && abs(w[i] - w[j]) <= 1)
//                 {
//                     dp[i][j] = 2;
//                 }

//                 // ブロック i から j までの間で取り除ける最大数を計算する
//                 if (abs(w[i] - w[j]) <= 1 && dp[i + 1][j - 1] == l - 2)
//                 {
//                     dp[i][j] = max(dp[i][j], l);
//                 }

//                 for (int k = i; k < j; ++k)
//                 {
//                     dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
//                 }
//             }
//         }

//         cout << dp[0][n - 1] << endl;
//     }

//     return 0;
// }

// 回答者の回答
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     while (1)
//     {
//         int n;
//         cin >> n;
//         if (n == 0)
//             break;

//         vector<int> w(n + 1);
//         for (int i = 0; i < n; i++)
//             cin >> w[i];

//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//         for (int i = 2; i <= n; i++)
//         {
//             for (int j = 0; j + i <= n; j++)
//             {
//                 for (int k = 1; k < i; k++)
//                 {
//                     dp[j][i] = max(dp[j][i], dp[j][k] + dp[j + k][i - k]);
//                 }
//                 if (dp[j + 1][i - 2] == i - 2 && abs(w[j] - w[j + i - 1]) <= 1)
//                 {
//                     dp[j][i] = i;
//                 }
//             }
//         }
//         cout << dp[0][n] << endl;
//     }
//     return 0;
// }

// 自分で解いたコード
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> w(n);
//     for (int i = 0; i < n; i++)
//         cin >> w[i];

//     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//     for (int l = 1; l <= n; l++)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             int j = i + l - 1;
//             dp[i][j] =
//         }
//     }

//     return 0;
// }