// https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e

// 0427もう一回
// 0428もう一度
// チーズに硬さあるんなら順番つけて回ればいいじゃない
// someArr[(int)char型]などは正しくキャストされないからダメ

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> city_map(h, vector<char>(w));

    vector<pair<int, int>> start_end_position(n + 1);

    rep(i, h)
    {
        rep(j, w)
        {
            char c;
            cin >> c;
            city_map[i][j] = c;

            if (c == 'S')
                start_end_position[0] = {i, j};

            if ('1' <= c && c <= '9')
            {
                start_end_position[c - '0'] = {i, j};
            }
        }
    }

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int ans = 0;

    rep(i, n)
    {

        queue<pair<int, int>> q;
        vector<vector<int>> travel_time(h, vector<int>(w, -1));

        auto start = start_end_position[i];
        auto goal = start_end_position[i + 1];
        q.push(start);
        travel_time[start.first][start.second] = 0;

        int time = -1;

        while (!q.empty())
        {
            auto now_position = q.front();
            q.pop();

            int x = now_position.first;
            int y = now_position.second;

            int now_time = travel_time[x][y];

            if (now_position == goal)
            {
                time = now_time;
                break;
            }
            rep(d, 4)
            {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (0 <= nx && nx < h && 0 <= ny && ny < w && city_map[nx][ny] != 'X')
                {

                    if (travel_time[nx][ny] == -1)
                    {
                        q.push({nx, ny});
                        travel_time[nx][ny] = now_time + 1;
                    }
                }
            }
        }

        ans += time;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int h, w, n;

// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

// int calc_time_to_goal(pair<int, int> &start, pair<int, int> &goal, vector<vector<char>> &city_map)
// {

//     // 現在位置に隣接するマスを管理するqueue
//     queue<pair<int, int>> q;
//     // マスに移動するのにかかる最小時間を管理するgrid
//     vector<vector<int>> travel_time(h, vector<int>(w, -1));

//     int start_x = start.first;
//     int start_y = start.second;

//     // 出発位置と出発位置からの経過時間を追加
//     q.push({start_x, start_y});
//     travel_time[start_x][start_y] = 0;

//     int time = -1;

//     while (!q.empty())
//     {
//         auto now_position = q.front();
//         q.pop();
//         int x = now_position.first;
//         int y = now_position.second;

//         int now_travel_time = travel_time[x][y];

//         if (now_position == goal)
//         {
//             time = now_travel_time;
//             break;
//         }

//         // 現在区画から東西南北４方向へ探索
//         rep(d, 4)
//         {
//             int nx = x + dx[d];
//             int ny = y + dy[d];

//             // 障害物のないマップ範囲内かつ訪れたことがない場合
//             if (0 <= nx && nx < h && 0 <= ny && ny < w && city_map[nx][ny] != 'X')
//             {
//                 if (travel_time[nx][ny] == -1)
//                 {
//                     q.push({nx, ny});
//                     travel_time[nx][ny] = now_travel_time + 1;
//                 }
//             }
//         }
//     }

//     return time;
// }

// int main()
// {

//     cin >> h >> w >> n;
//     vector<vector<char>> city_map(h, vector<char>(w));

//     vector<pair<int, int>> start_goal_position(n + 1);

//     rep(i, h)
//     {
//         rep(j, w)
//         {
//             char c;
//             cin >> c;
//             city_map[i][j] = c;

//             if (c == 'S')
//                 start_goal_position[0] = {i, j};
//             if ('1' <= c && c <= '9')
//             {
//                 start_goal_position[c - '0'] = {i, j};
//             }
//         }
//     }

//     int ans = 0;

//     // チーズは順番にしか食べられないので、それぞれのチーズの位置をゴールにして最短時間を求める
//     rep(i, n)
//     {
//         // スタート、ゴール位置を設定
//         pair<int, int> start = start_goal_position[i];
//         pair<int, int> goal = start_goal_position[i + 1];

//         int tmp_time = calc_time_to_goal(start, goal, city_map);

//         ans += tmp_time;
//     }

//     cout << ans << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int h, w, n;
//     cin >> h >> w >> n;

//     vector<vector<char>> mp(h, vector<char>(w));

//     pair<int, int> start;
//     vector<pair<int, int>> cheeze(n);

//     vector<int> dx = {0, 1, 0, -1};
//     vector<int> dy = {1, 0, -1, 0};

//     rep(i, h)
//     {
//         rep(j, w)
//         {
//             char c;
//             cin >> c;
//             mp[i][j] = c;
//             if (c == 'S')
//                 start = {i, j};
//             if ('1' <= c && c <= '9')
//             {
//                 cheeze[c - '1'] = {i, j};
//             }
//         }
//     }

//     int ans = 0;

//     rep(i, n)
//     {

//         map<pair<int, int>, bool> visited;

//         queue<pair<pair<int, int>, int>> q;
//         if (i == 0)
//             q.push({start, 0});
//         if (i > 0)
//             q.push({cheeze[i - 1], 0});

//         int min_diff = 0;

//         while (!q.empty())
//         {
//             auto top = q.front();
//             q.pop();

//             auto xy = top.first;
//             int x = xy.first;
//             int y = xy.second;
//             int now_diff = top.second;

//             if (cheeze[i] == xy)
//             {
//                 min_diff = now_diff;
//                 break;
//             }

//             rep(i, 4)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];

//                 if (nx >= 0 && nx < h && ny >= 0 && ny < w && mp[nx][ny] != 'X')
//                 {
//                     if (!visited[{nx, ny}])
//                         q.push({{nx, ny}, now_diff + 1});
//                     visited[{nx, ny}] = true;
//                 }
//             }
//         }

//         ans += min_diff;
//     }

//     std::cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int h, w, n, ans = 0;

//     cin >> h >> w >> n;

//     string graph[h];
//     vector<pair<int, int>> position(n + 1);

//     for (int i = 0; i < h; i++)
//     {
//         cin >> graph[i];
//         for (int j = 0; j < w; j++)
//         {
//             if (graph[i][j] == 'S')
//             {
//                 position[0] = {i, j};
//             }
//             if (graph[i][j] >= '1' && graph[i][j] <= '9')
//             {
//                 int cheese = graph[i][j] - '0';
//                 position[cheese] = {i, j};
//             }
//         }
//     }

//     int dx[4] = {1, 0, -1, 0};
//     int dy[4] = {0, -1, 0, 1};

//     for (int i = 0; i < n; i++)
//     {
//         queue<pair<int, int>> q;
//         q.push(position[i]);
//         vector<vector<int>> dist(h + 1, vector<int>(w + 1, -1));
//         dist[position[i].first][position[i].second] = 0;

//         while (!q.empty())
//         {
//             int x = q.front().first;
//             int y = q.front().second;
//             q.pop();

//             if (x == position[i + 1].first && y == position[i + 1].second)
//             {
//                 ans += dist[x][y];
//             }

//             for (int j = 0; j < 4; j++)
//             {
//                 int nx = x + dx[j];
//                 int ny = y + dy[j];

//                 if (nx >= 0 && nx < h && ny >= 0 && ny < w && dist[nx][ny] == -1 && graph[nx][ny] != 'X')
//                 {
//                     dist[nx][ny] = dist[x][y] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

/*
4/27解き直し分
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int h, w, n, ans = 0;
//     cin >> h >> w >> n;

//     char kukakuMap[h + 1][w + 1];
//     vector<pair<int, int>> position(n + 1);

//     for (int i = 1; i <= h; i++)
//     {

//         for (int j = 1; j <= w; j++)
//         {
//             cin >> kukakuMap[i][j];
//             if (kukakuMap[i][j] == 'S')
//             {
//                 position[0] = {i, j};
//             }
//             else if ('0' <= kukakuMap[i][j] && kukakuMap[i][j] <= '9')
//             {
//                 position[kukakuMap[i][j] - '0'] = {i, j};
//             }
//         }
//     }
//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};

//     for (int num = 0; num < n; num++)
//     {

//         queue<pair<int, int>> q;

//         vector<vector<int>> dist(h + 1, vector<int>(w + 1, -1));

//         dist[position[num].first][position[num].second] = 0;

//         q.push({position[num].first, position[num].second});

//         while (!q.empty())
//         {
//             int x, y;
//             x = q.front().first;
//             y = q.front().second;
//             q.pop();

//             if (kukakuMap[x][y] == num + 1 + '0')
//             {
//                 ans += dist[x][y];
//                 break;
//             }

//             for (int i = 0; i < 4; i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i];
//                 if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && dist[nx][ny] == -1 && kukakuMap[nx][ny] != 'X')
//                 {
//                     dist[nx][ny] = dist[x][y] + 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

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