#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    rep(i, m) cin >> a[i];

    vector<vector<int>> x(n, vector<int>(m));

    rep(i, n) rep(j, m)
    {
        cin >> x[i][j];
    }

    vector<int> ob(m, 0);
    rep(i, n) rep(j, m)
    {
        ob[j] += x[i][j];
    }

    bool ok = true;
    rep(i, m)
    {
        if (ob[i] < a[i])
            ok = false;
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}