// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e

// 0427もう一回
// 0428もう一度
// チーズに硬さあるんなら順番つけて回ればいいじゃない
// someArr[(int)char型]などは正しくキャストされないからダメ

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int h, w, n, ans = 0;
    cin >> h >> w >> n;

    char kukakuMap[h + 1][w + 1];
    vector<pair<int, int>> position(n + 1);

    for (int i = 1; i <= h; i++)
    {

        for (int j = 1; j <= w; j++)
        {
            cin >> kukakuMap[i][j];
            if (kukakuMap[i][j] == 'S')
            {
                position[0] = {i, j};
            }
            else if ('0' <= kukakuMap[i][j] && kukakuMap[i][j] <= '9')
            {
                position[kukakuMap[i][j] - '0'] = {i, j};
            }
        }
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int num = 0; num < n; num++)
    {

        queue<pair<int, int>> q;

        vector<vector<int>> dist(h + 1, vector<int>(w + 1, -1));

        dist[position[num].first][position[num].second] = 0;

        q.push({position[num].first, position[num].second});

        while (!q.empty())
        {
            int x, y;
            x = q.front().first;
            y = q.front().second;
            q.pop();

            if (kukakuMap[x][y] == num + 1 + '0')
            {
                ans += dist[x][y];
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && dist[nx][ny] == -1 && kukakuMap[nx][ny] != 'X')
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

/*
解答
*/
// #include <bits/stdc++.h>
// using namespace std;

// typedef tuple<int, int, int> Node;

// int main()
// {
//     int H, W, N;

//     cin >> H >> W >> N;
//     vector<string> grid(H);

//     for (int i = 0; i < H; i++)
//     {
//         cin >> grid[i];
//     }

//     vector<pair<int, int>> positions(N + 1);

//     for (int i = 0; i < H; i++)
//     {
//         for (int j = 0; j < W; j++)
//         {
//             if (grid[i][j] == 'S')
//             {
//                 positions[0] = {i, j};
//             }
//             else if ('0' <= grid[i][j] && grid[i][j] <= '9')
//             {
//                 int cheese = grid[i][j] - '0';
//                 positions[cheese] = {i, j};
//             }
//         }
//     }

//     int ans = 0;
//     int dx[] = {0, 1, 0, -1};
//     int dy[] = {1, 0, -1, 0};

//     for (int i = 0; i < N; i++)
//     {
//         vector<vector<bool>> visited(H, vector<bool>(W, false));
//         queue<Node> q;
//         q.push({positions[i].first, positions[i].second, 0});

//         while (!q.empty())
//         {
//             int x, y, d;
//             tie(x, y, d) = q.front();
//             q.pop();
//             if (x == positions[i + 1].first && y == positions[i + 1].second)
//             {
//                 ans += d;
//                 break;
//             }

//             for (int j = 0; j < 4; j++)
//             {
//                 int nx = x + dx[j];
//                 int ny = y + dy[j];
//                 if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] != 'X')
//                 {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny, d + 1});
//                 }
//             }
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

// 自分で書いたコード　単純に最初から全探索しているからダメ
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int h, w, n, direction[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, ans;
//     vector<vector<int>> initq(1);

//     cin >> h >> w >> n;

//     char kukaku[h + 1][w + 1];

//     for (int i = 1; i <= h; i++)
//     {
//         for (int j = 1; j <= w; j++)
//         {
//             cin >> kukaku[i][j];
//             if (kukaku[i][j] == 'S')
//                 initq[0] = {i, j};
//         }
//     }

//     queue<vector<int>> q;

//     int life = 1, dist[h + 1][w + 1];
//     for (int i = 1; i <= h; i++)
//     {
//         for (int j = 1; j <= w; j++)
//         {
//             dist[i][j] = -1;
//         }
//     }

//     q.push(initq[0]);
//     dist[initq[0][0]][initq[0][1]] = 0;

//     while (!q.empty())
//     {
//         vector<int> cur = q.front();
//         q.pop();
//         cout << cur[0] << cur[1] << endl;

//         for (int i = 0; i < 4; i++)
//         {
//             int nextY = cur[0] + direction[i][0];
//             int nextX = cur[1] + direction[i][1];

//             if (nextY != 0 && nextX != 0 && dist[nextY][nextX] == -1 && kukaku[nextY][nextX] != 'X')
//             {
//                 int hardNum = kukaku[nextY][nextX] - '0';

//                 if (0 <= hardNum && hardNum <= 9)
//                 {
//                     if (life < hardNum)
//                         continue;
//                     else if (hardNum == n)
//                     {
//                         ans = dist[cur[0]][cur[1]] + 1;
//                         break;
//                     }
//                     life++;
//                 }
//                 dist[nextY][nextX] = dist[cur[0]][cur[1]] + 1;
//                 q.push({nextY, nextX});
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <tuple>
// using namespace std;

// typedef tuple<int, int, int> Node;

// int main()
// {
//     int H, W, N;
//     cin >> H >> W >> N;
//     vector<string> grid(H);
//     for (int i = 0; i < H; ++i)
//     {
//         cin >> grid[i];
//     }

//     vector<pair<int, int>> positions(N + 1);
//     for (int i = 0; i < H; ++i)
//     {
//         for (int j = 0; j < W; ++j)
//         {
//             if (grid[i][j] == 'S')
//             {
//                 positions[0] = {i, j};
//             }
//             else if (isdigit(grid[i][j]))
//             {
//                 int cheese = grid[i][j] - '0';
//                 positions[cheese] = {i, j};
//             }
//         }
//     }

//     int ans = 0;
//     int dx[] = {0, 1, 0, -1};
//     int dy[] = {1, 0, -1, 0};
//     for (int i = 0; i < N; ++i)
//     {
//         vector<vector<bool>> visited(H, vector<bool>(W, false));
//         queue<Node> q;
//         q.push({positions[i].first, positions[i].second, 0});

//         while (!q.empty())
//         {
//             int x, y, d;
//             tie(x, y, d) = q.front();
//             q.pop();

//             if (x == positions[i + 1].first && y == positions[i + 1].second)
//             {
//                 ans += d;
//                 break;
//             }

//             for (int j = 0; j < 4; ++j)
//             {
//                 int nx = x + dx[j];
//                 int ny = y + dy[j];

//                 if (nx >= 0 && nx < H && ny >= 0 && ny < W && !visited[nx][ny] && grid[nx][ny] != 'X')
//                 {
//                     visited[nx][ny] = true;
//                     q.push({nx, ny, d + 1});
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }