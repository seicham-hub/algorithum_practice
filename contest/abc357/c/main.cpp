// https://atcoder.jp/contests/abc357/tasks/abc357_c

// わからなかった...
// フラクタル構造は前のものを利用しろ。
// 2024_11_07もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> s = {"#"};
    rep(ni, n)
    {
        int m = s.size(), m3 = m * 3;

        vector<string> t(m3, string(m3, '.'));

        rep(i, m3) rep(j, m3) t[i][j] = s[i % m][j % m];
        rep(i, m) rep(j, m) t[i + m][j + m] = '.';
        s = t;
    }

    rep(i, s.size())
    {
        rep(j, s.size())
        {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}

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