// 計算量は
// すべての頂点を一通り調べるのでO(N)
// また、全ての枝を一通り調べるので、O(M)
// 全体ではO(N+M)の計算時間となる。

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v)
{
    seen[v] = true; // vを訪問済みにする。

    // vからいける各頂点next_vについて
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;
        dfs(G, next_v); // 再帰的に探索
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    // グラフ入力受け取り（ここでは無向グラフ）
    Graph G(N);
    for (int i = 0; i < M; i++)
    {

        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点0をスタートとし探索
    seen.assign(N, false); // 全長点を「未訪問」に初期化
    dfs(G, 0);

    return 0;
}
