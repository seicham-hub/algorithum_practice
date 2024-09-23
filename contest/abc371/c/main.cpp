// https://atcoder.jp/contests/abc371/tasks/abc371_c

// めちゃ時間かかった（50分）
// 2024_09_16もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

vector<vector<bool>> input_graph(int n)
{
    vector<vector<bool>> g(n, vector<bool>(n));

    int m;
    cin >> m;
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a][b] = true;
        g[b][a] = true;
    }

    return g;
}

int main()
{
    int n;
    cin >> n;

    auto mg = input_graph(n);
    auto mh = input_graph(n);

    vector<vector<int>> a(n, vector<int>(n));

    rep(i, n - 1) rep(j, n)
    {
        if (j > i)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> p(n);
    rep(i, n) p[i] = i;

    int ans = 1e8;

    do
    {

        int tmp = 0;
        rep(i, n) rep(j, i)
        {
            if (mh[i][j] != mg[p[i]][p[j]])
            {
                tmp += a[i][j];
            }
        }

        ans = min(ans, tmp);
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// vector<vector<bool>> inputGraph(int n)
// {
//     vector<vector<bool>> g(n, vector<bool>(n));

//     int m;
//     cin >> m;
//     rep(i, m)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--, b--;
//         g[a][b] = true;
//         g[b][a] = true;
//     }

//     return g;
// }

// int main()
// {
//     int n;
//     cin >> n;

//     auto g = inputGraph(n);
//     auto h = inputGraph(n);

//     vector<vector<int>> a(n, vector<int>(n));

//     rep(i, n) rep(j, n)
//     {
//         if (j > i)
//         {
//             cin >> a[i][j];
//             a[j][i] = a[i][j];
//         }
//     }

//     int ans = 1001001001;
//     vector<int> p(n);

//     rep(i, n) p[i] = i;

//     do
//     {
//         int now = 0;

//         rep(i, n) rep(j, i)
//         {
//             if (h[i][j] != g[p[i]][p[j]])
//             {
//                 now += a[i][j];
//             }
//         }
//         ans = min(ans, now);

//     } while (next_permutation(p.begin(), p.end()));

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     int mg;
//     cin >> mg;

//     map<pair<int, int>, bool> graph_m;

//     rep(i, mg)
//     {
//         int u, v;
//         cin >> u >> v;
//         u--, v--;

//         graph_m[{u, v}] = true;
//         graph_m[{v, u}] = true;
//     }

//     int mh;
//     cin >> mh;

//     map<pair<int, int>, bool> graph_h;

//     rep(i, mh)
//     {
//         int u, v;
//         cin >> u >> v;
//         u--, v--;

//         graph_h[{u, v}] = true;
//         graph_h[{v, u}] = true;
//     }

//     vector<vector<int>> a(n, vector<int>(n));

//     rep(i, n - 1)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             cin >> a[i][j];
//             a[j][i] = a[i][j];
//         }
//     }

//     vector<int> indices;
//     rep(i, n) indices.push_back(i);

//     int ans = 1e9;

//     do
//     {
//         int tmp_cost = 0;
//         for (int node = 0; node < n; node++)
//         {
//             for (int i = node + 1; i < n; i++)
//             {
//                 int c_node = indices[node];
//                 int c_next = indices[i];
//                 if (graph_m[{node, i}] && !graph_h[{c_node, c_next}])
//                 {
//                     tmp_cost += a[c_node][c_next];
//                 }
//                 if (!graph_m[{node, i}] && graph_h[{c_node, c_next}])
//                 {
//                     tmp_cost += a[c_node][c_next];
//                 }
//             }
//         }

//         ans = min(ans, tmp_cost);

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;

//     return 0;
// }