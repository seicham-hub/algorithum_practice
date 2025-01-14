#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);

    rep(i, n)
    {
        cin >> a[i] >> b[i];

        c[i] = b[i] - a[i];
    }

    vector<int> indices;
    rep(i, n) indices.push_back(i);

    sort(indices.begin(), indices.end(), [&](int x, int y)
         { return c[x] > c[y]; });

    ll base = 0;
    rep(i, n) base += a[i];

    cout << base + c[indices[0]] << endl;

    return 0;
}