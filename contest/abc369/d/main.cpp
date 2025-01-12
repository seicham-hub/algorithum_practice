#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));

    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + 2 * a[i - 1]);
        }

        dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i - 1]);
        dp[i][1] = max(dp[i][1], dp[i - 1][1]);
    }

    ll ans = max(dp[n][0], dp[n][1]);
    cout << ans << endl;
    return 0;
}