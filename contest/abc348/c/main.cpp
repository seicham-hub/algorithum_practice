#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), c(n);

    map<int, int> mp;

    rep(i, n)
    {
        cin >> a[i] >> c[i];

        if (!mp.count(c[i]))
            mp[c[i]] = 1e9;

        mp[c[i]] = min(mp[c[i]], a[i]);
    }

    int ans = 0;

    for (auto mpi : mp)
    {

        if (ans <= mpi.second)
        {
            ans = mpi.second;
        }
    }

    cout << ans << endl;

    return 0;
}