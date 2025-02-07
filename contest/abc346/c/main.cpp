// https://atcoder.jp/contests/abc346/tasks/abc346_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);

    rep(i, n) cin >> a[i];

    ll all = 0;
    rep(i, k) all += i + 1;

    sort(a.begin(), a.end());

    int cnt = upper_bound(a.begin(), a.end(), k) - a.begin();

    set<int> st;
    rep(i, cnt)
        st.insert(a[i]);

    for (int s : st)
        all -= s;

    cout << all << endl;

    return 0;
}