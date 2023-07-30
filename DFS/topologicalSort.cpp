#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ

void rec(int v, const Graph &G, vector<bool> &seen, vector<int> &order)
{
    seen[v] = true;
    for (auto next : G[v])
    {
        if (seen[next])
            continue; // すでに訪問済みならスキップ
        rec(next, G, seen, order);
    }

    order.push_back(v);
}

int main()
{
    int n, m;
    cin >> n >> m; // 超点数と枝数
    Graph G(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    // 探索
    vector<bool> seen(n, 0);
    vector<int> order; // トポロジカルソート順

    for (int v = 0; v < n; v++)
    {
        if (seen[v])
            continue; // すでに訪問済みならスキップ
        rec(v, G, seen, order);
    }

    reverse(order.begin(), order.end());

    for (auto v : order)
    {

        cout << v << "->";
    }

    return 0;
}
