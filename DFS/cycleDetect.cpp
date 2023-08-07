// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

// 探索
vector<bool> seen, finished;

// サイクル復元のための情報
int pos = -1;    // サイクル中に含まれる頂点 pos
stack<int> hist; // 訪問履歴

void dfs(const Graph &G, int v, int p)
{
    seen[v] = true;
    hist.push(v);

    for (auto nv : G[v])
    {
        if (nv == p)
            continue; // 逆流を禁止する

        // 完全終了した頂点はスルー
        if (finished[nv])
            continue;

        // サイクルを検出
        if (seen[nv] && !finished[nv])
        {
            pos = nv;
            return;
        }

        dfs(G, nv, v);

        // サイクル検出したならば、まっすぐに抜けていく（順にたどっていって抜けていく）
        if (pos != -1)
            return;
    }

    hist.pop();
    finished[v] = true;
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
        --a, --b; // 頂点番号が1-indexedで与えられるので、0-indexedにする
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 探索
    seen.assign(n, false), finished.assign(n, false);
    pos = -1;
    dfs(G, 0, -1);

    // サイクルを復元
    set<int> cycle;

    while (!hist.empty())
    {
        int t = hist.top();
        cycle.insert(t);
        hist.pop();
        if (t == pos)
            break;
    }

    // クエリに答える
    int Q;
    cin >> Q;

    for (int _ = 0; _ < Q; ++_)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (cycle.count(a) && cycle.count(b))
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }

    return 0;
}
