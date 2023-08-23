// https://atcoder.jp/contests/abc315/tasks/abc315_c
// DPで解けるかと思ったけど... 情報が三つ必要で時間内に間に合わない
// 基本美味しさがでかいやつから選べばよいが

// 0823もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> bk(n + 1);

    rep(i, n)
    {
        int f, s;
        cin >> f >> s;
        bk[f].push_back(s);
    }

    int res = 0;
    vector<int> best;

    for (int i = 1; i <= n; i++)
    {
        sort(bk[i].begin(), bk[i].end());
        reverse(bk[i].begin(), bk[i].end());

        if (bk[i].size() >= 2)
        {
            res = max(res, bk[i][0] + bk[i][1] / 2);
        }
        if (bk[i].size() >= 1)
        {
            best.push_back(bk[i][0]);
        }
    }

    sort(best.begin(), best.end());
    reverse(best.begin(), best.end());

    if (best.size() >= 2)
        res = max(res, best[0] + best[1]);

    cout << res << endl;

    return 0;
}

/*
自分で解いたコード
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> f(n), s(n);

//     rep(i, n)
//     {
//         cin >> f[i] >> s[i];
//     }

//     // dp[i+1][j+1] i個まで選び、前に選んだ味がjだった時の満足度の最大値

//     vector<vector<int>> dp(3, vector<int>(n + 1, -1));

//     dp[0][0] = 0;

//     rep(i, n + 1)
//     {
//         rep(j, 3)
//         {
//             dp[i + 1][j + 1] = max(dp[i][j] + s[i], dp[i + 1][j + 1])
//         }
//     }

//     int ans = 0;

//     rep(i, n + 1)
//     {
//         ans = max(ans, dp[n][i]);
//     }

//     cout << ans << endl;

//     return 0;
// }