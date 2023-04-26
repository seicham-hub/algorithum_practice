// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja

// 0426もう一度

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> graph(n + 1);

//     for (int i = 0; i < n; i++)
//     {
//         int u, k;
//         cin >> u >> k;
//         graph[u].resize(k);
//         for (int j = 0; j < k; j++)
//         {
//             cin >> graph[u][j];
//         }
//     }

//     vector<int> distance(n + 1, -1);
//     distance[1] = 0;
//     queue<int> q;
//     q.push(1);

//     while (!q.empty())
//     {
//         int current = q.front();
//         q.pop();
//         for (int neighbor : graph[current])
//         {
//             if (distance[neighbor] == -1)
//             {
//                 distance[neighbor] = distance[current] + 1;
//                 q.push(neighbor);
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << i << " " << distance[i] << endl;
//     }

//     return 0;
// }
