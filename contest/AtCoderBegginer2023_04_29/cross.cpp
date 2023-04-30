#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    char c[101][101];
    cin >> h >> w;

    int s[min(h, w) + 1] = {};

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
        }
    }

    int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
    int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

    vector<vector<bool>> visited(h + 1, vector<bool>(w + 1, false));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            queue<pair<int, int>> q;

            if (c[i][j] == '#' && !visited[i][j])
            {
                q.push({i, j});
                visited[i][j] = true;
            }

            int cnt = 0;
            while (!q.empty())
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                visited[x][y] = true;

                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx <= h && ny >= 0 && ny <= w && !visited[nx][ny] && c[nx][ny] == '#')
                    {
                        cnt++;
                        q.push({nx, ny});
                    }
                }
            }
            cout << "子ウントです" << cnt << endl;
            s[cnt / 4]++;
        }
    }

    for (int i = 1; i <= min(h, w); i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    return 0;
}
