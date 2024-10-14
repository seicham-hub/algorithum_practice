// https://atcoder.jp/contests/abc363/tasks/abc363_c
// 分からなかった

// 2024_10_15もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int ans = 0;

    // これ必要
    sort(s.begin(), s.end());

    do
    {
        bool ok = true;
        rep(i, n - k + 1)
        {
            string sub = s.substr(i, k);
            string palin = sub;
            reverse(palin.begin(), palin.end());

            if (sub == palin)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            ans++;

    } while (next_permutation(s.begin(), s.end()));
    // next_permutation　重複がある場合は同じもの試さないようにしてくれる

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n, k;
//     cin >> n >> k;
//     string s;
//     cin >> s;

//     auto check = [&](string &s, int mid)
//     {
//         bool result = true;
//         rep(i, k / 2)
//         {
//             if (mid - i - 1 < 0 || n - 1 < mid + i)
//             {
//                 bool result = true;
//                 break;
//             }
//             if (s[mid - i - 1] != s[mid + i])
//                 result = false;
//         }

//         return result;
//     };

//     auto check2 = [&](string &s, int mid)
//     {
//         bool result = true;
//         rep(i, k / 2)
//         {
//             if (mid - i - 1 < 0 || n - 1 < mid + 1 + i)
//             {
//                 bool result = true;
//                 break;
//             }
//             if (s[mid - i - 1] != s[mid + 1 + i])
//                 result = false;
//         }

//         return result;
//     };

//     int ans = 0;

//     do
//     {
//         rep(i, n)
//         {
//             if (k % 2 == 0)
//             {
//                 if (!check(s, i))
//                     ans++;
//             }
//             else
//             {
//                 if (!check2(s, i))
//                     ans++;
//             }
//         }

//     } while (next_permutation(s.begin(), s.end()));

//     cout << ans << endl;

//     return 0;
// }