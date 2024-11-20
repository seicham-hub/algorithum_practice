// https://atcoder.jp/contests/abc353/tasks/abc353_c

// 分からなかった...
// 2024_11_17もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    const int M = 1e8;
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;

    rep(i, n) ans += (ll)a[i] * (n - 1);
    int cnt = 0;
    rep(i, n)
    {
        auto ind = upper_bound(a.begin(), a.end(), M - a[i]) - a.begin();
        ind--;

        cnt += n - 1 - ind;
    }

    ans -= (ll)cnt * M;

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int f(int x, int y)
// {
//     return (x + y) % 100000000;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     return 0;
// }