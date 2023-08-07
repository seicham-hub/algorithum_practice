// https://atcoder.jp/contests/abc313/tasks/abc313_b
// 勝手に強さの関係性に矛盾がないと考えていた。（1←2,2←3,3←1が成り立つ場合も存在する）
// 0806もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    vector<int> check(n + 1, 0), ans;

    rep(i, m)
    {

        cin >> a[i] >> b[i];
        check[b[i]]++;
    }

    for (int i = 1; i < n + 1; i++)
    {
        if (check[i] == 0)
            ans.push_back(i);
    }

    if (ans.size() == 1)
        cout << ans[0] << endl;
    else
        cout << -1 << endl;

    return 0;
}

/*
本番のコード
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(m), b(m);

//     map<int, int> mp;

//     rep(i, m)
//     {
//         cin >> a[i] >> b[i];
//         mp[b[i]] = a[i];
//     }

//     for (int i = 1; i < n + 1; i++)
//     {

//         int now = i;
//         int cnt = 0;

//         while (mp[now])
//         {
//             now = mp[now];
//             cnt++;
//         }

//         if (cnt == n - 1)
//         {
//             cout << now << endl;
//             return 0;
//         }
//     }

//     cout << -1 << endl;

//     return 0;
// }
