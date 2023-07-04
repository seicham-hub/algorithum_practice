// https://atcoder.jp/contests/abc306/tasks/abc306_e
// 0628もう一度
// 0629もう一度 ok

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    multiset<int> s, t;
    rep(i, k) s.insert(0);
    rep(i, n - k) t.insert(0);

    vector<int> a(n);

    ll ans = 0;

    auto add = [&](int x)
    {
        s.insert(x);
        ans += x;
        int mini = *s.begin();
        s.erase(s.find(mini));
        ans -= mini;
        t.insert(mini);
    };

    auto del = [&](int x)
    {
        if (s.find(x) != s.end())
        {
            s.erase(s.find(x));
            ans -= x;
            int maxi = *t.rbegin();
            t.erase(t.find(maxi));
            s.insert(maxi);
            ans += maxi;
        }
        else
        {
            t.erase(t.find(x));
        }
    };

    rep(i, q)
    {
        int x, y;
        cin >> x >> y;
        x--;

        add(y);
        del(a[x]);
        a[x] = y;
        cout << ans << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n, k, q;
//     cin >> n >> k >> q;

//     multiset<int> s, t;
//     rep(i, k) s.insert(0);
//     rep(i, n - k) t.insert(0);
//     ll ans = 0;

//     vector<int> a(n, 0);

//     auto add = [&](int x)
//     {
//         s.insert(x);
//         ans += x;
//         int mini = *s.begin();
//         s.erase(s.find(mini));
//         ans -= mini;
//         t.insert(mini);
//     };

//     auto del = [&](int x)
//     {
//         if (s.find(x) != s.end())
//         {
//             s.erase(s.find(x));
//             ans -= x;
//             int maxi = *t.rbegin();
//             t.erase(t.find(maxi));
//             s.insert(maxi);
//             ans += maxi;
//         }
//         else
//         {
//             t.erase(t.find(x));
//         }
//     };

//     rep(i, q)
//     {
//         int x, y;

//         cin >> x >> y;
//         x--;

//         // n=kの場合はtが空だと足りなくなるのでadd先に

//         add(y);
//         del(a[x]);
//         a[x] = y;
//         cout << ans << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n, k, q;
//     cin >> n >> k >> q;

//     vector<int> a(n);
//     multiset<int> s, t;
//     rep(i, k) s.insert(0);
//     rep(i, n - k) t.insert(0);
//     ll ans = 0;

//     auto add = [&](int x)
//     {
//         s.insert(x);
//         ans += x;
//         int y = *s.begin();
//         // 普通にyだけ指定すると全部消えるのでfindしないとダメ
//         s.erase(s.find(y));
//         ans -= y;
//         t.insert(y);
//     };
//     auto del = [&](int x)
//     {
//         // sに入っているかで場合分け
//         if (s.find(x) != s.end())
//         {
//             s.erase(s.find(x));
//             ans -= x;
//             int y = *t.rbegin();
//             t.erase(t.find(y));
//             s.insert(y);
//             ans += y;
//         }
//         else
//         {
//             t.erase(t.find(x));
//         }
//     };

//     rep(qi, q)
//     {
//         int x, y;
//         cin >> x >> y;
//         --x;
//         add(y);
//         del(a[x]);
//         a[x] = y;
//         cout << ans << '\n';
//     }

//     return 0;
// }

// 自分で解いたコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n, k, q;
//     cin >> n >> k >> q;
//     vector<int> x(q), y(q);

//     vector<int> a(n);
//     int sum = 0;

//     rep(i, q)
//     {
//         cin >> x[i] >> y[i];

//         if (y[i] >= a[k - 1])
//         {
//             sum += y[i] - a[k - 1];
//         }
//         else
//         {
//             if (x[i] < k)
//                 sum = sum - a[x[i] - 1] + a[k];
//         }
//         a[x[i] - 1] = y[i];
//         sort(a.begin(), a.end(), greater<int>());

//         cout << sum << endl;
//     }

//     return 0;
// }