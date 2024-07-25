// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2199&lang=jp

// 2024_07_22もう一度
// 2024_07_23もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    while (true)
    {

        int n, m;
        cin >> n >> m;

        if (!n && !m)
            break;

        vector<int> c(m);
        for (int i = 0; i < m; i++)
            cin >> c[i];

        vector<int> x(n);
        for (int i = 0; i < n; i++)
            cin >> x[i];

        vector<vector<int>> dp(n + 1, vector<int>(256, INT_MAX));
        dp[0][128] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int y = 0; y <= 255; y++)
            {
                for (int ci : c)
                {
                    if (dp[i - 1][y] == INT_MAX)
                        continue;
                    int ny = y + ci;
                    ny = ny > 255 ? 255 : ny;
                    ny = ny < 0 ? 0 : ny;
                    dp[i][ny] = min(dp[i][ny], dp[i - 1][y] + (ny - x[i - 1]) * (ny - x[i - 1]));
                }
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i <= 255; i++)
            ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     while (true)
//     {
//         int n, m;
//         cin >> n >> m;

//         if (!n && !m)
//             break;

//         vector<int> code_book(m);

//         for (int i = 0; i < m; i++)
//             cin >> code_book[i];

//         vector<int> x(n + 1);
//         for (int i = 1; i <= n; i++)
//             cin >> x[i];

//         vector<vector<int>> dp(n + 1, vector<int>(256, INT_MAX));
//         dp[0][128] = 0;

//         for (int i = 1; i <= n; i++)
//         {
//             for (int y = 0; y <= 255; y++)
//             {
//                 if (dp[i - 1][y] != INT_MAX)
//                 {
//                     for (int cb : code_book)
//                     {
//                         int ny = y + cb;

//                         if (ny < 0)
//                             ny = 0;
//                         if (ny > 255)
//                             ny = 255;

//                         dp[i][ny] = min(dp[i][ny], dp[i - 1][y] + (x[i] - ny) * (x[i] - ny));
//                     }
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         for (int i = 0; i <= 255; i++)
//             ans = min(ans, dp[n][i]);

//         cout << ans << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N, M;

//     while (cin >> N >> M, N || M)
//     {
//         vector<int> C(M);
//         for (int i = 0; i < M; i++)
//         {
//             cin >> C[i];
//         }

//         vector<int> x(N);
//         for (int i = 0; i < N; i++)
//         {
//             cin >> x[i];
//         }

//         const int INF = 1e9;
//         vector<vector<int>> dp(N + 1, vector<int>(256, INF));
//         dp[0][128] = 0; // y0 = 128

//         for (int i = 0; i < N; i++)
//         {
//             for (int y = 0; y < 256; y++)
//             {
//                 if (dp[i][y] == INF)
//                     continue;
//                 for (int j = 0; j < M; j++)
//                 {
//                     int ny = y + C[j];
//                     if (ny < 0)
//                         ny = 0;
//                     if (ny > 255)
//                         ny = 255;
//                     dp[i + 1][ny] = min(dp[i + 1][ny], dp[i][y] + (ny - x[i]) * (ny - x[i]));
//                 }
//             }
//         }

//         int ans = INF;
//         for (int y = 0; y < 256; y++)
//         {
//             ans = min(ans, dp[N][y]);
//         }
//         cout << ans << endl;
//     }

//     return 0;
// }

// 自分で書いたコード
// 分からなかった

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> code_book(n + 1);

//     for (int i = 1; i <= m; i++)
//         cin >> code_book[i];

//     return 0;
// }