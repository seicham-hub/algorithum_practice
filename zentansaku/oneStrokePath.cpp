// https://atcoder.jp/contests/abc054/tasks/abc054_c

// 0421もう一度
// 0424もう一度

#include <bits/stdc++.h>
using namespace std;

bool next_node_exist(int &current_node, int &next_node, vector<vector<int>> &graph)
{
    for (int next : graph[current_node])
    {
        if (next == next_node)
            return true;
    }
    return false;
}

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> indices;

    for (int i = 0; i < n; i++)
        indices.push_back(i);

    do
    {

        if (indices[0] != 0)
            break;

        bool is_finish = true;
        for (int i = 0; i < n - 1; i++)
        {
            int current_node = indices[i];
            int next_node = indices[i + 1];

            if (!next_node_exist(current_node, next_node, graph))
            {
                is_finish = false;
                break;
            }
        }

        if (is_finish)
            ans++;

    } while (next_permutation(indices.begin(), indices.end()));

    std::cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m, ans = 0;
//     cin >> n >> m;

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;

//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     vector<int> indices;
//     for (int i = 0; i < n; i++)
//         indices.push_back(i);

//     // 0,2,4,5,1

//     do
//     {
//         if (indices[0] != 0)
//             break;

//         bool all_ok = true;
//         for (int i = 0; i < n - 1; i++)
//         {
//             bool ok = false;
//             for (int next : graph[indices[i]])
//             {
//                 if (next == indices[i + 1])
//                     ok = true;
//             }
//             if (!ok)
//                 all_ok = false;
//         }

//         if (all_ok)
//             ans++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int n, m;
// int ans = 0;

// void dfs(int node, int count, vector<vector<int>> &graph, map<int, bool> visited)
// {

//     count++;
//     visited[node] = true;

//     if (count == n)
//     {
//         ans++;
//         return;
//     }

//     for (int next : graph[node])
//     {
//         if (!visited[next])
//             dfs(next, count, graph, visited);
//     }
// }

// int main()
// {

//     cin >> n >> m;

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;

//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     dfs(0, {}, graph, {});

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int n, m, ans = 0;

// void dfs(int node, vector<vector<int>> graph, vector<int> count, map<int, bool> visited)
// {

//     count.push_back(node);
//     visited[node] = true;

//     if (count.size() == n)
//     {
//         ans++;
//         return;
//     }

//     for (int next : graph[node])
//     {
//         if (!visited[next])
//         {
//             vector<int> copy = count;
//             dfs(next, graph, copy, visited);
//         }
//     }
// }

// int main()
// {

//     cin >> n >> m;

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;

//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     map<int, bool> visited;
//     dfs(0, graph, {}, visited);

//     cout << ans << endl;

//     return 0;
// }

/*
0425解きなおし分
*/

// #include <bits/stdc++.h>
// using namespace std;

// bool g[8][8] = {};

// int main()
// {

//     int n, m, ans = 0;

//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int a, b;
//         cin >> a >> b;

//         g[a][b] = true;
//         g[b][a] = true;
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 1);

//     do
//     {
//         if (indices[0] != 1)
//             break;

//         bool ok = true;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i], next = indices[i + 1];
//             if (!g[now][next])
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//             ans++;
//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;
//     return 0;
// }

/*
0424解きなおし分
*/

// #include <bits/stdc++.h>
// using namespace std;
// bool g[8][8] = {};

// int main()
// {
//     int n, m, ans = 0;

//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         int now, next;
//         cin >> now >> next;
//         g[now][next] = true;
//         g[next][now] = true;
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 1);

//     do
//     {
//         if (indices[0] != 1)
//             break;

//         bool ok = true;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i], next = indices[i + 1];
//             if (!g[now][next])
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//             ans++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int g[8][8];

// int main()
// {

//     int n, m, ans = 0;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int v, u;
//         cin >> v >> u;
//         g[v][u] = true;
//         g[u][v] = true;
//     }

//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);

//     do
//     {
//         if (p[0] != 1)
//             continue;
//         bool ok = true;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = p[i];
//             int next = p[i + 1];

//             if (!g[now][next])
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//             ans++;

//     } while (next_permutation(p.begin(), p.end()));

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, m, a[30], b[30], ans = 0;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         cin >> a[i] >> b[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 1);

//     do
//     {
//         if (indices[0] != 1)
//             break;

//         int cnt = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i];
//             int next = indices[i + 1];

//             for (int j = 0; j < m; j++)
//             {
//                 if ((a[j] == now && b[j] == next) || (b[j] == now && a[j] == next))
//                 {
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         if (cnt == n - 1)
//             ans++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;

//     return 0;
// }
