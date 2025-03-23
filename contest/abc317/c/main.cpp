#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using P = pair<int, int>;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<P>> graph(n);

    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }

    ll ans = 0;
    rep(st, n)
    {

        auto dfs = [&](auto dfs, int now, vector<bool> v, ll td) -> void
        {
            v[now] = true;

            for (auto [next, dist] : graph[now])
            {
                if (!v[next])
                {
                    dfs(dfs, next, v, td + dist);
                }
            }

            ans = max(ans, td);
        };

        vector<bool> visited(n, false);
        dfs(dfs, st, visited, 0);
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, m;
// long long ans = 0;
// // 町→次の町,距離
// vector<vector<pair<int, long long>>> load(n + 1);
// vector<bool> seen(n + 1, false);

// void dfs(int i, long long total, vector<bool> visited)
// {
//     visited[i] = true;
//     for (auto p : load[i])
//     {
//         int next = p.first;
//         long long diff = p.second;
//         if (!visited[next])
//             dfs(next, total + diff, visited);
//     }

//     ans = max(ans, total);
//     return;
// }

// int main()
// {

//     cin >> n >> m;

//     load.resize(n + 1);
//     seen.resize(n + 1);

//     rep(i, m)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         load[a].push_back({b, c});
//         load[b].push_back({a, c});
//     }

//     rep(j, n + 1) seen[j] = false;
//     for (int i = 1; i <= n; i++)
//     {
//         // iが始まりの町
//         dfs(i, 0, seen);
//     }

//     cout << ans << endl;

//     return 0;
// }