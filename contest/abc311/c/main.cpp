// https://atcoder.jp/contests/abc311/tasks/abc311_c

// TLEで解けなかった　fuctional graph
// 2025_03_22もう一度

// 解答のコード(別解 functional graph)
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);

    rep(i, n) cin >> a[i + 1];

    vector<int> id(n + 1);

    int v = 1;
    int i = 1;
    while (id[v] == 0)
    {
        id[v] = i;
        v = a[v];
        i++;
    }

    int len = i - id[v];

    vector<int> ans;

    rep(j, len)
    {
        ans.push_back(v);
        v = a[v];
    }

    cout << ans.size() << endl;
    for (auto ai : ans)
        cout << ai << " ";

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

//     vector<int> a(n + 1);

//     rep(i, n) cin >> a[i + 1];

//     int v = 1;
//     rep(i, n) v = a[v];
//     int sv = v;

//     vector<int> ans;
//     do
//     {
//         ans.push_back(v);
//         v = a[v];
//     } while (v != sv);

//     cout << ans.size() << endl;
//     rep(i, ans.size()) cout << ans[i] << " ";

//     return 0;
// }

// 解答のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n + 1);

//     rep(i, n) cin >> a[i + 1];

//     vector<int> id(n + 1);
//     int k = 1;
//     int v = 1;

//     while (id[v] == 0)
//     {
//         id[v] = k;
//         k++;

//         v = a[v];
//     }
//     int len = k - id[v];

//     vector<int> ans;
//     rep(i, len)
//     {
//         ans.push_back(v);
//         v = a[v];
//     }

//     cout << ans.size() << endl;
//     rep(i, ans.size()) cout << ans[i] << " ";
//     cout << endl;

//     return 0;
// }

// 自分のコード
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<int>> graph(n);

//     rep(i, n)
//     {
//         int a;
//         cin >> a;
//         a--;

//         graph[i].push_back(a);
//     }

//     vector<bool> visited(n);
//     map<int, int> vtoi;

//     auto dfs = [&](auto dfs, int now, vector<int> ans)
//     {
//         visited[now] = true;
//         ans.push_back(now);
//         vtoi[now] = ans.size() - 1;

//         for (int next : graph[now])
//         {
//             if (visited[next])
//             {

//                 if (vtoi.count(next))
//                 {
//                     return vector<int>(ans.begin() + vtoi[next], ans.end());
//                 }
//             }
//             else
//                 return dfs(dfs, next, ans);
//         }
//         return vector<int>();
//     };

//     vector<int> ans;
//     ans = dfs(dfs, 0, ans);

//     if (ans.size())
//     {
//         cout << ans.size() << endl;
//         rep(j, ans.size()) cout << ans[j] + 1 << " ";
//         cout << endl;
//         return 0;
//     }

//     return 0;
// }