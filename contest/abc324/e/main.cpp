// https://atcoder.jp/contests/abc324/tasks/abc324_e
// 0104もう一度
// 0112もう一度
// 0207もう一度 提出で間違った

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int calc(string &s, string &t)
{
    int res = 0;

    int si = 0;
    for (char tc : t)
    {
        while (si < s.size() && s[si] != tc)
            si++;

        if (si == s.size())
            break;
        // siを+しなかった
        si++;
        res++;
    }

    return res;
}

int main()
{
    int n;
    string t;
    cin >> n >> t;

    vector<string> s(n);

    vector<int> l(n), r(n);

    rep(i, n) cin >> s[i];
    ll ans = 0;

    rep(_, 2)
    {
        rep(i, n)
        {
            l[i] = calc(s[i], t);
        }
        swap(l, r);
        reverse(t.begin(), t.end());
        rep(i, n) reverse(s[i].begin(), s[i].end());
    }

    // 〇個以上のrの個数を格納する配列
    // 初期化個数をn+1にしてしまった
    vector<ll> c(t.size() + 1);

    rep(i, n)
    {
        for (int j = r[i]; j >= 0; j--)
            c[j]++;
    }

    rep(i, n)
    {
        ll remain = t.size() - l[i];
        ans += c[remain];
    }

    cout << ans << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int calc(string &s, string &t)
{
    int result = 0;
    int si = 0;
    for (char c : t)
    {
        while (si < s.size() && s[si] != c)
            si++;
        if (si == s.size())
            break;
        si++;
        result++;
    }

    return result;
}

int main()
{
    int n;
    string t;
    cin >> n >> t;

    vector<string> s(n);
    rep(i, n) cin >> s[i];

    ll ans = 0;

    vector<int> l(n), r(n);
    rep(_, 2)
    {
        rep(i, n)
        {
            l[i] = calc(s[i], t);
        }
        swap(l, r);
        rep(i, n) reverse(s[i].begin(), s[i].end());
        reverse(t.begin(), t.end());
    }

    // 部分文字列以上のrの個数を格納するvector
    vector<int> more(t.size() + 1);

    rep(i, n) for (int j = r[i]; j >= 0; j--) more[j]++;

    rep(i, n)
    {
        ans += more[t.size() - l[i]];
    }

    cout << ans << endl;
    return 0;
}

// 0112やり直し分
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// ll calc(const string &s, const string &t)
// {

//     ll g = 0;

//     for (auto c : s)
//     {
//         if (g >= (int)t.size())
//             break;
//         if (c == t[g])
//             g++;
//     }
//     return g;
// }

// int main()
// {
//     int n;
//     string t;
//     cin >> n >> t;

//     ll a[500001], b[500001], c[500001];

//     vector<string> s(n);
//     rep(i, n) cin >> s[i];

//     rep(i, n) a[i] = calc(s[i], t);

//     reverse(t.begin(), t.end());
//     rep(i, n)
//     {
//         reverse(s[i].begin(), s[i].end());
//         b[i] = calc(s[i], t);
//         c[b[i]]++;
//     }

//     ll ans = 0;

//     rep(i, n)
//     {
//         ll l = (int)t.size() - a[i];
//         for (int j = l; j <= t.size(); j++)
//         {
//             ans += c[j];
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

// 自分で書いたコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     string t;
//     cin >> n >> t;

//     vector<string> s(n);
//     vector<int> s_count(n), sr_count(n);

//     rep(i, n) cin >> s[i];

//     rep(i, n)
//     {
//         string sn = s[i];
//         int now = 0;
//         rep(j, sn.size())
//         {
//             if (t[now] == sn[j])
//                 now++;
//         }

//         s_count[i] = now;
//     }

//     rep(i, n) reverse(s[i].begin(), s[i].end());
//     reverse(t.begin(), t.end());

//     rep(i, n)
//     {
//         string sn = s[i];
//         int now = 0;
//         rep(j, sn.size())
//         {
//             if (t[now] == sn[j])
//                 now++;
//         }

//         sr_count[i] = now;
//     }

//     vector<ll> more_than(500001, 0);
//     rep(i, sr_count.size())
//     {
//         for (int j = 0; j <= sr_count[i]; j++)
//         {
//             more_than[j]++;
//         }
//     }

//     ll ans = 0;

//     rep(i, s_count.size())
//     {
//         int back_diff = t.size() - s_count[i];
//         ans += more_than[back_diff];
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// ll n;
// string t;
// ll a[500001], b[500001], c[500001];

// ll calc(const string &s, const string &t)
// {
//     ll g = 0;
//     for (auto c : s)
//     {
//         if (g >= (int)t.size())
//             break;
//         if (c == t[g])
//             g++;
//     }
//     return g;
// }

// int main()
// {

//     cin >> n >> t;
//     vector<string> s(n);

//     rep(i, n) cin >> s[i];

//     rep(i, n)
//         a[i] = calc(s[i], t);

//     reverse(t.begin(), t.end());
//     rep(i, n)
//     {
//         reverse(s[i].begin(), s[i].end());
//         b[i] = calc(s[i], t);
//         c[b[i]]++;
//     }

//     ll ans = 0;
//     rep(i, n)
//     {
//         ll l = (ll)t.size() - a[i];
//         for (int j = l; j <= t.size(); j++)
//         {
//             ans += c[j];
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }