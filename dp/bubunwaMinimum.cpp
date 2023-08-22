#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 29; // 十分大きい値にする、INT_MAXにしないのはオーバーフロー対策

int n, A;
int a[110];

// DPテーブル
int dp[110][10010];

int main()
{

    cin >> n >> A;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // いったんすべてINFに
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 10010; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= A; j++)
        {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (j >= a[i])
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - a[i]] + 1);
        }
    }

    if (dp[n][A] < INF)
        cout << dp[n][A] << endl;
    else
        cout << -1 << endl;

    return 0;
}
