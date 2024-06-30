// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja

// 2024_06_24もう一度
// 2024_06_25もう一度

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
            --v;
            graph[u].push_back(v);
        }
    }

    queue<int> q;
    q.push(0);

    vector<int> dist(n, -1);
    dist[0] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int next : graph[node])
        {
            if (dist[next] == -1)
            {
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " " << dist[i] << endl;
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
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

//     queue<int> q;
//     vector<int> dist(n, -1);
//     q.push(0);
//     dist[0] = 0;

//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         for (int next : graph[node])
//         {
//             if (dist[next] == -1)
//             {
//                 dist[next] = dist[node] + 1;
//                 q.push(next);
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << i + 1 << " " << dist[i] << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

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

//     queue<pair<int, int>> q;
//     vector<int> dist(n, -1);
//     q.push({0, 0});
//     dist[0] = 0;

//     while (!q.empty())
//     {
//         auto qf = q.front();
//         int node = qf.first;
//         int diff = qf.second;

//         q.pop();

//         for (int next : graph[node])
//         {
//             if (dist[next] == -1)
//             {
//                 dist[next] = diff + 1;
//                 q.push({next, diff + 1});
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout << i + 1 << " " << dist[i] << endl;
//     }

//     return 0;
// }