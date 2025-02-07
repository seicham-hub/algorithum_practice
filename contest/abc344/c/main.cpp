// https://atcoder.jp/contests/abc344/tasks/abc344_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, l, m;
    cin >> n;
    vector<ll> a(n);

    rep(i, n) cin >> a[i];

    cin >> m;
    vector<ll> b(m);
    rep(i, m) cin >> b[i];

    cin >> l;
    vector<ll> c(l);
    rep(i, l) cin >> c[i];

    int q;
    cin >> q;

    vector<ll> x(q);
    rep(i, q) cin >> x[i];

    set<ll> st;

    rep(i, n) rep(j, m) rep(k, l)
    {
        st.insert(a[i] + b[j] + c[k]);
    }

    rep(i, q)
    {
        auto it = st.find(x[i]);
        if (it != st.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}