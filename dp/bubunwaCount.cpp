#include <bits/stdc++.h>
using namespace std;

const int MOD = ~1000000009;
int n, A;
int a[110];

int dp[110][10010];

int main()
{
    // dp[i+1][j] ll i番目の数の中でいくつか選び、総和がjとなる場合の数
    cin >> n >> A;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp)); // いったん全て0に
    dp[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            (dp[i + 1][j] += dp[i][j]) % MOD;
            if (j >= a[i])
                (dp[i + 1][j] += dp[i][j - a[i]]) % MOD;
        }
    }

    cout << dp[n][A] << endl;

    return 0;
}
