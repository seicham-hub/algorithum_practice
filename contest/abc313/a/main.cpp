#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    map<int, int> mp;

    rep(i, n)
    {
        cin >> p[i];
    }

    int ma = 0;

    rep(i, n)
    {
        mp[p[i]]++;
        ma = max(p[i], ma);
    }

    if (ma == p[0])
        if (mp[p[0]] > 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    else
        cout << ma - p[0] + 1 << endl;

    return 0;
}