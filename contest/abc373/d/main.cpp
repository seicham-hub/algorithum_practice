// https://atcoder.jp/contests/abc373/tasks/abc373_d

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using P = pair<int, int>;
using ll = long long;

struct Edge
{
    int to, w;
};

int main()
{
    int n, m;

    cin >> n >> m;

    vector<vector<Edge>> g(n);

    rep(i, m)
    {
        int u, v, w;
        Edge e1, e2;
        cin >> u >> v >> w;
        u--;
        v--;

        e1.to = v;
        e1.w = w;
        e2.to = u;
        e2.w = -w;

        g[u].emplace_back(e1);
        g[v].emplace_back(e2);
    }

    vector<bool> used(n);
    vector<ll> x(n);

    rep(sv, n)
    {
        if (used[sv])
            continue;

        auto dfs = [&](auto dfs, int v, ll val)
        {
            if (used[v])
                return;

            used[v] = true;
            x[v] = val;

            for (Edge e : g[v])
            {
                dfs(dfs, e.to, val + e.w);
            }
        };
        dfs(dfs, sv, 0);
    }

    rep(i, n) cout << x[i] << " ";
    cout << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using P = pair<int, int>;
// using ll = long long;

// vector<ll> ans;

// void dfs(int node, vector<bool> &visited, vector<vector<P>> &graph)
// {

//     visited[node] = true;
//     for (auto ng : graph[node])
//     {
//         int next = ng.first;
//         int weight = ng.second;

//         if (!visited[next])
//         {
//             ans[next] = ans[node] + weight;

//             dfs(next, visited, graph);
//         }
//     }
// }

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     vector<vector<P>> graph(n);

//     rep(i, m)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         u--, v--;

//         graph[u].push_back({v, w});
//         graph[v].push_back({u, -w});
//     }

//     ans.resize(n);
//     vector<bool> visited(n, false);

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//             dfs(i, visited, graph);
//     }

//     for (auto a : ans)
//         cout << a << " ";
//     cout << endl;

//     return 0;
// }