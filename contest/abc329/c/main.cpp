// https://atcoder.jp/contests/abc329/tasks/abc329_c

// 2025_02_27もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<char, int>> rle;

    rep(i, n)
    {
        if (rle.size() && rle.back().first == s[i])
            rle.back().second++;
        else
            rle.emplace_back(s[i], 1);
    }

    vector<int> mx(26);

    for (auto [c, len] : rle)
    {
        mx[c - 'a'] = max(mx[c - 'a'], len);
    }

    int ans = 0;

    rep(i, 26)
    {
        ans += mx[i];
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
//     string s;
//     cin >> n >> s;

//     vector<pair<char, int>> d;

//     for (char c : s)
//     {
//         if (d.size() && d.back().first == c)
//             d.back().second++;
//         else
//             d.emplace_back(c, 1);
//     }

//     vector<int> mx(26);

//     for (auto [c, len] : d)
//     {
//         mx[c - 'a'] = max(mx[c - 'a'], len);
//     }
//     int ans = 0;
//     for (int len : mx)
//         ans += len;

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

//     map<char, int> mp;

//     int ans = 0, cnt = 0;
//     string tmp = "";
//     for (int i = 0; i < n; i++)
//     {

//         if (i > 0 && s[i] != s[i - 1])
//         {
//             cnt = 1;
//             if (mp[s[i]] < cnt)
//             {
//                 ans++;
//                 mp[s[i]] = cnt;
//             }
//         }
//         else
//         {
//             cnt++;
//             if (mp[s[i]] < cnt)
//             {
//                 ans++;
//                 mp[s[i]] = cnt;
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// ダメだったコード↓
// stringの加算操作はO(1)ではなくO(n) nはstringの長さ

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

//     unordered_set<string> ans;

//     string tmp = "";
//     for (int i = 0; i < n; i++)
//     {

//         if (i > 0 && s[i] != s[i - 1])
//             tmp = s[i];
//         else
//             tmp += s[i];
//         ans.insert(tmp);
//     }

//     cout << ans.size() << endl;

//     return 0;
// }