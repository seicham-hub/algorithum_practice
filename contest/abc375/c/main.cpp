// https://atcoder.jp/contests/abc375/tasks/abc375_c
// 分からなかった
// 2024_10_14もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);

    rep(i, n) cin >> a[i];

    vector<string> b = a;

    rep(i, n) rep(j, n)
    {
        int ni = i, nj = j;

        // 枠の番号計算
        int k = min({ni + 1, nj + 1, n - ni, n - nj});

        rep(ki, k)
        {
            swap(ni, nj);
            nj = n - 1 - nj;
        }
        b[ni][nj] = a[i][j];
    }

    rep(i, n) cout << b[i] << '\n';
    return 0;
}

// 方針聞いて実装してみたがダメだった
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<char>> grid(n, vector<char>(n)), ans_grid(n, vector<char>(n));

//     rep(i, n)
//     {
//         rep(j, n)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     ans_grid = grid;

//     auto rotate_grid = [&](int count, int i, int j)
//     {
//         vector<vector<char>> tmp_grid = grid;
//         vector<vector<char>> next_grid = grid;
//         rep(l, count)
//         {
//             next_grid[j][n - 1 - i] = tmp_grid[i][j];
//             tmp_grid = next_grid;

//             if (l == count - 1)
//                 ans_grid[j][n - 1 - i] = tmp_grid[i][j];
//         }
//     };

//     rep(i, n / 2)
//     {
//         for (int j = i; j < n - i; j++)
//         {
//             for (int k = i; k < n - i; k++)
//             {
//                 if (j == i || j == n - 1 - i)
//                 {
//                     rotate_grid((i + 1) % 4, j, k);
//                 }
//                 if (k == i || k == n - 1 - i)
//                 {
//                     rotate_grid((i + 1) % 4, j, k);
//                 }
//             }
//         }
//     }

//     rep(i, n)
//     {
//         rep(j, n)
//         {
//             cout << ans_grid[i][j];
//         }
//         cout << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n;
//     cin >> n;

//     vector<vector<char>> grid(n + 1, vector<char>(n + 1));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     for (int i = 1; i <= n / 2; i++)
//     {
//         vector<vector<char>> tmp_grid = grid;
//         for (int x = i; x <= n + 1 - i; x++)
//         {
//             for (int y = i; y <= n + 1 - i; y++)
//             {
//                 tmp_grid[y][n + 1 - x] = grid[x][y];
//             }
//         }

//         grid = tmp_grid;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= n; j++)
//         {
//             cout << grid[i][j];
//         }
//         cout << endl;
//     }

//     return 0;
// }