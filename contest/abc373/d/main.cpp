#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using P = pair<int, int>;
using ll = long long;

vector<ll> ans;

void dfs(int node, vector<bool> &visited, vector<vector<P>> &graph)
{

    visited[node] = true;
    for (auto ng : graph[node])
    {
        int next = ng.first;
        int weight = ng.second;

        if (!visited[next])
        {
            ans[next] = ans[node] + weight;

            dfs(next, visited, graph);
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<P>> graph(n);

    rep(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, -w});
    }

    ans.resize(n);
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            dfs(i, visited, graph);
    }

    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}