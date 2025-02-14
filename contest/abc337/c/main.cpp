// https://atcoder.jp/contests/abc337/tasks/abc337_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;

    unordered_map<int, int> mp;

    rep(i, n)
    {
        int a;
        cin >> a;

        mp[a] = i + 1;
    }

    int cnt = 0;
    int next = -1;

    vector<int> ans;
    while (cnt <= n)
    {
        ans.push_back(mp[next]);

        next = mp[next];
        cnt++;
    }

    rep(i, n) cout << ans[i] << " ";

    return 0;
}