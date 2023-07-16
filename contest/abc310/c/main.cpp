// https://atcoder.jp/contests/abc310/tasks/abc310_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);

    rep(i, n) cin >> s[i];

    map<string, bool> mp;
    int ans = 0;

    rep(i, n)
    {

        if (mp[s[i]] == false)
        {
            ans++;
            mp[s[i]] = true;
            string tmp = s[i];
            reverse(tmp.begin(), tmp.end());
            mp[tmp] = true;
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<string> s(n);

//     map<string, bool> mp;
//     int ans = 0;

//     rep(i, n) cin >> s[i];

//     rep(i, n)
//     {
//         if (mp[s[i]] == false)
//         {
//             ans++;
//             mp[s[i]] = true;
//             string tmp = s[i];
//             reverse(tmp.begin(), tmp.end());
//             mp[tmp] = true;
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }