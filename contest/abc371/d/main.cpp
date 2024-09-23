// https://atcoder.jp/contests/abc371/tasks/abc371_d

// 一応解けた

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> x(n), p(n);

    rep(i, n) cin >> x[i];
    rep(i, n) cin >> p[i];

    vector<ll> s(n + 1);

    rep(i, n) s[i + 1] = s[i] + p[i];

    int q;
    cin >> q;

    auto f = [&](int r)
    {
        int pos = upper_bound(x.begin(), x.end(), r) - x.begin();

        return s[pos];
    };

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;

        cout << f(r) - f(l - 1) << '\n';
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> x(n);
//     vector<int> p(n);
//     rep(i, n) cin >> x[i];
//     rep(i, n) cin >> p[i];

//     int q;
//     cin >> q;

//     vector<int> l(q), r(q);
//     rep(i, q) cin >> l[i] >> r[i];

//     vector<ll> rui(n, 0);
//     rui[0] = p[0];

//     for (int i = 1; i < n; i++)
//     {
//         rui[i] += rui[i - 1] + p[i];
//     }

//     rep(i, q)
//     {
//         ll ans = 0;
//         auto it_l = lower_bound(x.begin(), x.end(), l[i]);
//         it_l--;
//         int ind_l = it_l - x.begin();

//         auto it_r = upper_bound(x.begin(), x.end(), r[i]);
//         it_r--;
//         int ind_r = it_r - x.begin();

//         if (ind_r >= 0)
//             ans = rui[ind_r];
//         if (ind_l >= 0)
//             ans -= rui[ind_l];
//         cout << ans << endl;
//     }

//     return 0;
// }