// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp;

    for (int ai : a)
    {
        auto it = lower_bound(dp.begin(), dp.end(), ai);

        if (it == dp.end())
            dp.push_back(ai);
        else
        {
            // dp[it - dp.begin()] = ai;
            *it = ai;
        }
    }

    cout << dp.size() << endl;

    return 0;
}