// https://atcoder.jp/contests/abc325/tasks/abc325_d
// 全く分からなかった
// 0206もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<ll> t(n), d(n);
    rep(i, n) cin >> t[i] >> d[i];

    ll start = 1e18;
    rep(i, n)
    {
        start = min(start, t[i]);
    }

    vector<bool> is_print(n, false);
    for (ll i = start; i)

        return 0;
}