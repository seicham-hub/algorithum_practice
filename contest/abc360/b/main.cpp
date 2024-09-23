// https://atcoder.jp/contests/abc360/tasks/abc360_b
// substr使えるか
// 2024_09_15もう一度
// 2024_09_17もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string s, t;
    cin >> s >> t;

    for (int w = 1; w < s.size(); w++)
    {

        string s_cp = s;
        vector<string> sub;

        while (s_cp.size() >= w)
        {
            sub.push_back(s_cp.substr(0, w));
            s_cp.erase(s_cp.begin(), s_cp.begin() + w);
        }

        if (s_cp.size() != 0)
            sub.push_back(s_cp);

        rep(c, w)
        {
            string tmp = "";

            for (string sb : sub)
            {
                if (sb.size() > c)
                    tmp += sb[c];
            }

            if (tmp == t)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     string s, t;
//     cin >> s >> t;

//     for (int w = 1; w < s.size(); w++)
//     {
//         string scp = s;
//         vector<string> sb;

//         while (scp.size() >= w)
//         {
//             string sbb = scp.substr(0, w);
//             scp.erase(scp.begin(), scp.begin() + w);
//             sb.push_back(sbb);
//         }
//         sb.push_back(scp);

//         for (int c = 1; c <= w; c++)
//         {
//             string tmp = "";
//             for (string ss : sb)
//             {
//                 if (ss.size() >= c)
//                     tmp += ss[c - 1];
//             }

//             if (tmp == t)
//             {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     string s, t;
//     cin >> s >> t;

//     for (int w = 1; w <= s.size() - 1; w++)
//     {
//         string s_cp = s;
//         vector<string> sub;

//         while (s_cp.size() >= w)
//         {
//             string sb = s_cp.substr(0, w);
//             s_cp.erase(s_cp.begin(), s_cp.begin() + w);
//             sub.push_back(sb);
//         }
//         if (s_cp.size() > 0)
//             sub.push_back(s_cp);

//         for (int c = 1; c <= w; c++)
//         {
//             string tmp = "";
//             for (string sbb : sub)
//             {
//                 if (sbb.size() >= c)
//                 {
//                     tmp += sbb[c - 1];
//                 }
//             }
//             if (tmp == t)
//             {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     string s, t;
//     cin >> s >> t;
//     for (int w = 1; w <= s.size(); w++)
//     {
//         string ns = s;
//         vector<string> ss;

//         while (ns.size() >= w)
//         {
//             ss.push_back(ns.substr(0, w));
//             ns.erase(ns.begin(), ns.begin() + w);
//         }
//         ss.push_back(ns);

//         rep(c, w)
//         {
//             string nt = "";
//             for (string &ns : ss)
//             {
//                 if (c < ns.size())
//                     nt += ns[c];
//             }
//             if (nt == t)
//             {

//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "No" << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     string s, t;
//     cin >> s >> t;

//     int n = s.size();

//     vector<vector<string>> sbstr(n + 1);
//     bool ans = false;

//     for (int i = 1; i < n; i++)
//     {

//         string tmp = "";
//         for (char c : s)
//         {
//             tmp += c;
//             if (tmp.size() == i)
//             {
//                 sbstr[i].push_back(tmp);
//                 tmp = "";
//             }
//         }
//         if (tmp != "")
//             sbstr[i].push_back(tmp);
//     }

//     for (int i = 1; i <= n - 1; i++)
//     {

//         for (int j = 1; j <= n - 1; j++)
//         {
//             string tmp = "";
//             for (string sub : sbstr[i])
//             {
//                 if (j <= sub.size())
//                     tmp += sub[j - 1];
//             }

//             if (tmp == t)
//             {
//                 cout << "Yes" << endl;

//                 return 0;
//             }
//         }
//     }

//     cout << "No" << endl;

//     return 0;
// }