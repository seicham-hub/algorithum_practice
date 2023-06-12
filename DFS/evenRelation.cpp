// https://atcoder.jp/contests/abc126/tasks/abc126_d

#include <bits/stdc++.h>
using namespace std;

using Graph = map<int, pair<int, int>>;

int n;
vector<int> u, v, w, ans;

void dfs(Graph G, int i, vector<int> color)
{

    if (i == n)
    {
        ans = color;
        return;
    }
    int next = G[i].first;
    int dist = G[i].second;

    if (dist % 2 == 0)
    {
        if (color[i] != color[next] && (color[i] != -1 || color[next] != -1))
        {
            return;
        }
        else if (color[i] != -1)
        {
            color[next] = color[i] + 1;
        }
        else if (color[next] != -1)
        {
            color[i] = color[next] + 1;
        }
        else
        {
            color[i] = color[next] = 0;
            dfs(G, i + 1, color);
            color[i] = color[next] = 1;
            dfs(G, i + 1, color);
        }
    }
    else
    {
        if (color[i] == color[next] && (color[i] != -1 || color[next] != -1))
        {
            return;
        }
        if (color[i] != -1)
        {
            color[next] = (color[i] + 1) % 2;
        }
        else if (color[next] != -1)
        {
            color[i] = (color[next] + 1) % 2;
        }
        else
        {
            color[i] = 0;
            color[next] = 1;
            dfs(G, i + 1, color);
            color[i] = 1;
            color[next] = 0;
            dfs(G, i + 1, color);
        }
    }
    dfs(G, i + 1, color);
}

int main()
{

    cin >> n;
    u.resize(n - 1);
    v.resize(n - 1);
    w.resize(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    Graph G;

    for (int i = 0; i < n - 1; i++)
    {
        G[u[i]] = {v[i], w[i]};
        G[v[i]] = {u[i], w[i]};
    }

    vector<int> color(n + 1, -1);

    dfs(G, 1, color);

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}
