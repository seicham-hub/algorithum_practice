// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d

// 2024_06_24もう一度
// visitedを参照にするとまずいよね

#include <bits/stdc++.h>
using namespace std;

int m, n, ans = 0;
vector<vector<int>> grid;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, vector<vector<bool>> &visited, int tmp_ans)
{

    visited[x][y] = true;
    tmp_ans++;
    ans = max(ans, tmp_ans);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (!visited[nx][ny] && grid[nx][ny] == 1)
                dfs(nx, ny, visited, tmp_ans);
        }
    }
    visited[x][y] = false;
}

int main()
{

    cin >> m >> n;

    grid = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp_ans = 0;
            if (grid[i][j] == 1)
            {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(i, j, visited, tmp_ans);
            }
        }
    }

    cout << ans << endl;

    return 0;
}