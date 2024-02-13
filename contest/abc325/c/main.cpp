// https://atcoder.jp/contests/abc325/tasks/abc325_c
// 時間かかりすぎなのでもう一度、BFSの場合も
// 0206もう一度
// 0212もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int h, w;
    cin >> h >> w;

    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

    vector<string> s(h);

    rep(i, h) cin >> s[i];
    vector<vector<bool>> vi(h, vector<bool>(w, false));

    queue<pair<int, int>> q;
    int ans = 0;

    rep(i, h)
    {
        rep(j, w)
        {
            if (s[i][j] == '#' && !vi[i][j])
            {
                q.push({i, j});
                ans++;
            }

            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                vi[x][y] = true;

                rep(k, 8)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '#' && !vi[nx][ny])
                    {
                        vi[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                q.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}

// 2/12やり直し分　dfs内部に定義する方法が分からなかった
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int h, w;
//     int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//     int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

//     cin >> h >> w;

//     vector<string> s(h);
//     vector<vector<bool>> visit(h, vector<bool>(w, false));
//     rep(i, h) cin >> s[i];

//     int ans = 0;

//     function<void(int, int)> dfs = [&](int x, int y)
//     {
//         visit[x][y] = true;

//         rep(i, 8)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if (0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '#')
//             {
//                 if (!visit[nx][ny])
//                     dfs(nx, ny);
//             }
//         }
//     };

//     rep(i, h)
//     {
//         rep(j, w)
//         {

//             if (s[i][j] == '#' && !visit[i][j])
//             {
//                 ans++;
//                 dfs(i, j);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int ans = 0;

// vector<int> dx = {0, 1, 0, -1, -1, -1, 1, 1};
// vector<int> dy = {1, 0, -1, 0, -1, 1, 1, -1};
// int h, w;
// vector<string> s(10000);

// vector<vector<bool>> ma(10000, vector<bool>(10000, false));

// void dfs(int x, int y)
// {
//     ma[x][y] = true;
//     rep(i, 8)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if (0 <= nx && nx < h && 0 <= ny && ny < w && ma[nx][ny] == false)
//         {
//             ma[nx][ny] = true;
//             if (0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '#')
//                 dfs(nx, ny);
//         }
//     }
// }

// int main()
// {

//     cin >> h >> w;

//     rep(i, h) cin >> s[i];

//     rep(i, h)
//     {
//         rep(j, w)
//         {
//             if (ma[i][j] == false && s[i][j] == '#')
//             {
//                 ans++;
//                 dfs(i, j);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }