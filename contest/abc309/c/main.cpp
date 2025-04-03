// https://atcoder.jp/contests/abc309/tasks/abc309_c

// 間違えた...
// 2025_03_24もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<P> ab(n);

    ll tot = 0;

    rep(i, n)
    {
        cin >> ab[i].first >> ab[i].second;
        tot += ab[i].second;
    }

    sort(ab.begin(), ab.end());

    if (tot <= k)
    {
        cout << 1 << endl;
        return 0;
    }

    for (auto [a, b] : ab)
    {
        tot -= b;

        if (tot <= k)
        {
            cout << a + 1 << endl;
            return 0;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// int main()
// {
//     int n;
//     ll k;
//     cin >> n >> k;

//     map<ll, ll> delta; // 服薬量の差分

//     for (int i = 0; i < n; ++i)
//     {
//         ll a, b;
//         cin >> a >> b;
//         delta[1] += b;     // 1日目から b 錠増える
//         delta[a + 1] -= b; // a+1日目から b 錠減る
//     }

//     ll current = 0; // 現在の服薬量
//     for (auto &[day, diff] : delta)
//     {
//         current += diff;
//         if (current <= k)
//         {
//             cout << day << "\n";
//             return 0;
//         }
//     }

//     return 0; // 万一ここに来ることはない（必ず条件を満たす日は来る）
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;
// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     ll total = 0;
//     vector<P> medi(n);
//     rep(i, n)
//     {
//         cin >> medi[i].first >> medi[i].second;

//         total += medi[i].second;
//     }

//     vector<ll> rui(n + 1);
//     rui[0] = total;
//     sort(medi.begin(), medi.end());

//     rep(i, n) rui[i + 1] = rui[i] - medi[i].second;

//     rep(i, n + 1)
//     {
//         if (rui[i] <= k)
//         {
//             if (i == 0)
//                 cout << 1 << endl;
//             else
//                 cout << medi[i - 1].first + 1 << endl;

//             return 0;
//         }
//     }

//     return 0;
// }