// https://atcoder.jp/contests/abc357/tasks/abc357_c

// わからなかった...
// フラクタル構造は前のものを利用しろ。
// 2024_11_07もう一度
// 2024_12_12もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> g = {"#"};

    rep(i, n)
    {
        int m = g.size();
        int m3 = m * 3;

        vector<string> tmp(m3, string(m3, '.'));

        rep(j, m3) rep(k, m3)
        {
            tmp[j][k] = g[j % m][k % m];
        }

        rep(j, m) rep(k, m)
        {
            tmp[j + m][k + m] = '.';
        }
        g = tmp;
    }

    for (string gi : g)
    {
        cout << gi << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<string> ans = {"#"};

//     for (int i = 1; i <= n; i++)
//     {
//         int before = pow(3, i - 1);
//         int m = pow(3, i);
//         vector<string> tmp(m, string(m, '.'));

//         rep(j, m)
//         {
//             rep(k, m)
//             {
//                 tmp[j][k] = ans[j % before][k % before];
//             }
//         }

//         rep(j, before)
//         {

//             rep(k, before)
//                 tmp[j + before][k + before] = '.';
//         }
//         ans = tmp;
//     }

//     for (string a : ans)
//     {
//         cout << a << endl;
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
//     vector<vector<string>> grid(n + 1);

//     grid[0] = {"#"};

//     for (int i = 1; i <= n; i++)
//     {
//         int before = pow(3, i - 1);
//         int line = pow(3, i);
//         vector<string> now(line, string(line, 's'));
//         grid[i] = now;

//         rep(j, line)
//         {
//             rep(k, line)
//             {
//                 grid[i][j][k] = grid[i - 1][j % before][k % before];
//             }
//         }
//         for (int j = before; j < 2 * before; j++)
//         {
//             for (int k = before; k < 2 * before; k++)
//             {
//                 grid[i][j][k] = '.';
//             }
//         }
//     }

//     auto ans = grid.back();

//     for (string aline : ans)
//     {
//         cout << aline << endl;
//     }

//     return 0;
// }

// お手本コード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<string> g = {"#"};

//     rep(i, n)
//     {
//         int m = g.size();
//         int m3 = m * 3;

//         vector<string> tmp(m3, string(m3, '.'));

//         rep(j, m3) rep(l, m3)
//         {
//             tmp[j][l] = g[j % m][l % m];
//         }

//         rep(j, m) rep(l, m)
//         {
//             tmp[j + m][l + m] = '.';
//         }

//         g = tmp;
//     }

//     rep(i, g.size())
//     {
//         rep(j, g.size())
//         {
//             cout << g[i][j];
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

//     vector<string> s = {"#"};
//     rep(ni, n)
//     {
//         int m = s.size(), m3 = m * 3;

//         vector<string> t(m3, string(m3, '.'));

//         rep(i, m3) rep(j, m3) t[i][j] = s[i % m][j % m];
//         rep(i, m) rep(j, m) t[i + m][j + m] = '.';
//         s = t;
//     }

//     rep(i, s.size())
//     {
//         rep(j, s.size())
//         {
//             cout << s[i][j];
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

//     char c = '#';

//     if (n == 0)
//     {
//         cout << c << endl;
//         return 0;
//     }

//     vector<vector<string>> ans(3, vector<string>(3, ""));

//     vector<string> tmp;
//     rep(i, pow(3, n - 1))
//     {
//         rep(j, pow(3, n - 1))
//         {
//             tmp[i][j] = ' ';
//         }
//     }

//     ans[1][1] = tmp;

//     return 0;
// }