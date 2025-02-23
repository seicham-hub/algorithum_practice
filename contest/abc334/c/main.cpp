// https://atcoder.jp/contests/abc334/tasks/abc334_c

// 分からなかった...
// 2025_02_20もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n, 2);

    rep(i, k)
    {
        int a;
        cin >> a;
        a--;

        A[a]--;
    }

    vector<int> x;

    rep(i, n) rep(j, A[i]) x.push_back(i);

    n = x.size();

    if (n % 2 == 0)
    {

        int ans = 0;
        rep(i, n / 2) ans += x[2 * i + 1] - x[2 * i];

        cout << ans << endl;
        return 0;
    }
    else
    {
        int finalAns = 0;
        int ans = 0;
        rep(i, n / 2) ans += x[2 * i + 2] - x[2 * i + 1];

        finalAns = ans;

        for (int i = 1; i < n / 2; i++)
        {
            ans -= x[2 * i] - x[2 * i - 1];
            ans += x[2 * i - 1] - x[2 * i - 2];

            finalAns = min(ans, finalAns);
        }

        cout << finalAns << endl;
        return 0;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n, k;
//     cin >> n >> k;

//     vector<int> cnt(n, 2);

//     rep(i, k)
//     {
//         int a;
//         cin >> a;
//         a--;

//         cnt[a]--;
//     }

//     vector<int> x;

//     rep(i, n) rep(j, cnt[i]) x.push_back(i);

//     n = x.size();

//     if (n % 2 == 0)
//     {

//         int ans = 0;
//         rep(i, n / 2) ans += x[2 * i + 1] - x[2 * i];
//         cout << ans << endl;
//     }
//     else
//     {
//         int now = 0;
//         rep(i, n / 2) now += x[2 * i + 2] - x[2 * i + 1];
//         int ans = now;
//         for (int i = 2; i < n; i += 2)
//         {
//             now += x[i - 1] - x[i - 2];
//             now -= x[i] - x[i - 1];

//             ans = min(ans, now);
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n, k;
//     cin >> n >> k;

//     vector<int> cnt(n, 2);

//     rep(i, k)
//     {
//         int a;
//         cin >> a;
//         a--;
//         cnt[a]--;
//     }

//     vector<int> x;
//     rep(i, n) rep(j, cnt[i]) x.push_back(i);

//     n = x.size();

//     if (n % 2 == 0)
//     {
//         int ans = 0;
//         rep(i, n / 2) ans += x[i * 2 + 1] - x[i * 2];
//         cout << ans << endl;
//     }
//     else
//     {
//         int now = 0;
//         rep(i, n / 2) now += x[i * 2 + 2] - x[i * 2 + 1];
//         int ans = now;
//         for (int i = 2; i < n; i += 2)
//         {
//             now += x[i - 1] - x[i - 2];
//             now -= x[i] - x[i - 1];
//             ans = min(ans, now);
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(k);

//     rep(i, k) cin >> a[i];

//     if (k % 2 == 1)
//     {
//         ll front = 0, back = 0;
//         for (int i = 0; i + 1 <= k - 2; i = i + 2)
//             front += a[i + 1] - a[i];

//         for (int i = 1; i + 1 <= k - 1; i = i + 2)
//             back += a[i + 1] - a[i];

//         cout << min(front, back) << endl;
//     }
//     else
//     {
//         ll ans = 0;
//         for (int i = 0; i + 1 <= k - 1; i = i + 2)
//             ans = a[i + 1] - a[i];

//         cout << ans << endl;
//     }

//     return 0;
// }