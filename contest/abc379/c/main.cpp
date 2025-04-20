// https://atcoder.jp/contests/abc379/tasks/abc379_c

// 解けなかった...　コードに落とせなかった
// 石は右側にしか移動できない、持ち越すという発想

// 2025_04_02もう一度
// 2025_04_04もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> stones(m + 1);
    stones[0] = {0, 1};

    rep(i, m) cin >> stones[i + 1].first;
    rep(i, m) cin >> stones[i + 1].second;

    stones.emplace_back(n + 1, 1);

    sort(stones.begin(), stones.end());

    ll ans = 0;
    rep(i, stones.size() - 1)
    {
        ll diff = stones[i + 1].first - stones[i].first;
        ll r = stones[i].second - diff;

        if (r < 0)
        {
            cout << -1 << endl;
            return 0;
        }

        ans += (diff - 1) * diff / 2;
        ans += diff * r;

        stones[i + 1].second += r;
    }
    if (stones.back().second > 1)
    {
        cout << -1 << endl;
        return 0;
    }

    cout
        << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<P> stones(m + 1);
//     stones[0] = {0, 1};

//     rep(i, m) cin >> stones[i + 1].first;
//     rep(i, m) cin >> stones[i + 1].second;

//     sort(stones.begin(), stones.end());
//     stones.push_back({n + 1, 1});

//     ll ans = 0;
//     rep(i, stones.size() - 1)
//     {
//         ll L = stones[i + 1].first - stones[i].first;
//         ll C = stones[i].second;

//         if (C < L)
//         {
//             cout << -1 << endl;
//             return 0;
//         }

//         stones[i + 1].second += C - L;

//         ans += L * (L - 1) / 2;
//         ans += (C - L) * L;
//     }

//     if (stones.back().second > 1)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     vector<int> x(m);
//     vector<ll> a(m);

//     rep(i, m) cin >> x[i];
//     rep(i, m) cin >> a[i];

//     ll tmpRem = 0;
//     ll cost = 0;
//     // 番号、個数の順
//     vector<P> mul;
//     vector<int> blank;

//     for (int i = 0; i < m / 2; i += 2)
//     {
//         if (a[i] > 1)
//         {
//             mul.emplace_back(x[i], a[i]);
//             tmpRem += a[i] - 1;
//         }
//         if (a[i + 1] > 1)
//             mul.emplace_back(x[i + 1], a[i + 1]);

//         if (x[i + 1] - x[i] != 1)
//         {

//             if (tmpRem == x[i + 1] - x[i] - 1 && mul.size())
//             {
//                 rep(j, x[i + 1] - x[i] - 1) blank.emplace_back(x[i] + j + 1);

//                 while (blank.size())
//                 {

//                     int bind = blank[0];
//                     auto &[ind, val] = mul[0];

//                     cost += bind - ind;

//                     val--;
//                     blank.erase(blank.begin());
//                     if (val == 1)
//                         mul.erase(mul.begin());
//                 }
//             }
//             else
//             {
//                 cout << -1 << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << cost << endl;

//     return 0;
// }