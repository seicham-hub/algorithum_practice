// https://atcoder.jp/contests/abc340/tasks/abc340_c
// 解けたが、書き方が冗長だった

// 2025_02_12もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

unordered_map<ll, ll> memo;
ll f(ll x)
{
    if (x == 1)
        return 0;

    if (memo.count(x))
        return memo[x];

    ll res = f(x / 2) + f(x - x / 2) + x;
    return memo[x] = res;
}

int main()
{
    ll n;
    cin >> n;

    cout << f(n) << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     ll n;

//     cin >> n;

//     unordered_map<ll, ll> xSum;

//     auto dfs = [&](auto dfs, ll now) -> ll
//     {
//         if (xSum.count(now))
//         {
//             return xSum[now];
//         }

//         if (now < 2)
//         {
//             return 0;
//         }

//         ll div = now / 2;

//         if (now % 2 == 0)
//         {
//             ll sum1 = dfs(dfs, div);
//             ll sum2 = dfs(dfs, div);

//             xSum[now] = sum1 + sum2 + now;
//         }
//         else
//         {
//             ll sum1 = dfs(dfs, div);
//             ll sum2 = dfs(dfs, div + 1);

//             xSum[now] = sum1 + sum2 + now;
//         }

//         return xSum[now];
//     };

//     dfs(dfs, n);

//     cout << xSum[n] << endl;

//     return 0;
// }