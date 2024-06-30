// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp

// 2024_06_25もう一度
// 2024_07_01もう一度

#include <bits/stdc++.h>
using namespace std;

bool is_valid(int &nx, int &ny, int &w, int &h, vector<vector<int>> &dist)
{
    return 0 <= nx && nx < h && 0 <= ny && ny < w && dist[nx][ny] == 0;
}

int main()
{

    while (true)
    {

        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        vector<vector<int>> horizontal_wall(h, vector<int>(w - 1));
        vector<vector<int>> vertical_wall(h, vector<int>(w));

        for (int i = 0; i < 2 * h - 1; i++)
        {
            if (i % 2 == 0)
                for (int j = 0; j < w - 1; j++)
                    cin >> horizontal_wall[i / 2][j];
            else
                for (int j = 0; j < w; j++)
                    cin >> vertical_wall[i / 2][j];
        }

        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> dist(h, vector<int>(w, 0));
        dist[0][0] = 1;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!q.empty())
        {
            auto xy = q.front();
            q.pop();

            int x = xy.first;
            int y = xy.second;
            // 壁だったらいけない、すでに訪れていてもいけない

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!is_valid(nx, ny, w, h, dist))
                    continue;

                bool can_move = false;

                if (i == 0)
                    can_move = horizontal_wall[x][y] == 0;
                if (i == 2)
                    can_move = horizontal_wall[x][y - 1] == 0;
                if (i == 1)
                    can_move = vertical_wall[x][y] == 0;
                if (i == 3)
                    can_move = vertical_wall[x - 1][y] == 0;

                if (can_move)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        cout << dist[h - 1][w - 1] << endl;
    }

    return 0;
}

// // お手本コード
// #include <iostream>
// #include <vector>
// #include <queue>
// #include <utility>
// #include <cstring>

// using namespace std;

// int w, h;
// int horizontal_walls[30][29];
// int vertical_walls[29][30];
// int dist[30][30];

// int dx[4] = {1, -1, 0, 0};
// int dy[4] = {0, 0, 1, -1};

// bool is_valid(int x, int y)
// {
//     return x >= 0 && x < h && y >= 0 && y < w;
// }

// int bfs()
// {
//     memset(dist, -1, sizeof(dist));
//     queue<pair<int, int>> q;
//     q.push({0, 0});
//     dist[0][0] = 1;

//     while (!q.empty())
//     {
//         auto [x, y] = q.front();
//         q.pop();

//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if (!is_valid(nx, ny))
//                 continue;

//             bool can_move = false;
//             if (i == 0 && !vertical_walls[x][y])
//                 can_move = true; // Down
//             if (i == 1 && !vertical_walls[x - 1][y])
//                 can_move = true; // Up
//             if (i == 2 && !horizontal_walls[x][y])
//                 can_move = true; // Right
//             if (i == 3 && !horizontal_walls[x][y - 1])
//                 can_move = true; // Left

//             if (can_move && dist[nx][ny] == -1)
//             {
//                 dist[nx][ny] = dist[x][y] + 1;
//                 q.push({nx, ny});
//                 if (nx == h - 1 && ny == w - 1)
//                     return dist[nx][ny];
//             }
//         }
//     }

//     return 0;
// }

// int main()
// {
//     while (cin >> w >> h)
//     {
//         if (w == 0 && h == 0)
//             break;

//         for (int i = 0; i < 2 * h - 1; i++)
//         {
//             if (i % 2 == 0)
//             {
//                 for (int j = 0; j < w - 1; j++)
//                 {
//                     cin >> horizontal_walls[i / 2][j];
//                 }
//             }
//             else
//             {
//                 for (int j = 0; j < w; j++)
//                 {
//                     cin >> vertical_walls[i / 2][j];
//                 }
//             }
//         }

//         int result = bfs();
//         cout << result << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     while (true)
//     {

//         int w, h;

//         cin >> w >> h;

//         if (w == 0 && h == 0)
//             break;

//         vector<vector<int>> walls(2 * h - 1, vector<int>(w, -1));

//         for (int i = 0; i < 2 * h - 1; i++)
//         {
//             if (i % 2 == 0)
//                 for (int j = 0; j < w - 1; j++)
//                     cin >> walls[i][j];
//             else
//                 for (int j = 0; j < w; j++)
//                     cin >> walls[i][j];
//         }

//         queue<pair<int, int>> q;
//         q.push({0, 0});
//         vector<vector<int>> dist(h, vector<int>(w, 0));
//         dist[0][0] = 1;

//         int dx[4] = {0, 1, 0, -1};
//         int dy[4] = {1, 0, -1, 0};

//         while (!q.empty())
//         {
//             auto xy = q.front();
//             q.pop();
//             int x = xy.first;
//             int y = xy.second;

//             for (int i = 0; i < 4; i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];

//                 if (0 <= nx && nx < h && 0 <= ny && ny < w && dist[nx][ny] == 0)
//                 {
//                     // 左右移動
//                     if (nx - x == 0)
//                     {
//                         // 右移動
//                         if (ny - y > 0 && walls[2 * x][y] == 0)
//                         {
//                             dist[nx][ny] = dist[x][y] + 1;
//                             q.push({nx, ny});
//                         }
//                         // 左移動
//                         else if (ny - y < 0 && 1 <= y && y < w + 1 && walls[2 * x][y - 1] == 0)
//                         {
//                             dist[nx][ny] = dist[x][y] + 1;
//                             q.push({nx, ny});
//                         }
//                     }
//                     // 上下移動
//                     else
//                     {
//                         // 下移動

//                         if (nx - x > 0 && x < h - 1 && walls[2 * x + 1][y] == 0)
//                         {
//                             dist[nx][ny] = dist[x][y] + 1;
//                             q.push({nx, ny});
//                         }

//                         // 上移動
//                         else if (nx - x < 0 && 1 <= x && walls[2 * x - 1][y] == 0)
//                         {
//                             dist[nx][ny] = dist[x][y] + 1;
//                             q.push({nx, ny});
//                         }
//                     }
//                 }
//             }
//         }

//         cout << dist[h - 1][w - 1] << endl;
//     }

//     return 0;
// }