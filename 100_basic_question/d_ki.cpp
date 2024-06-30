// https://atcoder.jp/contests/abc138/tasks/abc138_d
// わからなかった

// 2024_06_22もう一度
// 2024_06_24もう一度
// 2024_06_25もう一度

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

void dfs(int node, int parent, vector<int> &counter)
{

    for (int next : graph[node])
    {
        if (next == parent)
            continue;

        counter[next] += counter[node];
        dfs(next, node, counter);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    graph.resize(n);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<pair<int, int>> operations(q);

    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        --p;

        operations[i] = {p, x};
    }

    vector<int> counter(n);

    for (auto op : operations)
    {
        counter[op.first] += op.second;
    }

    dfs(0, -1, counter);

    for (int i = 0; i < n; i++)
        cout << counter[i] << " ";

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, int parent, vector<int> &counter, vector<vector<int>> &graph)
// {

//     for (int next : graph[node])
//     {
//         if (next == parent)
//             continue;
//         counter[next] += counter[node];
//         dfs(next, node, counter, graph);
//     }
// }

// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     vector<pair<int, int>> ops(q);
//     for (int i = 0; i < q; ++i)
//     {
//         int p, x;
//         cin >> p >> x;
//         --p;

//         ops[i] = {p, x};
//     }
//     vector<int> counter(n);
//     for (auto op : ops)
//     {
//         counter[op.first] += op.second;
//     }

//     dfs(0, -1, counter, graph);

//     for (int i = 0; i < n; i++)
//         cout << counter[i] << endl;

//     return 0;
// }

// お手本解答
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> to[200005];
// vector<int> ans;

// void dfs(int v, int p = -1)
// {
//     for (int u : to[v])
//     {
//         if (u == p)
//             continue;
//         ans[u] += ans[v];
//         dfs(u, v);
//     }
// }

// int main()
// {
//     int n, q;
//     cin >> n >> q;
//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         --a;
//         --b;

//         to[a].push_back(b);
//         to[b].push_back(a);
//     }

//     ans.resize(n);

//     for (int i = 0; i < q; i++)
//     {
//         int p, x;
//         cin >> p >> x;
//         --p;
//         ans[p] += x;
//     }

//     dfs(0);

//     for (int i = 0; i < n; i++)
//         cout << ans[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, vector<vector<int>> &graph, int point, vector<int> &counter, int parent = -1)
// {

//     counter[node] += point;
//     point = counter[node];

//     for (int next : graph[node])
//     {
//         if (next == parent)
//             continue;

//         dfs(next, graph, point, counter, node);
//     }
// }

// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;

//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     vector<pair<int, int>> operations(q);

//     for (int i = 0; i < q; i++)
//     {
//         int p, x;
//         cin >> p >> x;
//         p--;
//         operations[i] = {p, x};
//     }

//     vector<int> counter(n);
//     for (auto op : operations)
//     {
//         counter[op.first] += op.second;
//     }

//     dfs(0, graph, 0, counter);

//     for (int i = 0; i < counter.size(); i++)
//         cout << counter[i] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<int> counter(n, 0);

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;
//         graph[a].push_back(b);
//     }

//     vector<pair<int, int>> operation(q);

//     for (int i = 0; i < q; i++)
//     {
//         int p, x;
//         cin >> p >> x;
//         p--;
//         operation[i] = {p, x};
//     }

//     vector<vector<int>> part(n);

//     function<void(int, int)> dfs = [&](int parent, int node)
//     {
//         part[parent].push_back(node);
//         for (int next : graph[node])
//         {
//             dfs(parent, next);
//         }
//     };

//     for (int i = 0; i < n; i++)
//         dfs(i, i);

//     for (auto op : operation)
//     {
//         int node = op.first;
//         int plus = op.second;

//         for (int child : part[node])
//         {
//             counter[child] += plus;
//         }
//     }

//     for (int i = 0; i < counter.size(); i++)
//     {

//         if (i != counter.size() - 1)
//             cout << counter[i] << " ";
//         else
//             cout << counter[i] << endl;
//     }

//     return 0;
// }
