// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d

// 2024_06_24もう一度
// 2024_06_25もう一度
// visitedを参照にするとまずいよね

#include <bits/stdc++.h>
using namespace std;

int m, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;

void dfs(int count, pair<int, int> xy, vector<vector<bool>> visited, vector<vector<int>> &grid)
{

    int x = xy.first;
    int y = xy.second;
    ++count;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (grid[nx][ny] && !visited[nx][ny])
                dfs(count, {nx, ny}, visited, grid);
        }
    }

    ans = max(ans, count);
}

int main()
{

    cin >> m >> n;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (grid[i][j])
            {
                vector<vector<bool>> visited(n, vector<bool>(m, false));
                dfs(0, {i, j}, visited, grid);
            }
    }

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int m, n;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// vector<vector<int>> grid;

// int tmp_ans = 0;

// int dfs(int x, int y, int point, vector<vector<bool>> visited)
// {
//     point = 1;
//     visited[x][y] = true;

//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if (0 <= nx && nx < n && 0 <= ny && ny < m)
//         {
//             if (!visited[nx][ny] && grid[nx][ny] == 1)
//                 point += dfs(nx, ny, point, visited);
//         }
//     }

//     return point;
// }

// int main()
// {

//     cin >> m >> n;
//     int ans = 0;

//     grid = vector<vector<int>>(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//             if (grid[i][j] == 1)
//             {
//                 vector<vector<bool>> visited(n, vector<bool>(m, false));
//                 tmp_ans = 0;
//                 dfs(i, j, 0, visited);
//                 ans = max(ans, tmp_ans);
//             }
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int m, n, ans = 0;
// vector<vector<int>> grid;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};

// void dfs(int x, int y, vector<vector<bool>> &visited, int tmp_ans)
// {

//     visited[x][y] = true;
//     tmp_ans++;
//     ans = max(ans, tmp_ans);

//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];

//         if (0 <= nx && nx < n && 0 <= ny && ny < m)
//         {
//             if (!visited[nx][ny] && grid[nx][ny] == 1)
//                 dfs(nx, ny, visited, tmp_ans);
//         }
//     }
//     visited[x][y] = false;
// }

// int main()
// {

//     cin >> m >> n;

//     grid = vector<vector<int>>(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> grid[i][j];
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int tmp_ans = 0;
//             if (grid[i][j] == 1)
//             {
//                 vector<vector<bool>> visited(n, vector<bool>(m, false));
//                 dfs(i, j, visited, tmp_ans);
//             }
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }