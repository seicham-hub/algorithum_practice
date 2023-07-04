#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    string snk = "snuke";

    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i, h)
    {
        string tmps;
        cin >> tmps;
        rep(j, w)
        {
            s[i][j] = tmps[j];
        }
    }

    if (s[0][0] != 's')
    {
        cout << "No" << endl;
        return 0;
    }

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    vector<vector<bool>> visit(h, vector<bool>(w, false));
    visit[0][0] = true;
    bool ans = false;

    while (!q.empty())
    {
        auto t = q.front();

        int x, y, sind;
        tie(x, y, sind) = t;

        q.pop();

        if (x == h - 1 && y == w - 1)
        {
            ans = true;
            break;
        }

        rep(i, 4)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // visitをtrueにするのはqueueに追加するとき

            if (nx >= 0 && nx < h && ny >= 0 && ny < w && s[nx][ny] == snk[(sind + 1) % 5] && !visit[nx][ny])
            {
                visit[nx][ny] = true;
                q.emplace(nx, ny, sind + 1);
            }
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}