// https://atcoder.jp/contests/abc006/tasks/abc006_4
// 分からなかった.. 昇順になるように残すものの最大値をとる

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int max = c[1];

    vector<int> dp(n + 1);

    for (int i = 2; i <= n; i++)
    {
        if (max > c[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = dp[i - 1];
            max = c[i];
        }
    }

    cout << dp[n] << endl;
}