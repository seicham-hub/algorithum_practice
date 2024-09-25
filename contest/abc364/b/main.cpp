#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int h, w, sx, sy;
    cin >> h >> w;

    cin >> sx >> sy;

    sx--, sy--;

    vector<vector<char>> grid(h, vector<char>(w));

    rep(i, h) rep(j, w)
    {
        cin >> grid[i][j];
    }

    string x;
    cin >> x;

    auto move = [&](int nx, int ny)
    {
        if (0 <= nx && nx < h && 0 <= ny && ny < w && grid[nx][ny] == '.')
        {

            sx = nx;
            sy = ny;
        }
    };

    for (char c : x)
    {
        if (c == 'L')
        {
            int nx = sx;
            int ny = sy - 1;
            move(nx, ny);
        }
        if (c == 'R')
        {
            int nx = sx;
            int ny = sy + 1;
            move(nx, ny);
        }
        if (c == 'U')
        {
            int nx = sx - 1;
            int ny = sy;
            move(nx, ny);
        }
        if (c == 'D')
        {
            int nx = sx + 1;
            int ny = sy;
            move(nx, ny);
        }
    }

    cout << sx + 1 << " " << sy + 1;

    return 0;
}