#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

// 木上の探索
vector<int> depth;
vector<int> subtree_size;

void dfs(const Graph &G, int v, int p, int d)
{
    depth[v] = d;
    for (auto nv : G[v])
    {
        if (nv == p)
            continue;
        dfs(G, nv, v, d + 1);
    }

    // 帰りがけ時に、部分木サイズを求める。
    subtree_size[v] = 1; // 自分自身
    for (auto c : G[v])
    {
        if (c == p)
            continue;
        subtree_size[v] += subtree_size[c];
    }
}

int main()
{
    int n;
    cin >> n;

    Graph G(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    int root = 0;
    depth.assign(n, 0);
    subtree_size.assign(n, 0);
    dfs(G, root, -1, 0);

    return 0;
}
