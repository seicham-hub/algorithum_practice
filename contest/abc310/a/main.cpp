#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> d(n);
    rep(i, n) cin >> d[i];

    int mind = 1e9;

    rep(i, n)
    {
        mind = min(mind, d[i]);
    }

    if (q + mind < p)
    {
        cout << q + mind << endl;
    }
    else
    {
        cout << p << endl;
    }

    return 0;
}