#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

// 木上の探索
// v: 現在探索中の頂点、p:vの親（vが根の時は-1）
// 深さを追加　d: 頂点vの深さ
void dfs(const Graph &G, int v, int p, int d)
{
    for (auto nv : G[v])
    {
        if (nv == p)
            continue;
        dfs(G, nv, v, d + 1);
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

    int root = 0; // 仮に頂点0を根とする
    dfs(G, root, -1, 0);

    return 0;
}
