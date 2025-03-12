// https://atcoder.jp/contests/abc395/tasks/abc395_c
// 解けたが時間かかった

// 2025_03_11もう一度

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

    vector<int> cnt(2e6);

    int r = 0;

    const int INF = 2e6;
    int mult = 0;
    int ans = INF;
    rep(l, n)
    {

        while (r < n && mult == 0)
        {
            cnt[a[r]]++;

            if (cnt[a[r]] == 2)
                mult++;
            r++;
        }
        if (mult == 0)
            break;

        ans = min(ans, r - l);
        if (cnt[a[l]] == 2)
            mult--;
        cnt[a[l]]--;
    }

    if (ans == INF)
        cout << -1 << endl;
    else
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

//     vector<vector<int>> mp(1e6 + 1, vector<int>());

//     rep(i, n)
//     {

//         mp[a[i]].push_back(i);
//     }

//     int ans = 2e6;
//     rep(i, mp.size())
//     {
//         rep(j, mp[i].size())
//         {
//             if (j == 0)
//                 continue;
//             ans = min(ans, mp[i][j] - mp[i][j - 1] + 1);
//         }
//     }

//     if (ans == 2e6)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }