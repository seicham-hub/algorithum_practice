// https://atcoder.jp/contests/abc380/tasks/abc380_d
// 分からなかった...

// 2024_11_20もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

ll f(ll l, ll r, ll target)
{

    if (abs(l - r) == 1)
        return 0;

    ll mid = (l + r) / 2;

    if (mid <= target)
        return f(mid, r, target) + 1;
    else
        return f(l, mid, target);
}

char flip(char c)
{
    if (islower(c))
        return toupper(c);
    else
        return tolower(c);
}

int main()
{
    string s;
    cin >> s;
    int q;
    cin >> q;

    int n = s.size();
    rep(i, q)
    {
        ll k;
        cin >> k;
        k--;

        ll ind = k % n;
        ll t = k / n;

        ll cnt = f(0, 1LL << 60, t);

        if (cnt % 2 == 0)
            cout << s[ind] << ' ';
        else
            cout << flip(s[ind]) << ' ';
    }

    cout << endl;

    return 0;
}

// 解答のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int f(ll l, ll r, ll k)
// {
//     if (abs(l - r) == 1)
//         return 0;

//     ll c = (l + r) / 2;
//     if (k < c)
//         return f(l, c, k);
//     else
//         return f(c, r, k) + 1;
// }

// char flip(char c)
// {
//     if (islower(c))
//         return c - 'a' + 'A';
//     return c - 'A' + 'a';
// }

// int main()
// {

//     string s;
//     cin >> s;

//     int n = s.size();
//     int q;
//     cin >> q;

//     rep(qi, q)
//     {
//         ll k;
//         cin >> k;
//         k--;
//         int si = k % n;
//         k /= n;
//         int cnt = f(0, 1LL << 60, k);
//         char ans = s[si];
//         if (cnt % 2)
//             ans = flip(ans);
//         cout << ans << ' ';
//     }
//     cout << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     string s;
//     cin >> s;
//     int n = s.size();
//     int q;
//     cin >> q;

//     string ura;

//     for (char c : s)
//     {
//         if (islower(c))
//             ura += toupper(c);
//         if (isupper(c))
//             ura += tolower(c);
//     }

//     vector<ll> k(q);
//     rep(i, q)
//     {
//         cin >> k[i];
//         k[i]--;
//     }

//     rep(i, q)
//     {
//         int check = (k[i] / n) % 2;
//         if (!check)
//             cout << s[k[i] % n] << " ";
//         else
//             cout << ura[k[i] % n] << " ";
//     }

//     return 0;
// }