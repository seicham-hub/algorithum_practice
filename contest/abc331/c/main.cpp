// https://atcoder.jp/contests/abc331/tasks/abc331_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<ll> rui(n + 1, 0);

    rep(i, n)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(a.begin(), a.end());

    rep(i, n)
        rui[i + 1] = rui[i] + a[i];

    rep(i, n)
    {
        int ind = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << rui[n] - rui[ind] << " ";
    }
    return 0;
}