// https://atcoder.jp/contests/abc355/tasks/abc355_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    set<int> ae;

    rep(i, n)
    {
        cin >> a[i];
        ae.insert(a[i]);
    }
    rep(i, m) cin >> b[i];

    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    sort(c.begin(), c.end());

    int ans = 0;

    rep(i, n + m - 1)
    {
        if (ae.count(c[i]) && ae.count(c[i + 1]))
            ans++;
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}