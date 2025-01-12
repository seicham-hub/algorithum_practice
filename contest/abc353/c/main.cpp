// https://atcoder.jp/contests/abc353/tasks/abc353_c

// 分からなかった...
// 2024_11_17もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    const int M = 1e8;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    ll ans = 0;
    rep(i, n) ans += a[i];
    ans *= n - 1;

    rep(i, n)
    {
        int index = lower_bound(a.begin() + i + 1, a.end(), M - a[i]) - a.begin();

        if (index < n)
            ans -= ll(n - index) * M;
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
//     cin >> n;

//     const int M = 1e8;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     sort(a.begin(), a.end());

//     ll ans = 0;
//     rep(i, n) ans += a[i];
//     ans *= n - 1;

//     int r = n - 1;
//     rep(i, n)
//     {
//         while (a[i] + a[r] >= M)
//         {
//             r--;
//         }
//         int nu = min(n - (i + 1), n - r - 1);
//         ans -= (ll)nu * M;
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
//     int M = 1e8;

//     int n;
//     cin >> n;
//     vector<int> a(n);

//     ll total = 0;
//     rep(i, n)
//     {
//         cin >> a[i];
//         total += a[i];
//     }
//     ll ans = total * (n - 1);

//     sort(a.begin(), a.end());

//     int r = n - 1;
//     rep(i, n - 1)
//     {
//         int ind = lower_bound(a.begin() + i + 1, a.end(), M - a[i]) - a.begin();

//         ans -= ll(n - ind) * M;
//     }

//     cout
//         << ans << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int M = 1e8;

//     int n;
//     cin >> n;
//     vector<int> a(n);

//     ll total = 0;
//     rep(i, n)
//     {
//         cin >> a[i];
//         total += a[i];
//     }
//     ll ans = total * (n - 1);

//     sort(a.begin(), a.end());

//     int r = n - 1;
//     rep(i, n - 1)
//     {
//         // cout << a[i] + a[r] - M << endl;
//         while (r >= 0 && a[i] + a[r] >= M)
//         {
//             r--;
//         }

//         int cnt = n - max(i + 1, r + 1);
//         ans -= (ll)(n - max(i + 1, r + 1)) * M;
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
//     int n;
//     cin >> n;

//     vector<int> a(n);

//     ll total = 0;
//     rep(i, n)
//     {
//         cin >> a[i];
//         total += a[i];
//     }

//     ll ans = total * (n - 1);

//     sort(a.begin(), a.end());

//     ll tInt = 0;
//     rep(i, n)
//     {
//         ll target = 1e8 - a[i];
//         int ind = lower_bound(a.begin(), a.end(), target) - a.begin();
//         if (ind <= i)
//             tInt += n - i - 1;
//         else
//             tInt += n - ind;
//     }

//     ans -= (ll)1e8 * tInt;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     const int M = 1e8;
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     sort(a.begin(), a.end());

//     ll ans = 0;

//     rep(i, n) ans += (ll)a[i] * (n - 1);

//     int r = n - 1;
//     rep(i, n)
//     {
//         while (r >= 0 || a[i] + a[r] >= M)
//             r--;

//         // max(r,i+1) <= j < n
//         ans -= ll(n - max(r, i + 1) - 1) * M;
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int f(int x, int y)
// {
//     return (x + y) % 100000000;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     return 0;
// }