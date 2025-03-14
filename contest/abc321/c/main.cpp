// https://atcoder.jp/contests/abc321/tasks/abc321_c

// 解けたが、時間かかりすぎ

// 2025_03_12もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int k;
    cin >> k;

    vector<ll> ans;
    rep(msk, 1 << 10)
    {
        ll x = 0;
        for (int i = 9; i >= 0; i--)
        {
            if (msk & 1 << i)
                x = x * 10 + i;
        }

        if (x == 0)
            continue;
        ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    cout << ans[k - 1] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int k;
//     cin >> k;

//     vector<ll> ans;

//     rep(s, 1 << 10)
//     {

//         ll x = 0;
//         for (int i = 9; i >= 0; i--)
//         {
//             if (s & 1 << i)
//                 x = x * 10 + i;
//         }

//         if (x == 0)
//             continue;
//         ans.push_back(x);
//     }

//     sort(ans.begin(), ans.end());

//     cout << ans[k - 1] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {

//     vector<ll> ans;

//     auto dfs = [&](auto dfs, int &digit, string accum)
//     {
//         if (accum.size() == digit)
//         {
//             ans.push_back(stoll(accum));
//             return;
//         }

//         int now = accum.back() - '0';
//         if (now == 0)
//             return;

//         while (now > 0)
//         {
//             now--;
//             dfs(dfs, digit, accum + to_string(now));
//         }
//     };

//     rep(i, 10)
//     {
//         int digit = i + 1;

//         rep(j, 10)
//             dfs(dfs, digit, to_string(j));
//     }

//     sort(ans.begin(), ans.end());

//     ll k;
//     cin >> k;

//     cout << ans[k] << endl;

//     return 0;
// }