// https://atcoder.jp/contests/abc088/tasks/abc088_d

#include <bits/stdc++.h>
using namespace std;

int bfs(int h, int w, vector<vector<char>> &grid)
{

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 1;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty())
    {

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < h && 0 <= ny && ny < w)
            {
                if (grid[nx][ny] == '.' && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return dist[h - 1][w - 1];
}

int count_white(int &h, int &w, vector<vector<char>> &grid)
{
    int result = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
                result++;
        }
    }

    return result;
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<char>> grid(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            cin >> grid[i][j];
    }

    int min_dist = bfs(h, w, grid);

    int white_count = count_white(h, w, grid);

    if (min_dist == -1)
        cout << -1 << endl;
    else
        cout << white_count - min_dist << endl;

    return 0;
}