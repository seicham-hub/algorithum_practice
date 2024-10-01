// https://atcoder.jp/contests/abc369/tasks/abc369_c
// 分からなかった...
// 2024_09_27もう一度
// 2024_09_28もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> b(n - 1);
    rep(i, n - 1) b[i] = a[i + 1] - a[i];

    vector<P> rle;

    rep(i, n - 1)
    {

        if (rle.size() && rle.back().first == b[i])
            rle.back().second++;
        else
            rle.push_back({b[i], 1});
    }

    ll ans = n;
    for (auto [x, cnt] : rle)
    {
        ans += ll(cnt) * (cnt + 1) / 2;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     int r = 0;
//     ll ans = 0;

//     rep(l, n)
//     {
//         while (r < n)
//         {
//             if (r > l + 1 && a[r] - a[r - 1] != a[r - 1] - a[r - 2])
//                 break;
//             r++;
//         }

//         ans += r - l;
//     }

//     cout << ans << endl;

//     return 0;
// }

// お手本解答：run length圧縮
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     vector<int> b(n - 1);

//     rep(i, n - 1) b[i] = a[i + 1] - a[i];

//     // run length encode
//     vector<P> rle;

//     rep(i, n - 1)
//     {
//         if (rle.size() && rle.back().first == b[i])
//         {
//             rle.back().second++;
//         }
//         else
//         {
//             rle.emplace_back(b[i], 1);
//         }
//     }

//     ll ans = n;

//     for (auto [x, cnt] : rle)
//     {
//         ans += cnt * ll(cnt + 1) / 2;
//     }

//     cout << ans << endl;

//     return 0;
// }

// お手本解答：尺取り法
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n);
//     rep(i, n) cin >> a[i];

//     ll ans = 0;
//     int r = 0;

//     rep(l, n)

//     {
//         while (r < n)
//         {
//             if (r > l + 1 && a[r] - a[r - 1] != a[r - 1] - a[r - 2])
//                 break;
//             r++;
//         }
//         ans += r - l;
//     }

//     cout << ans << endl;

//     return 0;
// }

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