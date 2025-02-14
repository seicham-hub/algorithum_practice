// https://atcoder.jp/contests/abc338/tasks/abc338_c

// 2025_02_13もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

void input(int n, vector<int> &vec)
{
    rep(i, n) cin >> vec[i];
}

int main()
{
    int n;
    cin >> n;
    vector<int> q(n), a(n), b(n);

    input(n, q);
    input(n, a);
    input(n, b);

    ll ans = 0;
    rep(i, 1e6 + 1)
    {

        ll tmp = 1e6;
        bool isCook = true;
        rep(j, n)
        {
            ll reft = q[j] - (ll)a[j] * i;

            if (reft < 0)
            {
                isCook = false;
                break;
            }
            if (b[j] == 0)
                continue;
            ll cnt = reft / b[j];

            tmp = min(tmp, cnt);
        }

        if (isCook)
            ans = max(ans, i + tmp);
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
//     int n;
//     cin >> n;

//     vector<int> q(n), a(n), b(n);

//     rep(i, n) cin >> q[i];
//     rep(i, n) cin >> a[i];
//     rep(i, n) cin >> b[i];

//     ll ans = 0;
//     rep(i, 1e6 + 1)
//     {

//         ll minb = 1e6;
//         int isCook = true;

//         rep(j, n)
//         {
//             ll reft = q[j] - ((ll)a[j] * i);

//             if (reft < 0)
//             {
//                 isCook = false;
//                 break;
//             }

//             if (b[j] == 0)
//                 continue;

//             minb = min(minb, reft / b[j]);
//         }

//         if (isCook)
//             ans = max(ans, i + minb);
//     }

//     cout << ans << endl;

//     return 0;
// }