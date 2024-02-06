#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int ans = 0;
vector<int> dx = {0, 1, 0, -1, -1, -1, 1, 1};
vector<int> dy = {1, 0, -1, 0, -1, 1, 1, -1};
int h, w;
vector<string> s(10000);

vector<vector<bool>> ma(10000, vector<bool>(10000, false));

void dfs(int x, int y)
{
    ma[x][y] = true;
    rep(i, 8)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < h && 0 <= ny && ny < w && ma[nx][ny] == false)
        {
            ma[nx][ny] = true;
            if (0 <= nx && nx < h && 0 <= ny && ny < w && s[nx][ny] == '#')
                dfs(nx, ny);
        }
    }
}

int main()
{

    cin >> h >> w;

    rep(i, h) cin >> s[i];

    rep(i, h)
    {
        rep(j, w)
        {
            if (ma[i][j] == false && s[i][j] == '#')
            {
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << endl;

    return 0;
}