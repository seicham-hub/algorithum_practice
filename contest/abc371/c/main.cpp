#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    int mg;
    cin >> mg;

    map<pair<int, int>, bool> graph_m;

    rep(i, mg)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph_m[{u, v}] = true;
        graph_m[{v, u}] = true;
    }

    int mh;
    cin >> mh;

    map<pair<int, int>, bool> graph_h;

    rep(i, mh)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        graph_h[{u, v}] = true;
        graph_h[{v, u}] = true;
    }

    vector<vector<int>> a(n, vector<int>(n));

    rep(i, n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    vector<int> indices;
    rep(i, n) indices.push_back(i);

    int ans = 1e9;

    do
    {
        int tmp_cost = 0;
        for (int node = 0; node < n; node++)
        {
            for (int i = node + 1; i < n; i++)
            {
                int c_node = indices[node];
                int c_next = indices[i];
                if (graph_m[{node, i}] && !graph_h[{c_node, c_next}])
                {
                    tmp_cost += a[c_node][c_next];
                }
                if (!graph_m[{node, i}] && graph_h[{c_node, c_next}])
                {
                    tmp_cost += a[c_node][c_next];
                }
            }
        }

        ans = min(ans, tmp_cost);

    } while (next_permutation(indices.begin(), indices.end()));

    cout << ans << endl;

    return 0;
}