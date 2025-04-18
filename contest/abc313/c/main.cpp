// https://atcoder.jp/contests/abc313/tasks/abc313_c
// 最大1e9差なので普通にやってたらどんなに頑張っても終わらないよね
// 0806もう一度
// 0809もう一度 ok

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n;
    cin >> n;

    vector<int> a(n);

    ll tot = 0;
    rep(i, n)
    {
        cin >> a[i];
        tot += a[i];
    }

    sort(a.begin(), a.end());

    ll mean = tot / n;
    ll plus = tot % n;
    ll ans = 0;

    rep(i, n - plus)
    {
        ans += abs(mean - a[i]);
    }
    rep(i, plus)
    {
        ans += abs(mean + 1 - a[n - plus + i]);
    }

    cout << ans / 2 << endl;
}

/*
9/26 やり直し分
*/

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);

//     ll sum = 0;

//     rep(i, n)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     sort(a.begin(), a.end());

//     int base = sum / n;
//     int plus = sum % n;

//     vector<int> com(n, base);
//     rep(i, plus)
//     {
//         com[n - 1 - i] += 1;
//     }

//     ll ans = 0;

//     rep(i, n)
//     {
//         ans += abs(a[i] - com[i]);
//     }

//     cout << ans / 2 << endl;

//     return 0;
// }

// /*
// 8/10やり直し分
// */

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     ll sum = 0;
//     rep(i, n)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     sort(a.begin(), a.end());

//     vector<int> b(n, sum / n);

//     for (int i = 0; i < sum % n; i++)
//     {
//         b[n - 1 - i]++;
//     }

//     sum = 0;
//     rep(i, n)
//     {
//         sum += abs(a[i] - b[i]);
//     }

//     cout << sum / 2 << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     vector<int> b(n);

//     long long sum = 0;

//     rep(i, n)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     int ave = sum / n;
//     int remain = sum % n;

//     sort(a.begin(), a.end());

//     rep(i, n)
//     {
//         if (i <= n - 1 - remain)
//             b[i] = ave;
//         else
//             b[i] = ave + 1;
//     }

//     sum = 0;

//     rep(i, n)
//     {
//         sum += abs(a[i] - b[i]);
//     }

//     cout << sum / 2 << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     ll sum = 0;

//     rep(i, n)
//     {
//         cin >> a[i];
//         sum += a[i];
//     }

//     sort(a.begin(), a.end());
//     vector<int> b(n, sum / n);

//     rep(i, sum % n)
//     {
//         b[n - 1 - i]++;
//     }

//     ll ans = 0;

//     rep(i, n)
//     {
//         ans += abs(a[i] - b[i]);
//     }

//     cout << ans / 2 << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     multiset<int> s;

//     rep(i, n)
//     {
//         int a;
//         cin >> a;
//         s.insert(a);
//     }

//     int ans = 0;

//     while (*s.rbegin() - *s.begin() > 1)
//     {
//         auto f = *s.begin();
//         auto e = *s.rbegin();

//         s.erase(s.begin());
//         s.erase(s.find(e));

//         s.insert(f + 1);
//         s.insert(e - 1);
//         ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }