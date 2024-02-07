// https://atcoder.jp/contests/abc324/tasks/abc324_d
// 0105もう一度
// 0131もう一度 ok

// 2024/2/7やり直し分
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    ll ans = 0;

    vector<int> sc(10);

    rep(i, s.size())
        sc[s[i] - '0']++;

    for (ll x = 0;; x++)
    {
        string t = to_string(x * x);

        if (t.size() > s.size())
            break;

        vector<int> tc(10);
        rep(i, t.size())
            tc[t[i] - '0']++;

        tc[0] += s.size() - t.size();

        if (sc == tc)
            ans++;
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
//     int n;
//     string s;

//     cin >> n >> s;

//     vector<int> sc(10);
//     for (char c : s)
//         sc[c - '0']++;

//     ll ans = 0;

//     for (ll x = 0;; x++)
//     {
//         string t = to_string(x * x);
//         if (t.size() > s.size())
//             break;
//         vector<int> tc(10);
//         for (char c : t)
//             tc[c - '0']++;
//         tc[0] += s.size() - t.size();

//         if (tc == sc)
//             ans++;
//     }
//     cout << ans << endl;
//     return 0;
// }

// 解答のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// using ll = long long;

// int main()
// {
//     int N;
//     string S;
//     cin >> N >> S;

//     sort(S.begin(), S.end());

//     long max_value = pow(10, N);

//     int ans = 0;
//     for (long i = 0; i * i < max_value; i++)
//     {
//         string T = to_string(i * i);
//         T.resize(N, '0');
//         sort(T.begin(), T.end());
//         if (S == T)
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }

// 自分のコード　桁数をそろえる必要があることに気づきにくい
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     vector<int> s_chars(10, 0);

//     rep(i, s.size())
//     {
//         int now_s = s[i] - '0';
//         s_chars[now_s]++;
//     }

//     ll cur_num = 0;
//     ll ans = 0;

//     while (cur_num * cur_num < 1e13)
//     {
//         ll now = cur_num * cur_num;

//         string now_str = to_string(now);
//         vector<int> check(10, 0);
//         rep(i, now_str.size())
//         {
//             int nn = now_str[i] - '0';
//             check[nn]++;
//         }

//         bool is_bi = true;
//         rep(i, 10)
//         {
//             if (i == 0 && s_chars[i] >= check[i])
//             {
//                 continue;
//             }
//             if (s_chars[i] != check[i])
//                 is_bi = false;
//         }
//         if (is_bi)
//             ans++;

//         cur_num++;
//     }

//     cout << ans << endl;

//     return 0;
// }