
// https://atcoder.jp/contests/abc308/tasks/abc308_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> c(n);
    rep(i, n) cin >> c[i];

    vector<string> d(m);
    rep(i, m) cin >> d[i];

    vector<int> p(m + 1);
    rep(i, m + 1) cin >> p[i];

    map<string, int> mp;

    rep(i, m)
    {
        mp[d[i]] = p[i + 1];
    }

    int ans = 0;

    rep(i, n)
    {

        if (mp[c[i]] == false)
        {
            ans += p[0];
            continue;
        }

        ans += mp[c[i]];
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<string> c(n), d(m);
//     vector<int> p(m + 1);

//     map<string, int> mp;

//     int ans = 0;

//     rep(i, n) cin >> c[i];
//     rep(i, m) cin >> d[i];
//     rep(i, m + 1) cin >> p[i];

//     rep(i, m)
//     {
//         mp[d[i]] = p[i + 1];
//     }

//     rep(i, n)
//     {
//         if (mp[c[i]] == false)
//         {
//             ans += p[0];
//             continue;
//         }

//         ans += mp[c[i]];
//     }

//     cout << ans << endl;

//     return 0;
// }