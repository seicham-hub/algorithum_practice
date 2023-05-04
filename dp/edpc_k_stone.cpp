// https://atcoder.jp/contests/dp/tasks/dp_k
// 0504もう一度

#include <iostream>
#include <vector>

using namespace std;

bool dp[110000];

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // DP dp[i]は残りの石がi個のときの局面の勝敗
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] |= !dp[i - a[j]];
        }
    }

    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}