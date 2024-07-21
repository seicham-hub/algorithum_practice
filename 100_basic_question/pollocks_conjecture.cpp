// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp
// 2024_07_21もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> t_even, t_odd;
    for (int i = 1; i <= 200; i++)
    {
        int t = (i * (i + 1) * (i + 2)) / 6;

        t_even.push_back(t);
        if (t % 2 != 0)
            t_odd.push_back(t);
    }

    auto create_dp = [&](vector<int> &dp, vector<int> &t_s)
    {
        dp[0] = 0;

        for (int t : t_s)
        {
            for (int j = t; j <= 1e6; j++)
            {
                dp[j] = min(dp[j], dp[j - t] + 1);
            }
        }
    };

    vector<int> dp_even(vector<int>(1e6 + 1, 1e6));
    vector<int> dp_odd(vector<int>(1e6 + 1, 1e6));

    create_dp(dp_even, t_even);
    create_dp(dp_odd, t_odd);

    while (true)
    {
        int num;
        cin >> num;
        if (!num)
            break;

        cout << dp_even[num] << " " << dp_odd[num] << endl;
    }

    return 0;
}