// https://atcoder.jp/contests/abc304/tasks/abc304_d
// 0609もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    long long w, h;
    int n;
    cin >> w >> h >> n;

    vector<long long> p(n), q(n);

    rep(i, n) cin >> p[i] >> q[i];

    int a;
    cin >> a;
    vector<long long> ai(a);
    rep(i, a) cin >> ai[i];
    int b;
    cin >> b;
    vector<long long> bi(b);
    rep(i, b) cin >> bi[i];

    map<pair<int, int>, int> mp;

    rep(i, n)
    {
        int x = lower_bound(ai.begin(), ai.end(), p[i]) - ai.begin();
        int y = lower_bound(bi.begin(), bi.end(), q[i]) - bi.begin();

        mp[{x, y}]++;
    }

    int m = n, M = 0;
    for (auto e : mp)
    {
        m = min(m, e.second);
        M = max(M, e.second);
    }

    if (mp.size() < (long long)(a + 1) * (b + 1))
        m = 0;

    cout << m << M << endl;

    return 0;
}