#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];

    vector<vector<int>> mp(1e6 + 1, vector<int>());

    rep(i, n)
    {

        mp[a[i]].push_back(i);
    }

    int ans = 2e6;
    rep(i, mp.size())
    {
        rep(j, mp[i].size())
        {
            if (j == 0)
                continue;
            ans = min(ans, mp[i][j] - mp[i][j - 1] + 1);
        }
    }

    if (ans == 2e6)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}