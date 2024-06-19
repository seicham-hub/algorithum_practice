// https://atcoder.jp/contests/abc023/tasks/abc023_d
// 2024_06_19もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long ans = 0;

    cin >> n;

    vector<pair<int, int>> hs(n);

    for (int i = 0; i < n; i++)
    {
        cin >> hs[i].first >> hs[i].second;
    }

    auto compare = [](const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    };

    sort(hs.begin(), hs.end(), compare);

    for (int i = 0; i < n; i++)
    {
    }

    cout << ans << endl;
    return 0;
}