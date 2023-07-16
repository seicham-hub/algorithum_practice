// https://atcoder.jp/contests/abc306/tasks/abc306_f
// 転倒数を数えるには？　何由来かの個数を数えるとき、fenwicktree
// 0712もう一度
// 0714もう一度 ok

/*
7/16やり直し分
*/
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));

    vector<P> b;

    rep(i, n) rep(j, m)
    {
        cin >> a[i][j];
        b.emplace_back(a[i][j], i);
    }

    sort(b.begin(), b.end());

    ll ans = ll(1 + m) * m / 2 * n * (n - 1) / 2;

    fenwick_tree<int> t(n);
    for (auto [_, x] : b)
    {
        t.add(x, 1);
        ans += t.sum(x + 1, n);
    }

    cout << ans << endl;

    return 0;
}

/*
7/14やり直し分
*/

// #include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using namespace std;
// using ll = long long;
// using P = pair<int, int>;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<vector<int>> a(n, vector<int>(m));

//     rep(i, n) rep(j, m)
//     {
//         cin >> a[i][j];
//     }

//     vector<P> b;
//     rep(i, n) rep(j, m)
//     {
//         b.emplace_back(a[i][j], i);
//     }

//     sort(b.begin(), b.end());

//     ll ans = ll((1 + m) * m / 2) * ((n - 1) * n / 2);

//     fenwick_tree<int> t(n);
//     for (auto [_, x] : b)
//     {
//         t.add(x, 1);
//         ans += t.sum(x + 1, n);
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using namespace std;
// using ll = long long;
// using P = pair<int, int>;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>> a(n, vector<int>(m));

//     vector<P> b;
//     rep(i, n) rep(j, m)
//     {
//         cin >> a[i][j];
//         b.emplace_back(a[i][j], i);
//     }

//     sort(b.begin(), b.end());

//     ll ans = ll(((m + 1) * m / 2) * (n * (n - 1) / 2));

//     fenwick_tree<int> t(n);
//     for (auto [_, x] : b)
//     {
//         t.add(x, 1);
//         ans += t.sum(x + 1, n);
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using namespace std;
// using ll = long long;
// using P = pair<int, int>;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     // 後ろに型書いておけば省略可能　c++17移行
//     vector<vector<int>> a(n, vector<int>(m));

//     rep(i, n) rep(j, m) cin >> a[i][j];
//     vector<P> b;
//     rep(i, n) rep(j, m) b.emplace_back(a[i][j], i);
//     sort(b.begin(), b.end());

//     ll ans = ll(((m + 1) * m / 2) * (n * (n - 1) / 2));

//     fenwick_tree<int> t(n);
//     for (auto [_, x] : b)
//     {
//         t.add(x, 1);
//         ans += t.sum(x + 1, n);
//     }
//     cout << ans << endl;

//     return 0;
// }