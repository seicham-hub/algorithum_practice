// https://atcoder.jp/contests/abc326/tasks/abc326_c
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);

    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    rep(i, n)
    {

        int ind = lower_bound(a.begin(), a.end(), a[i] + m) - a.begin();
        ans = max(ans, ind - i);
    }

    cout << ans << endl;

    return 0;
}