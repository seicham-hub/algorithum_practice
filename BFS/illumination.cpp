// https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e
// 0428もう一度
// 0501もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int h, w;
    cin >> w >> h;

    vector<vector<int>> building_map(h + 2, vector<int>(w + 2, 0));

    rep(i, h)
    {
        rep(j, w)
        {
            int d;
            cin >> d;
            building_map[i + 1][j + 1] = d;
        }
    }

    int ans = 0;

    queue<pair<int, int>> q;
    vector<vector<int>> distance(h + 2, vector<int>(w + 2, -1));

    pair<int, int> start = {0, 0};
    q.push(start);
    distance[start.first][start.second] = 0;

    int dx_odd[6] = {0, 1, 0, -1, -1, 1};
    int dy_odd[6] = {1, 0, -1, 0, 1, 1};
    int dx_even[6] = {0, 1, 0, -1, -1, 1};
    int dy_even[6] = {1, 0, -1, 0, -1, -1};

    while (!q.empty())
    {
        auto now_position = q.front();
        q.pop();

        int x = now_position.first;
        int y = now_position.second;

        int now_distance = distance[x][y];

        rep(i, 6)
        {
            int nx, ny;
            if (x % 2 == 1)
            {
                nx = x + dx_odd[i];
                ny = y + dy_odd[i];
            }
            else
            {
                nx = x + dx_even[i];
                ny = y + dy_even[i];
            }

            if (0 <= nx && nx < h + 2 && 0 <= ny && ny < w + 2)
            {
                if (building_map[nx][ny] == 1)
                    ans++;
                else if (distance[nx][ny] == -1)
                {
                    q.push({nx, ny});
                    distance[nx][ny] = now_distance + 1;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int h, w, ans = 0;

//     cin >> w >> h;

//     int graph[h + 2][w + 2];

//     for (int i = 1; i <= h; i++)
//     {
//         for (int j = 1; j <= w; j++)
//         {
//             cin >> graph[i][j];
//         }
//     }

//     queue<pair<int, int>> q;
//     q.push({0, 0});

//     vector<vector<bool>> dist(h + 2, vector<bool>(w + 2, false));
//     dist[0][0] = true;

//     int dy[6] = {0, 1, 0, -1, -1, 1};
//     int dx[2][6] = {{1, 0, -1, 0, -1, -1}, {1, 0, -1, 0, 1, 1}};

//     while (!q.empty())
//     {
//         int y = q.front().first;
//         int x = q.front().second;
//         q.pop();

//         for (int i = 0; i < 6; i++)
//         {
//             int ny = y + dy[i];
//             int nx = x + dx[y % 2][i];

//             if (nx >= 0 && nx <= w + 1 && ny >= 0 && ny <= h + 1)
//             {
//                 if (graph[ny][nx] == 1)
//                     ans++;
//                 else if (!dist[ny][nx])
//                 {
//                     dist[ny][nx] = true;
//                     q.push({ny, nx});
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int w, h, ans = 0;

//     cin >> w >> h;

//     int graph[h + 2][w + 2] = {};

//     for (int i = 1; i <= h; i++)
//     {
//         for (int j = 1; j <= w; j++)
//         {
//             cin >> graph[i][j];
//         }
//     }

//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     int dx[6] = {1, 0, -1, 0, 1, -1};
//     int dy[2][6] = {{0, -1, 0, 1, -1, -1}, {0, -1, 0, 1, 1, 1}};
//     vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));

//     while (!q.empty())
//     {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();

//         for (int i = 0; i < 6; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[x % 2][i];

//             if (nx >= 0 && nx <= h + 1 && ny >= 0 && ny <= w + 1)
//             {
//                 if (graph[nx][ny] == 1)
//                 {
//                     ans++;
//                 }
//                 else if (graph[nx][ny] == 0 && visited[nx][ny] == false)
//                 {
//                     q.push({nx, ny});
//                     visited[nx][ny] = true;
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <string>
// #include <cstring>
// #include <cctype>
// #include <cmath>
// #include <stack>
// #include <queue>
// #include <vector>
// #include <set>
// #include <map>
// #include <list>
// #include <stdio.h>
// #include <string.h>
// #include <cstdlib>
// #include <math.h>
// #include <bitset>
// #define INF 2000000000
// using namespace std;
// int Dx[4] = {1, 0, -1, 0}, Dy[4] = {0, 1, 0, -1};
// typedef long long ll;
// #define PL pair<long long, long long>
// #define P pair<int, int>
// #define mk make_pair
// #define en endl;
// #define WHITE 0
// #define BLACK 2
// #define GRAY 1
// #define RE return 0;
// #define HERE cout << "         here" << en
// #define out(value) cout << value << en

// #define rep(i, n) for (int i = 0; i < (n); i++)

// using namespace std;

// const int dx[2][6] = {{1, 0, -1, -1, -1, 0}, {1, 1, 0, -1, 0, 1}}, dy[6] = {0, -1, -1, 0, 1, 1};

// int main()
// {
//     int h, w;
//     scanf("%d%d", &w, &h);
//     int B[102][102] = {0};
//     rep(i, h) rep(j, w) scanf("%d", B[i + 1] + j + 1);

//     h += 2;
//     w += 2;

//     bool vis[102][102] = {};
//     vis[0][0] = true;

//     int ans = 0;
//     queue<pair<int, int>> Q;
//     Q.push(make_pair(0, 0));
//     while (!Q.empty())
//     {
//         int y = Q.front().first, x = Q.front().second;
//         Q.pop();
//         rep(k, 6)
//         {
//             int yy = y + dy[k], xx = x + dx[y % 2][k];
//             if (0 <= yy && yy < h && 0 <= xx && xx < w && !vis[yy][xx])
//             {
//                 if (B[yy][xx] == 1)
//                     ans++;
//                 else
//                 {
//                     vis[yy][xx] = true;
//                     Q.push(make_pair(yy, xx));
//                 }
//             }
//         }
//     }
//     printf("%d\n", ans);

//     return 0;
// }

// #include "bits/stdc++.h"
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// #define INF 1 << 30
// #define LINF 1LL << 60

// // odd
// int dx1[6] = {1, 1, 0, -1, 0, 1};
// int dy1[6] = {0, -1, -1, 0, 1, 1};

// int dx2[6] = {1, 0, -1, -1, -1, 0};
// int dy2[6] = {0, -1, -1, 0, 1, 1};

// int main(void)
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);
//     ll W, H;
//     cin >> W >> H;
//     vector<vector<ll>> masu(H + 2, vector<ll>(W + 2, 0));
//     for (int i = 1; i <= H; i++)
//     {
//         for (int j = 1; j <= W; j++)
//         {
//             cin >> masu[i][j];
//         }
//     }

//     vector<vector<ll>> masu_check(H + 2, vector<ll>(W + 2, 0));

//     queue<pii> q;
//     q.push({0, 0});
//     masu_check[0][0] = 1;
//     while (!q.empty())
//     {
//         auto p = q.front();
//         q.pop();
//         int i = p.first, j = p.second;
//         for (int k = 0; k < 6; k++)
//         {
//             int nx, ny;
//             if (i % 2 == 1)
//             {
//                 nx = j + dx1[k];
//                 ny = i + dy1[k];
//             }
//             else
//             {
//                 nx = j + dx2[k];
//                 ny = i + dy2[k];
//             }
//             if (nx < 0 || nx > W + 1)
//                 continue;
//             if (ny < 0 || ny > H + 1)
//                 continue;
//             if (masu[ny][nx] == 1)
//                 continue;
//             if (masu_check[ny][nx] == 1)
//                 continue;
//             q.push({ny, nx});
//             masu_check[ny][nx] = 1;
//         }
//     }

//     ll ans = 0;
//     for (int i = 1; i <= H; i++)
//     {
//         for (int j = 1; j <= W; j++)
//         {
//             if (masu[i][j] == 1)
//             {
//                 int cnt = 0;
//                 for (int k = 0; k < 6; k++)
//                 {
//                     int nx, ny;
//                     if (i % 2 == 1)
//                     {
//                         nx = j + dx1[k];
//                         ny = i + dy1[k];
//                     }
//                     else
//                     {
//                         nx = j + dx2[k];
//                         ny = i + dy2[k];
//                     }
//                     if (masu[ny][nx] == 0)
//                     {
//                         if (masu_check[ny][nx] == 1)
//                             cnt++;
//                     }
//                 }
//                 ans += cnt;
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }