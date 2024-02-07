// https://atcoder.jp/contests/abc325/tasks/abc325_d
// 全く分からなかった
// 0206もう一度

// 解答のコード
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;
using P = pair<ll, ll>;

int main()
{
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i, n)
    {
        ll t, d;
        cin >> t >> d;
        a[i] = P(t, t + d);
    }

    sort(a.begin(), a.end());

    int ans = 0;
    ll t = 0;
    int ai = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;

    while (ai < n || q.empty())
    {
        // 現在見ている時刻以下の物をqueueに追加
        while (ai < n && a[ai].first <= t)
        {
            q.push(a[ai].second);
            ai++;
        }

        // 現在見ている時刻未満で終了するものは除く
        while (!q.empty() && q.top() < t)
            q.pop();

        if (!q.empty())
            ans++, q.pop();

        // スキップの実装
        if (q.empty() && ai < n)
            t = a[ai].first;
        t++;
    }

    cout << ans << endl;

    return 0;
}

// 自分のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// using ll = long long;
// using p = pair<ll, ll>;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<ll> t(n), d(n);
//     rep(i, n) cin >> t[i] >> d[i];

//     ll start = 1e18;
//     rep(i, n)
//     {
//         start = min(start, t[i]);
//     }

//     vector<bool> is_print(n, false);
//     for (ll i = start; i)

//         return 0;
// }