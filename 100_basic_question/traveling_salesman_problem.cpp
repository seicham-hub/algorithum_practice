// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja

#include <bits/stdc++.h>
using namespace std;

// void dfs(int now, vector<int> dp, vector<bool> visited, vector<vector<pair<int, int>>> &graph)
// {
//     visited[now] = true;

//     for (auto next : graph[now])
//     {

//         if (!visited[next.first])
//         {
//             dp[1 << now] = max(dp);
//             dfs(next.first, dp, visited, graph)
//         }
//     }
// }

int main()
{
    int v, e;
    cin >> v >> e;

    vector<map<int, int>> graph(e);

    for (int i = 0; i < e; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        graph[s][t] = d;
    }

    vector<int> dp(1 << v, 0);

    for (int msk = 0; msk < 1 << v; msk++)
    {
    }

    // for (int start = 0; start < v; start++)
    // {
    //     vector<bool> visited(v, false);
    //     dfs(start, dp, visited, graph);
    // }

    return 0;
}