// https://atcoder.jp/contests/abc342/tasks/abc342_c

// 分からなかった...
// 2025_02_10もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n, q;
    string s;
    cin >> n >> s >> q;

    unordered_map<char, char> alphaMap;
    rep(i, 26) alphaMap[i + 'a'] = i + 'a';

    rep(i, q)
    {
        char c, d;
        cin >> c >> d;

        rep(i, 26) if (c == alphaMap[i + 'a']) alphaMap[i + 'a'] = d;
    }

    string ans = "";
    for (char c : s)
    {
        ans += alphaMap[c];
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// const string alpabet = "abcdefghijklmnopqrstuvwxyz";

// int main()
// {
//     int n, q;
//     string s;
//     cin >> n >> s >> q;

//     string t;
//     rep(i, 26) t += 'a' + i;

//     rep(qi, q)
//     {
//         char c, d;
//         cin >> c >> d;
//         rep(i, 26)
//         {
//             if (t[i] == c)
//                 t[i] = d;
//         }
//     }

//     rep(i, n)
//     {
//         int j = s[i] - 'a';
//         s[i] = t[j];
//     }

//     cout << s << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// const string alpabet = "abcdefghijklmnopqrstuvwxyz";

// int main()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     int q;
//     cin >> q;

//     map<char, char> mp;

//     rep(i, alpabet.size())
//     {
//         mp[alpabet[i]] = alpabet[i];
//     }

//     rep(i, q)
//     {

//         char c, d;
//         cin >> c >> d;

//         for (char alpha : alpabet)
//         {
//             if (mp[alpha] == c)
//                 mp[alpha] = d;
//         }
//     }

//     string ans = "";
//     for (char c : s)
//     {
//         ans += mp[c];
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     int q;
//     cin >> q;

//     vector<vector<int>> indMp(26);

//     rep(i, s.size())
//     {
//         char c = s[i];
//         indMp[c - 'a'].push_back(i);
//     }

//     rep(i, q)
//     {
//         char c, d;
//         cin >> c >> d;

//         vector<int> tmp = indMp[c - 'a'];

//         rep(j, tmp.size())
//             indMp[d - 'a']
//                 .push_back(tmp[j]);

//         if (c != d)
//             indMp[c - 'a'] = vector<int>();
//     }

//     string ans = string(s.size(), ' ');

//     rep(i, 26)
//     {
//         char now = i + 'a';
//         for (int ind : indMp[i])
//         {
//             ans[ind] = now;
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }