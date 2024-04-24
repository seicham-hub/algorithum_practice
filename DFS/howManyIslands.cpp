// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

// seen配列なくてもcの値を0に変換すれば良い

#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int w, h;

void dfs(pair<int, int> start, vector<vector<int>> &island_map, vector<vector<bool>> &visited)
{
    int x = start.first;
    int y = start.second;
    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < h && 0 <= ny && ny < w)
        {
            if (!visited[nx][ny] && island_map[nx][ny] == 1)
            {
                dfs({nx, ny}, island_map, visited);
            }
        }
    }
}

int main()
{

    cin >> w >> h;

    vector<vector<int>> island_map(h, vector<int>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> island_map[i][j];
        }
    }

    vector<vector<bool>> visited(h, vector<bool>(w, false));
    int ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (island_map[i][j] == 1 && !visited[i][j])
            {
                ans++;
                pair<int, int> start = {i, j};
                dfs(start, island_map, visited);
            }
        }
    }
    cout << ans << endl;

    return 0;
}

// queueで実装してみました
// #include <bits/stdc++.h>
// using namespace std;

// int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
// int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

// int main()
// {
//     int w, h, ans = 0;
//     cin >> w >> h;

//     vector<vector<int>> island_map(h, vector<int>(w));

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cin >> island_map[i][j];
//         }
//     }

//     queue<pair<int, int>> q;
//     vector<vector<int>> dist(h, vector<int>(w, -1));

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {

//             if (island_map[i][j] == 1 && dist[i][j] == -1)
//             {
//                 ans++;

//                 pair<int, int> start = {i, j};
//                 dist[i][j] = 0;
//                 q.push(start);

//                 while (!q.empty())
//                 {
//                     auto now_position = q.front();
//                     q.pop();

//                     int x = now_position.first;
//                     int y = now_position.second;

//                     int now_dist = dist[x][y];

//                     for (int i = 0; i < 8; i++)
//                     {
//                         int nx = x + dx[i];
//                         int ny = y + dy[i];

//                         if (0 <= nx && nx < h && 0 <= ny && ny < w)
//                         {
//                             if (island_map[nx][ny] == 1 && dist[nx][ny] == -1)
//                             {
//                                 q.push({nx, ny});
//                                 dist[nx][ny] = now_dist + 1;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int w, h, ans = 0;
// int dx[8] = {0, 1, 0, -1, -1, -1, 1, 1};
// int dy[8] = {1, 0, -1, 0, -1, 1, 1, -1};

// void dfs(pair<int, int> &start, vector<vector<bool>> &visited, vector<vector<int>> &island_map)
// {

//     int x = start.first;
//     int y = start.second;

//     visited[x][y] = true;

//     for (int i = 0; i < 8; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if (0 <= nx && nx < h && 0 <= ny && ny < w)
//         {
//             if (!visited[nx][ny] && island_map[nx][ny] == 1)
//             {
//                 pair<int, int> next = {nx, ny};

//                 dfs(next, visited, island_map);
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> w >> h;

//     vector<vector<int>> island_map(h, vector<int>(w));

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cin >> island_map[i][j];
//         }
//     }

//     vector<vector<bool>> visited(h, vector<bool>(w, false));

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             if (island_map[i][j] == 1 && !visited[i][j])
//             {
//                 ans++;
//                 pair<int, int> start = {i, j};
//                 dfs(start, visited, island_map);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// using Graph = vector<vector<int>>;
// int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
// int w, h, ans = 0;
// bool seen[60][60];
// Graph c(60, (vector<int>(60, 0)));

// void dfs(int x, int y)
// {

//     seen[x][y] = true;
//     for (int i = 0; i < 8; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (!seen[nx][ny] && nx >= 0 && nx <= h && ny >= 0 && ny <= h && c[nx][ny] == 1)
//             dfs(nx, ny);
//     }
// }

// int main()
// {

//     cin >> w >> h;

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cin >> c[i][j];
//         }
//     }

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             if (c[i][j] == 1 && !seen[i][j])
//             {
//                 dfs(i, j);
//                 ans++;
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }
