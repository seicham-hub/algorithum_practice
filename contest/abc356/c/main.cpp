// https://atcoder.jp/contests/abc356/tasks/abc356_c

// 時間かかった、なぜ間違えてるのか分からなかった

// 2024_11_07もう一度
// 2024_11_14もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> test(m);
    vector<char> r(m);

    rep(i, m)
    {
        int c;
        cin >> c;

        int tmp = 0;
        rep(j, c)
        {
            int a;
            cin >> a;
            a--;
            tmp = tmp | (1 << a);
        }
        cin >> r[i];
        test[i] = tmp;
    }

    int ans = 0;

    rep(msk, (1 << n))
    {
        bool flg = true;
        rep(i, m)
        {
            int cnt = __builtin_popcount(msk & test[i]);
            if (cnt >= k && r[i] == 'x')
                flg = false;
            if (cnt < k && r[i] == 'o')
                flg = false;
        }

        if (flg)
            ans++;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)
// using ll = long long;

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> ab(m);
//     vector<char> r(m);

//     rep(i, m)
//     {
//         int c;
//         cin >> c;
//         rep(j, c)
//         {
//             int a;
//             cin >> a;
//             a--;
//             ab[i] |= 1 << a;
//         }
//         cin >> r[i];
//     }

//     int ans = 0;

//     rep(candidate, 1 << n)
//     {
//         bool ok = true;
//         rep(i, m)
//         {
//             int trueCnt = __builtin_popcount(candidate & ab[i]);
//             if (trueCnt >= k && r[i] != 'o')
//                 ok = false;
//             if (trueCnt < k && r[i] != 'x')
//                 ok = false;
//         }
//         if (ok)
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)
// using ll = long long;

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> am;
//     vector<char> r(m);

//     rep(i, m)
//     {
//         int c;
//         cin >> c;
//         int bit = 0;
//         rep(j, c)
//         {
//             int a;
//             cin >> a;
//             a--;

//             bit |= 1 << a;
//         }
//         cin >> r[i];
//         am.push_back(bit);
//     }

//     int ans = 0;

//     rep(msk, 1 << n)
//     {
//         bool ok = true;
//         rep(i, m)
//         {
//             int cnt = __builtin_popcount(msk & am[i]);

//             if (cnt >= k && r[i] != 'o')
//                 ok = false;
//             if (cnt < k && r[i] != 'x')
//                 ok = false;
//         }

//         if (ok)
//             ans++;
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
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> as(m);
//     vector<char> r(m);

//     rep(i, m)
//     {
//         int c;
//         cin >> c;
//         rep(j, c)
//         {
//             int a;
//             cin >> a;
//             a--;
//             as[i] = as[i] | 1 << a;
//         }
//         cin >> r[i];
//     }

//     int ans = 0;

//     rep(msk, 1 << n)
//     {
//         bool ok = true;
//         rep(i, m)
//         {
//             int cnt = __builtin_popcount(msk & as[i]);
//             if ((cnt >= k) != (r[i] == 'o'))
//                 ok = false;
//         }
//         if (ok)
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }

// 自分のコード mskが1始まりだったからこけてた
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> c(m);
//     vector<char> r(m);
//     vector<vector<int>> a(m);

//     rep(i, m)
//     {
//         cin >> c[i];

//         rep(j, c[i])
//         {
//             int aim;
//             cin >> aim;
//             aim--;
//             a[i].push_back(aim);
//         }
//         cin >> r[i];
//     }
//     ll ans = 0;

//     auto check = [&](int msk, int bit)
//     {
//         int result = 0;
//         rep(i, n)
//         {
//             if (msk & 1 << i)
//             {
//                 if ((bit & 1 << i))
//                     result++;
//             }
//         }

//         return result >= k;
//     };

//     for (int msk = 0; msk < (1 << n); msk++)
//     {
//         bool ok = true;
//         rep(i, m)
//         {
//             int bit = 0;
//             for (int aij : a[i])
//             {
//                 bit = bit | 1 << aij;
//             }

//             if (!check(msk, bit) && r[i] == 'o')
//                 ok = false;
//             if (check(msk, bit) && r[i] == 'x')
//                 ok = false;
//         }

//         if (ok)
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }