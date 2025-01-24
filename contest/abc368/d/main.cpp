// https://atcoder.jp/contests/abc368/tasks/abc368_d

// 分からなかった
// 頂点を残す為の条件は？

// 2025_01_13もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> to(n);

    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> v(k);
    vector<bool> selected(n);

    rep(i, k)
    {
        cin >> v[i];
        v[i]--;
        selected[v[i]] = true;
    }

    vector<int> point(n);
    auto dfs = [&](auto dfs, int now, int p = -1) -> void
    {
        if (selected[now])
            point[now]++;

        for (int next : to[now])
        {
            if (next == p)
                continue;
            dfs(dfs, next, now);
            point[now] += point[next];
        }
    };

    dfs(dfs, v[0]);

    int ans = 0;
    rep(i, n) if (point[i] > 0) ans++;

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<vector<int>> to(n);

//     rep(i, n - 1)
//     {
//         int a, b;
//         cin >> a >> b;
//         --a, --b;
//         to[a].push_back(b);
//         to[b].push_back(a);
//     }

//     vector<int> v(k);
//     vector<bool> selected(n, false);
//     rep(i, k)
//     {
//         cin >> v[i];
//         v[i]--;
//         selected[v[i]] = true;
//     }

//     vector<int> num(n);
//     auto dfs = [&](auto dfs, int now, int p = -1) -> void
//     {
//         if (selected[now])
//             num[now]++;
//         for (int next : to[now])
//         {
//             if (next == p)
//                 continue;

//             dfs(dfs, next, now);
//             num[now] += num[next];
//         }
//     };

//     dfs(dfs, v[0]);

//     int ans = 0;
//     rep(i, n) if (num[i] > 0) ans++;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n, k;
//     cin >> n >> k;

//     vector<vector<int>> to(n);
//     rep(i, n - 1)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--, b--;
//         to[a].push_back(b);
//         to[b].push_back(a);
//     }

//     vector<int> v(k);
//     vector<bool> selected(n);
//     rep(i, k)
//     {
//         cin >> v[i];
//         v[i]--;
//         selected[v[i]] = true;
//     }

//     vector<int> num(n);

//     auto dfs = [&](auto dfs, int now, int p = -1) -> void
//     {
//         if (selected[now])
//             num[now]++;
//         for (int next : to[now])
//         {
//             if (next != p)
//             {
//                 dfs(dfs, next, now);
//                 num[now] += num[next];
//             }
//         }
//     };

//     dfs(dfs, v[0]);

//     int ans = 0;
//     rep(i, n) if (num[i] > 0) ans++;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int k, n;
//     cin >> n >> k;

//     vector<vector<int>> to(n);

//     rep(i, n - 1)
//     {
//         int a, b;
//         cin >> a >> b;

//         a--, b--;

//         to[a].push_back(b);
//         to[b].push_back(a);
//     }

//     vector<int> v(k);

//     vector<bool> selected(n, false);
//     rep(i, k)
//     {
//         cin >> v[i];
//         v[i]--;

//         selected[v[i]] = true;
//     }

//     vector<int> num(n);

//     auto dfs = [&](auto dfs, int now, int p = -1) -> void
//     {
//         if (selected[now])
//             num[now]++;
//         for (int next : to[now])
//         {

//             if (next == p)
//                 continue;
//             dfs(dfs, next, now);
//             num[now] += num[next];
//         }
//     };

//     dfs(dfs, v[0]);

//     int ans = 0;
//     rep(i, n) if (num[i] > 0) ans++;

//     cout << ans << endl;

//     return 0;
// }