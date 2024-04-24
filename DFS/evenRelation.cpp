// https://atcoder.jp/contests/abc126/tasks/abc126_d

// 0616もう一度
// 0617もう一度　vectorの構造　時間かかりすぎ
// グラフは初期位置を決めて、それに隣接するものをたどっていく。無向の場合は逆の物も入れる。

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int n;

void dfs(int node, int color, vector<int> &ans, vector<vector<pair<int, int>>> &graph, vector<bool> &visited)
{

    ans[node] = color;
    visited[node] = true;

    for (pair<int, int> g : graph[node])
    {
        int next_node = g.first;
        int dist = g.second;

        int next_color = dist % 2 == 0 ? color : (color + 1) % 2;

        if (!visited[next_node])
            dfs(next_node, next_color, ans, graph, visited);
    }
    return;
}

int main()
{

    cin >> n;

    vector<vector<pair<int, int>>> graph(n);

    rep(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<bool> visited(n);
    vector<int> ans(n);
    ans[0] = 0;
    dfs(0, 0, ans, graph, visited);

    for (auto a : ans)
        cout << a << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// #define rep(i, n) for (int i = 0; i < n; ++i)

// vector<bool> visted(100030, false);

// void dfs(int node, int color, vector<int> &ans, vector<vector<pair<int, int>>> &graph)
// {
//     visted[node] = true;
//     for (auto g : graph[node])
//     {
//         int next_node = g.first;
//         int dist = g.second;

//         int next_color = dist % 2 == 0 ? color : (color + 1) % 2;
//         ans[next_node] = next_color;

//         if (!visted[next_node])
//             dfs(next_node, next_color, ans, graph);
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;

//     vector<vector<pair<int, int>>> graph(n);

//     rep(i, n - 1)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;
//         u--;
//         v--;

//         graph[u].push_back({v, w});
//         graph[v].push_back({u, w});
//     }

//     vector<int> ans(n);

//     dfs(0, 0, ans, graph);

//     for (auto a : ans)
//         cout << a << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define rep(i, n) for (int i = 0; i < n; ++i)

// vector<int> c;
// map<int, vector<pair<int, int>>> graph;

// void dfs(int now, int color = 0)
// {
//     c[now] = color;
//     for (auto g : graph[now])
//     {
//         int next = g.first;
//         int dist = g.second;

//         if (c[next] != -1)
//             continue;

//         if (dist % 2 == 0)
//             dfs(next, color);
//         else
//             dfs(next, (color + 1) % 2);
//     }

//     return;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     c.resize(n + 1, -1);
//     vector<int> u(n - 1), v(n - 1), w(n - 1);

//     rep(i, n - 1)
//     {
//         cin >> u[i] >> v[i] >> w[i];
//         graph[u[i]].push_back({v[i], w[i]});
//         graph[v[i]].push_back({u[i], w[i]});
//     }

//     dfs(1);

//     for (int i = 1; i <= n; i++)
//     {

//         cout << c[i] << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// #define rep(i, n) for (int i = 0; i < n; ++i)

// int N;
// vector<pair<int, int>> E[101010];
// int ans[101010];

// void dfs(int cu, int pa = -1, int col = 0)
// {
//     ans[cu] = col;
//     for (auto p : E[cu])
//     {
//         if (p.first == pa)
//             continue;

//         if (p.second % 2 == 0)
//             dfs(p.first, cu, col);
//         else
//             dfs(p.first, cu, 1 - col);
//     }
// }

// int main()
// {
//     cin >> N;
//     rep(i, N - 1)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--;
//         b--;

//         E[a].push_back({b, c});
//         E[b].push_back({a, c});
//     }

//     dfs(0);

//     for (int i = 0; i < N; i++)
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }

// TLE,RE 自分で書いたコード

// #include <bits/stdc++.h>
// using namespace std;

// int n;

// vector<int> u, v, w, ans;
// using Graph = map<pair<int, int>, bool>;
// Graph mp;

// void dfs(vector<int> c, int ni)
// {

//     if (ni >= n - 1)
//     {
//         ans = c;
//         return;
//     }

//     int nexti = ni + 1;

//     if (w[ni] % 2 == 0)
//     {
//         if (c[u[ni]] != -1)
//         {
//             c[v[ni]] = c[u[ni]];
//             dfs(c, nexti);
//         }
//         else if (c[v[ni]] != -1)
//         {
//             c[u[ni]] = c[v[ni]];
//             dfs(c, nexti);
//         }
//         else
//         {
//             c[u[ni]] = c[v[ni]] = 0;
//             dfs(c, ni++);
//             c[u[ni]] = c[v[ni]] = 0;
//             dfs(c, nexti);
//         }
//     }
//     else
//     {
//         if (c[u[ni]] != -1)
//         {
//             c[v[ni]] = (c[u[ni]] + 1) % 2;
//             dfs(c, nexti);
//         }
//         else if (c[v[ni]] != -1)
//         {
//             c[u[ni]] = (c[v[ni]] + 1) % 2;
//             dfs(c, nexti);
//         }
//         else
//         {

//             c[u[ni]] = 1;
//             c[v[ni]] = 0;
//             dfs(c, nexti);
//             c[u[ni]] = 0;
//             c[v[ni]] = 1;
//             dfs(c, nexti);
//         }
//     }

//     return;
// }

// int main()
// {

//     cin >> n;
//     vector<int> color(n + 1, -1);
//     u.resize(n - 1);
//     v.resize(n - 1);
//     w.resize(n - 1);

//     for (int i = 0; i < n - 1; i++)
//     {
//         cin >> u[i] >> v[i] >> w[i];
//         mp[{u[i], v[i]}] = true;
//         mp[{v[i], u[i]}] = true;
//     }

//     dfs(color, 0);

//     for (int i = 1; i <= n; i++)
//     {

//         cout << ans[i] << endl;
//     }

//     return 0;
// }
