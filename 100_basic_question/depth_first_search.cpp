// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_B&lang=ja
// 2024_06_21もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++)
    {
        int u, k;
        cin >> u >> k;
        u--;

        for (int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            v--;
            graph[u].push_back(v);
        }
    }

    vector<pair<int, int>> ans(n);
    vector<bool> visited(n, false);
    int now_time = 1;

    function<void(int)> dfs = [&](int node)
    {
        ans[node].first = now_time;
        visited[node] = true;

        for (int next : graph[node])
        {
            if (!visited[next])
            {
                now_time++;
                dfs(next);
            }
        }
        now_time++;
        ans[node].second = now_time;
    };

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            now_time++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> ans;
// vector<bool> visited;
// int now_time = 1;

// void dfs(int node, vector<vector<int>> &graph)
// {

//     visited[node] = true;
//     ans[node].first = now_time;

//     for (int next : graph[node])
//     {
//         if (!visited[next])
//         {
//             now_time++;
//             dfs(next, graph);
//         }
//     }
//     now_time++;
//     ans[node].second = now_time;
// }

// int main()
// {

//     int n;
//     cin >> n;

//     ans.resize(n);

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < n; i++)
//     {
//         int u, k;
//         cin >> u >> k;
//         u--;
//         for (int j = 0; j < k; j++)
//         {
//             int v;
//             cin >> v;
//             v--;
//             graph[u].push_back(v);
//         }
//     }

//     visited.resize(n);

//     for (int i = 0; i < n; i++)
//     {

//         if (!visited[i])
//         {
//             dfs(i, graph);
//             now_time++;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << i + 1 << " " << ans[i].first << " " << ans[i].second << endl;
//     }

//     return 0;
// }