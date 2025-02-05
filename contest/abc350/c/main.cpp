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

    map<int, int> mp;

    rep(i, n)
    {
        cin >> a[i];
        a[i]--;
        mp[a[i]] = i;
    }

    vector<P> ans;

    rep(i, n)
    {
        int ind = mp[i];

        if (a[i] != i)
        {
            swap(mp[i], mp[a[i]]);
            swap(a[i], a[ind]);

            ans.emplace_back(i + 1, ind + 1);
        }
    }

    cout << ans.size() << endl;
    for (auto ansi : ans)
    {
        cout << ansi.first << " " << ansi.second << endl;
    }

    return 0;
}