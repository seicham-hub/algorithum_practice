// https://atcoder.jp/contests/abc323/tasks/abc323_d
// 分からなかった
// 11/30もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    long long ans = 0;
    cin >> n;

    map<long long, long long> mp;
    map<long long, long long>::iterator itr;

    rep(i, n)
    {
        int x, y;
        cin >> x >> y;
        mp[x] = y;
    }

    itr = mp.begin();

    while (itr != mp.end())
    {
        int x = (*itr).first;
        int y = (*itr).second;

        if (y > 1)
            mp[2 * x] += y / 2;
        ans += y % 2;
        itr++;
    }

    cout << ans << endl;

    return 0;
}

// 優先度付きキューの実装
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main(void)
// {
//     int n, ans = 0;
//     long long x, y;
//     map<long long, long long> mp;
//     map<long long, long long>::iterator itr;

//     cin >> n;

//     rep(i, n)
//     {
//         cin >> x >> y;
//         mp[x] += y;
//     }

//     itr = mp.begin();

//     while (itr != mp.end())
//     {
//         x = (*itr).first, y = (*itr).second;
//         if (y > 1)
//             mp[2 * x] += (y / 2);
//         // 二進数表記したときに2^0の位に1があるか
//         if (y & 1)
//             ans++;
//         itr++;
//     }

//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> s(n), c(n);

//     rep(i, n)
//     {
//         cin >> s[i] >> c[i];
//     }

//     return 0;
// }