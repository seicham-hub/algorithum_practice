// https://atcoder.jp/contests/abc351/tasks/abc351_d

// わからなかった.. TLE

// 2025_01_26もう一度

// お手本コード
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};

using P = pair<int, int>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);

    rep(i, h) cin >> s[i];

    vector x(h, vector<bool>(w));

    rep(i, h) rep(j, w) if (s[i][j] == '#')
    {
        x[i][j] = true;

        rep(v, 4)
        {
            int ni = i + di[v], nj = j + dj[v];
            if (ni < 0 || ni >= h || nj < 0 || nj >= w)
                continue;
            x[ni][nj] = true;
        }
    }

    vector used(h, vector<bool>(w));
    vector last(h, vector<int>(w));
    int tm = 0;

    int ans = 1;
    rep(si, h) rep(sj, w) if (!x[si][sj])
    {
        if (used[si][sj])
            continue;

        tm++;
        int cnt = 0;
        queue<P> q;
        q.emplace(si, sj);
        used[si][sj] = true;

        while (!q.empty())
        {

            auto [i, j] = q.front();
            q.pop();
            cnt++;

            rep(v, 4)
            {
                int ni = i + di[v], nj = j + dj[v];
                if (ni < 0 || ni >= h || nj < 0 || nj >= w)
                    continue;
                if (used[ni][nj])
                    continue;

                if (x[ni][nj])
                {
                    if (last[ni][nj] != tm)
                        cnt++, last[ni][nj] = tm;
                    continue;
                }

                q.emplace(ni, nj);
                used[ni][nj] = true;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int h, w;
//     cin >> h >> w;

//     vector<string> grid(h);

//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};

//     rep(i, h) cin >> grid[i];

//     int ans = 0;

//     auto check = [&](int x, int y) -> bool
//     {
//         rep(i, 4)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if (nx >= 0 && nx < h && ny >= 0 && ny < w)
//                 if (grid[nx][ny] == '#')
//                     return false;
//         }

//         return true;
//     };

//     rep(i, h)
//     {
//         rep(j, w)
//         {
//             if (grid[i][j] != '#')
//             {

//                 vector<vector<bool>> visited(h, vector<bool>(w, false));
//                 int tmpans = 0;

//                 auto dfs = [&](auto dfs, int x, int y) -> void
//                 {
//                     visited[x][y] = true;
//                     tmpans++;

//                     if (!check(x, y))
//                         return;

//                     rep(i, 4)
//                     {
//                         int nx = x + dx[i];
//                         int ny = y + dy[i];
//                         if (nx >= 0 && nx < h && ny >= 0 && ny < w)
//                         {
//                             if (!visited[nx][ny] && grid[nx][ny] != '#')
//                             {

//                                 dfs(dfs, nx, ny);
//                             }
//                         }
//                     }
//                 };

//                 dfs(dfs, i, j);

//                 ans = max(ans, tmpans);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }