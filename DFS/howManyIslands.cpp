// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp

#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int w, h;
bool seen[60][60];

void dfs(int x, int y)
{

    seen[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!seen[nx][ny] && nx >= 0 && nx <= h && ny >= 0 && ny <= h)
            dfs(nx, ny);
    }
}

int main()
{

    cin >> w >> h;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> c[i][j]
        }
    }

    return 0;
}
