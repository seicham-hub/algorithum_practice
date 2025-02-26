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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    const int M = 1000005;
    vector<vector<int>> is(M);
    rep(i, n) is[a[i]].push_back(i);

    vector<ll> ans(n);

    ll now = 0;
    for (int x = M - 1; x >= 1; x--)
    {
        for (int i : is[x])
            ans[i] = now;
        now += (ll)x * is[x].size();
    }

    rep(i, n) cout << ans[i] << " ";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n;
//     cin >> n;
//     vector<int> a(n), b(n);
//     vector<ll> rui(n + 1, 0);

//     rep(i, n)
//     {
//         cin >> a[i];
//         b[i] = a[i];
//     }

//     sort(a.begin(), a.end());

//     rep(i, n)
//         rui[i + 1] = rui[i] + a[i];

//     rep(i, n)
//     {
//         int ind = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
//         cout << rui[n] - rui[ind] << " ";
//     }
//     return 0;
// }