// ナップサック問題
// 重さも全探索する必要あり

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, wLimit;
    cin >> n;

    vector<int> w(n), v(n);

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        w[i] = a;
        v[i] = b;
    }
    cin >> wLimit;

    vector<vector<int>> dp(n + 1, vector<int>(0));

    for (int wi = 0; wi <= wLimit; wi++)
        dp[0][wi] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int wi = 0; wi <= wLimit; wi++)
        {
            // wi - w[i]が0以上の時
            if (wi >= w[i])
                dp[i + 1][wi] = max(dp[i][wi - w[i]] + v[i], dp[i][wi]);
            else
                dp[i + 1][wi] = dp[i + 1][wi];
        }
    }

    cout << dp[n][wLimit] << endl;
    return 0;
}
