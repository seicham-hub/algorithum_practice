// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

// seen配列なくてもcの値を0に変換すれば良い

#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int w, h, ans = 0;
bool seen[60][60];
Graph c(60, (vector<int>(60, 0)));

void dfs(int x, int y)
{

    seen[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!seen[nx][ny] && nx >= 0 && nx <= h && ny >= 0 && ny <= h && c[nx][ny] == 1)
            dfs(nx, ny);
    }
}

int main()
{

    cin >> w >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (c[i][j] == 1 && !seen[i][j])
            {
                dfs(i, j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
