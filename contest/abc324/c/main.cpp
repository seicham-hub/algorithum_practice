// https://atcoder.jp/contests/abc324/tasks/abc324_c
// 0124もう一度 ok

// 2024 1/24やり直し分
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

bool f(string &s, string &t)
{
    if (s.size() != t.size() - 1)
        return false;

    int ti = 0;
    rep(i, s.size())
    {
        while (ti < t.size() && t[ti] != s[i])
            ti++;
        if (ti == t.size())
            return false;
        ti++;
    }
    return true;
}

int ham(string &s, string &t)
{
    if (s.size() != t.size())
        return 999;
    int res = 0;
    rep(i, s.size())
    {
        if (s[i] != t[i])
            res++;
    }
    return res;
}

int main()
{
    int n;
    string t;
    cin >> n >> t;
    vector<int> ans;

    rep(i, n)
    {
        string s;
        cin >> s;

        bool ok = false;

        if (s.size() + 1 >= t.size())
        {

            if (s == t)
                ok = true;
            if (f(s, t))
                ok = true;
            if (f(t, s))
                ok = true;
            if (ham(s, t) <= 1)
                ok = true;
        }

        if (ok)
            ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int a : ans)
        cout << a << " ";

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int ham(string &s, string &t)
// {
//     if (s.size() != t.size())
//         return 9999;
//     int res = 0;
//     rep(i, s.size()) if (s[i] != t[i]) res++;
//     return res;
// }

// bool f(string &s, string &t)
// {

//     if (s.size() - t.size() != 1)
//         return false;

//     int si = 0;
//     rep(i, t.size())
//     {
//         while (si < s.size() && t[i] != s[si])
//             si++;
//         if (si == s.size())
//             return false;
//         si++;
//     }
//     return true;
// }

// int main()
// {
//     int n;
//     string t;
//     cin >> n >> t;
//     vector<int> ans;

//     rep(i, n)
//     {
//         string s;
//         cin >> s;
//         bool ok = false;

//         if (s.size() + 1 >= t.size())
//         {

//             if (t == s)
//                 ok = true;
//             if (f(s, t))
//                 ok = true;
//             if (f(t, s))
//                 ok = true;
//             if (ham(s, t) <= 1)
//                 ok = true;
//         }

//         if (ok)
//             ans.push_back(i + 1);
//     }

//     cout << ans.size() << endl;
//     for (int a : ans)
//         cout << a << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// int ham(string &s, string &t)
// {
//     if (s.size() != t.size())
//         return 999;
//     int res = 0;
//     rep(i, s.size()) if (s[i] != t[i]) res++;
//     return res;
// }
// bool f(string &s, string &t)
// {
//     if (s.size() != t.size() + 1)
//         return false;
//     int si = 0;
//     rep(ti, t.size())
//     {
//         while (si < s.size() && s[si] != t[ti])
//             si++;
//         if (si == s.size())
//             return false;
//         si++;
//     }
//     return true;
// }

// int main()
// {
//     int n;
//     string t;
//     vector<int> ans;
//     cin >> n >> t;

//     rep(i, n)
//     {
//         string s;
//         cin >> s;

//         bool ok = false;
//         if (s.size() + 1 >= t.size())
//         {
//             if (s == t)
//                 ok = true;
//             if (f(s, t))
//                 ok = true;
//             if (f(t, s))
//                 ok = true;
//             if (ham(s, t) <= 1)
//                 ok = true;
//         }

//         if (ok)
//             ans.push_back(i + 1);
//     }

//     cout << ans.size() << endl;
//     for (int i : ans)
//         cout << i << ' ';
//     return 0;
// }

// 自分のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     string td;
//     cin >> n >> td;
//     vector<string> s(n);

//     vector<vector<int>> count_al(n, vector<int>(26, 0));
//     rep(i, n)
//             cin >>
//         s[i];

//     vector<int> ans;

//     rep(i, n)
//     {
//         if (td.size() == s[i].size())
//         {
//             int diff = 0;
//             rep(j, td.size())
//             {
//                 if (s[i][j] != td[j])
//                     diff++;
//             }
//             if (diff <= 1)
//                 ans.push_back(i + 1);
//         }
//         else if ((td.size() - s[i].size()) == 1)
//         {
//             int diff = 0;
//             int sj = 0;

//             rep(j, td.size())
//             {
//                 if (td[j] != s[i][sj])
//                 {
//                     diff++;
//                     continue;
//                 }
//                 sj++;
//             }
//             if (diff <= 1)
//                 ans.push_back(i + 1);
//         }
//         else if ((s[i].size() - td.size()) == 1)
//         {
//             int diff = 0;
//             int tj = 0;

//             rep(j, s[i].size())
//             {
//                 if (td[tj] != s[i][j])
//                 {
//                     diff++;
//                     continue;
//                 }
//                 tj++;
//             }
//             if (diff <= 1)
//                 ans.push_back(i + 1);
//         }
//     }

//     cout << ans.size() << endl;

//     rep(i, ans.size())
//     {
//         if (i == ans.size() - 1)
//             cout << ans[i] << endl;
//         else
//             cout << ans[i] << " ";
//     }

//     return 0;
// }