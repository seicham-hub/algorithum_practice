// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=ja

// 2024_07_01もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;

    vector<int> value(n), weight(n);

    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> value[i] >> weight[i];
    }

    // dp[i][w] i番目の品物までの品物を使って、容量w以下のナップザックに入れたときの価値の最大値
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; ++j)
        {
            if (j - weight[i] >= 0)
                dp[i + 1][j] = max(dp[i][j], dp[i][j - weight[i]] + value[i]);
            else
                dp[i + 1][j] = dp[i][j];
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}