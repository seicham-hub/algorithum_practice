// https://atcoder.jp/contests/abc339/tasks/abc339_c

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

    ll minim = 1e9;
    ll start = 0;
    rep(i, n)
    {
        start += a[i];
        minim = min(minim, start);
    }

    if (minim >= 0)
        cout << start << endl;
    else
        cout << abs(minim) + start << endl;

    return 0;
}