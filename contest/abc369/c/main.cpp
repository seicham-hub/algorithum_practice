// https://atcoder.jp/contests/abc369/tasks/abc369_c
// 分からなかった...
// 2024_09_27もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;
    int r = 0;

    rep(l, n)
    {
        while (r < n)
        {
            if (r > l + 1 && a[r] - a[r - 1] != a[r - 1] - a[r - 2])
                break;
            r++;
        }
        ans += r - l;
    }

    cout << ans << endl;

    return 0;
}

// 自分で書いたコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     set<int> st;

//     int ans = 0;

//     rep(i, n - 1)
//     {
//         int diff = a[i + 1] - a[i];
//         ans += 2;
//         if (st.count(diff))
//         {
//             ans += 1;
//         }
//         else
//         {
//             set<int> st_c;
//             st = st_c;
//         }
//         st.insert(diff);
//     }

//     return 0;
// }