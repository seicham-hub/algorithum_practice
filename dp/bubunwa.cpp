#include <bits/stdc++.h>
using namespace std;

int main()
{
    // dp[i+1][j] bool  i番目までの整数からいくつか選んで総和をjとする事ができるか？
    int n, A;
    int a[110];

    bool dp[110][10010];
    cin >> n >> A;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, 0, sizeof(dp)); // いったん全てfalseに
    dp[0][0] = true;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= A; j++)
        {
            dp[i + 1][j] |= dp[i][j];
            if (j >= a[i])
                dp[i + 1][j] |= dp[i][j - a[i]];
        }
    }
    if (dp[n][A])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
