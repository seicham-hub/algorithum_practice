// https://atcoder.jp/contests/abc330/tasks/abc330_c

// WAとなった...(制約読み取りミス)

// 2025_02_24もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll d;
    cin >> d;

    ll ans = d;
    ll y = 2e6;
    for (ll x = 0; x <= 2e6; x++)
    {
        while (y > 0 && x * x + y * y > d)
        {
            y--;
        }

        ans = min(ans, abs(x * x + y * y - d));
        ans = min(ans, abs(x * x + (y + 1) * (y + 1) - d));
    }

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     ll d;
//     cin >> d;

//     vector<ll> cand;

//     ll lastX = 0;
//     for (ll i = 0; i * i <= d; i++)
//     {
//         cand.push_back(i * i);
//         lastX = i;
//     }
//     lastX++;
//     cand.push_back(lastX * lastX);

//     ll ans = 3 * 1e12;

//     rep(i, cand.size())
//     {
//         ll reft = cand[i] - d;
//         ll y;
//         if (reft > 0)
//         {
//             y = 0;
//             ans = min(ans, reft + y);
//         }

//         else
//         {
//             reft = abs(reft);
//             // ll y = sqrt(reft);

//             // ans = min(ans, abs(reft - (ll)pow(y, 2)));
//             // ans = min(ans, abs(reft - (ll)pow(y + 1, 2)));
//             int ind = lower_bound(cand.begin(), cand.end(), reft) - cand.begin();

//             y = cand[ind];
//             ans = min(ans, abs(reft - y));
//             if (ind > 0)
//                 ans = min(ans, abs(reft - cand[ind - 1]));
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }