// https://atcoder.jp/contests/atc001/tasks/dfs_a

#include <bits/stdc++.h>
using namespace std;

bool seen[510][510];
char c[510][510];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int h, w;

void dfs(vector<int> v)
{

    seen[v[0]][v[1]] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = v[0] + dx[i];
        int ny = v[1] + dy[i];
        if (seen[nx][ny] || nx < 0 || nx >= h || ny < 0 || ny >= w || c[nx][ny] == '#')
            continue;
        dfs({nx, ny});
    }
}

int main()
{

    cin >> h >> w;
    vector<int> start(2), goal(2);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == 's')
                start = {i, j};
            if (c[i][j] == 'g')
                goal = {i, j};
        }
    }

    dfs(start);

    if (seen[goal[0]][goal[1]])
    {

        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
