#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    int h, w;
    cin >> h >> w;

    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    vector<vector<int>> grid(h, vector<int>(w));

    rep(i, h) rep(j, w)
    {

        cin >> grid[i][j];
    }

    int ans = 0;

    auto dfs = [&](auto dfs, int x, int y, vector<int> trace) -> void
    {
        trace.emplace_back(grid[x][y]);

        if (x == h - 1 && y == w - 1)
        {

            bool ok = true;
            set<int> tmp;
            rep(i, trace.size())
            {
                if (tmp.count(trace[i]))
                    ok = false;
                tmp.insert(trace[i]);
            }
            if (ok)
                ans++;

            return;
        }

        rep(i, 2)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < h && ny >= 0 && ny < w)
            {
                dfs(dfs, nx, ny, trace);
            }
        }
    };

    vector<int> tmp;

    dfs(dfs, 0, 0, tmp);

    cout << ans << endl;

    return 0;
}