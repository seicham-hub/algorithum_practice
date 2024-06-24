// https://atcoder.jp/contests/abc007/tasks/abc007_3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;

    pair<int, int> start, end;
    cin >> start.first >> start.second;
    start.first--;
    start.second--;
    cin >> end.first >> end.second;

    vector<vector<char>> grid(r, vector<char>(c));
    end.first--;
    end.second--;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> grid[i][j];
    }

    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> dist(r, vector<int>(c, -1));
    dist[start.first][start.second] = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    while (!q.empty())
    {

        auto xy = q.front();
        int x = xy.first;
        int y = xy.second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < r && 0 <= ny && ny < c)
            {
                if (grid[nx][ny] == '.' && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << dist[end.first][end.second] << endl;
    return 0;
}