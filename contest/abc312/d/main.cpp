// https://atcoder.jp/contests/abc312/tasks/abc312_d
// 分からなかった　dpという発想はどこから？→法則が分かりにくいから、前の状態から考えよう
// モジュロ演算　(A+B)%C = (A%C+B%C)%C 剰余定理で証明可

// 0730もう一度
// 0801もう一度
// 0802もう一度 ok

/*
8/3やり直し分
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    // dp[i][j] i:何番目？　j:(-)の数　値：何通りあるか
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));

    dp[0][0] = 1;

    rep(i, n)
    {
        rep(j, n)
        {
            if (s[i] != ')')
                dp[i + 1][j + 1] += dp[i][j] % 998244353;
            if (j != 0 && s[i] != '(')
                dp[i + 1][j - 1] += dp[i][j] % 998244353;
        }
    }

    cout << dp[n][0] % 998244353 << endl;

    return 0;
}

/*
8/2やり直し分
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     string s;
//     cin >> s;

//     int n = s.size();

//     // dp[i][j] i番目（1番から）　j:( - ) の個数  これが何通りあるか
//     vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
//     dp[0][0] = 1;

//     rep(i, n)
//     {
//         rep(j, n)
//         {

//             if (s[i] != ')')
//                 dp[i + 1][j + 1] += dp[i][j] % 998244353;

//             if (j != 0 && s[i] != '(')
//                 dp[i + 1][j - 1] += dp[i][j] % 998244353;
//         }
//     }

//     cout << dp[n][0] % 998244353 << endl;

//     return 0;
// }

/*
8/1やり直し分
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     string s;
//     cin >> s;

//     int n = s.size();

//     // dp[i][j]  i番目　j :( - ) の数
//     vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

//     dp[0][0] = 1;

//     rep(i, n)
//     {
//         rep(j, n)
//         {

//             if (s[i] != ')')
//                 dp[i + 1][j + 1] += dp[i][j] % 998244353;

//             if (j != 0 && s[i] != '(')
//                 dp[i + 1][j - 1] += dp[i][j] % 998244353;
//         }
//     }

//     cout << dp[n][0] % 998244353 << endl;

//     return 0;
// }

/*
解答のコード
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     string s;
//     cin >> s;
//     int n = s.size();

//     vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
//     dp[0][0] = 1;

//     rep(i, n)
//     {
//         rep(j, n)
//         {
//             if (s[i] != ')')
//                 dp[i + 1][j + 1] += dp[i][j] % 998244353;
//             if (j != 0 && s[i] != '(')
//                 dp[i + 1][j - 1] += dp[i][j] % 998244353;
//         }
//     }

//     cout << (long long)(dp[n][0] % 998244353) << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// long long ans = 0;

// void dfs(int i, string s)
// {

//     if (i == s.size() - 1)
//     {
//     }

//     if (s[i] == '?')
//     {
//         s[i] = ')';
//         dfs(i + 1, s);
//         s[i] = '(';
//         dfs(i + 1, s);

//         s[i] = '?';
//     }
// }

// int main()
// {

//     string s;

//     cin >> s;

//     dfs(0, s);

//     return 0;
// }