// https://atcoder.jp/contests/abc361/tasks/abc361_c
// 上手くいかなかった... もう一度

// 2024_10_20

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 1e9;

    rep(i, k + 1)
    {
        ans = min(ans, a[i + n - k - 1] - a[i]);
    }

    cout << ans << endl;

    return 0;
}

// 自分の回答　貪欲法は複数先考えると最適じゃないときがある
// eraseは計算量n位かかる
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n);

//     rep(i, n) cin >> a[i];

//     sort(a.begin(), a.end());

//     int cnt = 0;
//     int i = 0;
//     int j = a.size() - 1;

//     while (cnt < k)
//     {
//         if (a[i + 1] - a[i] > a[j] - a[j - 1])
//         {
//             i++;
//         }
//         else
//         {
//             j--;
//         }

//         cnt++;
//     }

//     cout << a[j] - a[i] << endl;

//     return 0;
// }