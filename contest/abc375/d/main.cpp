// https://atcoder.jp/contests/abc375/tasks/abc375_d
// 3つあるような場合は真ん中固定するとそれぞれ独立に選べるかもね

// わからなかった...
// 2024_10_14もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    string s;
    cin >> s;
    int n = s.size();

    vector<array<int, 26>> rui(n + 1);

    rep(i, n)
    {
        rui[i + 1] = rui[i];
        rui[i + 1][s[i] - 'A']++;
    }

    ll ans = 0;

    rep(i, n)
    {

        rep(j, 26)
        {
            ans += (ll)rui[i][j] * (rui[n][j] - rui[i + 1][j]);
        }
    }

    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {

//     string s;
//     cin >> s;
//     int n = s.size();

//     vector<int> lcnt(26), rcnt(26);
//     rep(i, n) rcnt[s[i] - 'A']++;

//     ll ans = 0;
//     rep(i, n)
//     {
//         rcnt[s[i] - 'A']--;

//         rep(j, 26)
//         {
//             ans += (ll)lcnt[j] * rcnt[j];
//         }
//         lcnt[s[i] - 'A']++;
//     }

//     cout << ans << endl;

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

//     vector<int> lcnt(26);
//     vector<int> rcnt(26);

//     rep(i, n) rcnt[s[i] - 'A']++;

//     ll ans = 0;
//     rep(j, n)
//     {
//         rcnt[s[j] - 'A']--;
//         rep(c, 26) ans += (ll)lcnt[c] * rcnt[c];
//         lcnt[s[j] - 'A']++;
//     }

//     cout << ans << endl;

//     return 0;
// }

// 解説みて書いた実装
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {

//     string s;
//     cin >> s;

//     int n = s.size();

//     vector<array<int, 26>> rui(n + 1);

//     rep(i, n)
//     {
//         rui[i + 1] = rui[i];
//         rui[i + 1][s[i] - 'A'] = rui[i][s[i] - 'A'] + 1;
//     }

//     ll ans = 0;

//     auto count = [&](int mid)
//     {
//         ll result = 0;
//         for (char c = 'A'; c <= 'Z'; c++)
//             result += ll(rui[mid][c - 'A']) * (rui[n][c - 'A'] - rui[mid + 1][c - 'A']);

//         return result;
//     };

//     // 真ん中の文字探索
//     for (int l = 1; l < n - 1; l++)
//     {
//         for (char i = 'A'; i <= 'Z'; i++)
//         {

//             if (i == s[l])
//             {
//                 ans += count(l);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }