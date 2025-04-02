// https://atcoder.jp/contests/abc320/tasks/abc320_c

// わからなかった...
// 2025_03_13もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int m;
    cin >> m;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int ans = 1e9;

    rep(t1, 3 * m)
    {
        rep(t2, 3 * m)
        {
            rep(t3, 3 * m)
            {
                if (t1 == t2)
                    continue;
                if (t2 == t3)
                    continue;
                if (t1 == t3)
                    continue;

                if (s1[t1 % m] == s2[t2 % m] && s2[t2 % m] == s3[t3 % m])
                    ans = min(ans, max({t1, t2, t3}));
            }
        }
    }

    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {

//     int m;
//     cin >> m;
//     string s1, s2, s3;
//     cin >> s1 >> s2 >> s3;

//     int ans = 2e7;

//     rep(t1, 300) rep(t2, 300) rep(t3, 300)
//     {
//         if (t1 == t2)
//             continue;
//         if (t2 == t3)
//             continue;
//         if (t1 == t3)
//             continue;

//         if (s1[t1 % m] == s2[t2 % m] && s2[t2 % m] == s3[t3 % m])
//             ans = min(ans, max({t1, t2, t3}));
//     }

//     if (ans == 2e7)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int m;
//     cin >> m;
//     vector<string> s(3);

//     rep(i, 3) cin >> s[i];

//     const int INF = 1e4;
//     int ans = INF;

//     rep(t1, 300) rep(t2, 300) rep(t3, 300)
//     {
//         if (t1 == t2)
//             continue;
//         if (t2 == t3)
//             continue;
//         if (t1 == t3)
//             continue;

//         if (s[0][t1 % m] == s[1][t2 % m] && s[1][t2 % m] == s[2][t3 % m])
//             ans = min(ans, max({t1, t2, t3}));
//     }

//     if (ans == INF)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// void calc(string s, int i, int &time, int &isOk)
// {
//     for (int j = 0; j < s.size(); j++)
//     {
//         if (s[(j + time) % s.size()] - '0' == i)
//         {
//             time += j;
//             isOk++;
//             break;
//         }
//     }
// }

// int main()
// {

//     int m;
//     cin >> m;

//     string s1, s2, s3;
//     cin >> s1 >> s2 >> s3;

//     vector<string> ss = {s1, s2, s3};

//     vector<vector<int>> s1Vtoi(10), s2Vtoi(10), s3Vtoi(10);
//     rep(i, m) s1Vtoi[s1[i] - '0'].push_back(i);
//     rep(i, m) s2Vtoi[s1[i] - '0'].push_back(i);
//     rep(i, m) s3Vtoi[s1[i] - '0'].push_back(i);

//     vector sVtoi = {s1Vtoi, s2Vtoi, s3Vtoi};

//     vector<int> indices = {0, 1, 2};
//     int ans = 2e8;

//     for (int i = 1; i <= 9; i++)
//     {
//         do
//         {
//             string ss1 = ss[indices[0]];
//             string ss2 = ss[indices[1]];
//             string ss3 = ss[indices[2]];

//             int time = 0;
//             int isOk = 0;

//             calc(ss1, i, time, isOk);
//             time++;
//             calc(ss2, i, time, isOk);
//             time++;
//             calc(ss3, i, time, isOk);

//             if (isOk == 3)
//                 ans = min(ans, time);

//         } while (next_permutation(indices.begin(), indices.end()));
//     }

//     cout << ans << endl;

//     return 0;
// }