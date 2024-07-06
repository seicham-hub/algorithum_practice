// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja

// 2024_07_06もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vector<vector<long long>> dp(n, vector<long long>(21, 0));
    dp[1][nums[0]] = 1;

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            if (j - nums[i - 1] >= 0 && j + nums[i - 1] <= 20)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j + nums[i - 1]];
            else if (j - nums[i - 1] >= 0)
                dp[i][j] = dp[i - 1][j - nums[i - 1]];
            else if (j + nums[i - 1] <= 20)
                dp[i][j] = dp[i - 1][j + nums[i - 1]];
            else
                dp[i][j] = 0;
        }
    }

    cout << dp[n - 1][nums[n - 1]] << endl;

    return 0;
}
