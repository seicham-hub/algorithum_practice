#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int main()
{

    // 　頂点数と辺数
    int n, m;
    cin >> n >> m;

    // グラフ入力受け取り
    Graph G(n);

    vector<int> deg(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[b].push_back(a); // 逆向きに辺を張る
        deg[a]++;          // 出次数
    }

    // シンク達をqueueに挿入する
    queue<int> que;
    for (int i = 0; i < n; i++)
        if (deg[i] == 0)
            que.push(i);

    // 探索開始
    vector<int> order;

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        order.push_back(v);

        // vへと伸びている頂点達を探索する
        for (auto nv : G[v])
        {
            // 辺(nv,v)を削除する

            --deg[nv];

            // それによってnvが新たにシンクになったらQに追加
            if (deg[nv] == 0)
                que.push(nv);
        }
    }

    // 答えをひっくり返す
    reverse(order.begin(), order.end());
    for (auto v : order)
        cout << v << endl;

    return 0;
}
