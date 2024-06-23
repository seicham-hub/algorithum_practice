// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

#include <bits/stdc++.h>
using namespace std;

int main()
{

    while (true)
    {

        int w, h, ans = 0;
        cin >> w >> h;

        if (h == 0 && w == 0)
            break;

        vector<vector<int>> grid(h, vector<int>(w));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
                cin >> grid[i][j];
        }

        int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

        vector<vector<bool>> visited(h, vector<bool>(w, false));

        function<void(int, int)> dfs = [&](int x, int y)
        {
            visited[x][y] = true;

            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < h && 0 <= ny && ny < w)
                {
                    if (!visited[nx][ny] && grid[nx][ny] == 1)
                        dfs(nx, ny);
                }
            }
        };

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {

                if (!visited[i][j] && grid[i][j] == 1)
                {
                    ans++;
                    dfs(i, j);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}