// https://atcoder.jp/contests/abc305/tasks/abc305_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int h, w;

    int u = -1e9, d = 1e9, l = 1e9, r = -1e9;

    cin >> h >> w;

    vector<vector<char>> s(h, vector<char>(w));

    rep(i, h)
    {
        rep(j, w)
        {
            cin >> s[i][j];
            if (s[i][j] == '#')
            {
                u = max(i, u);
                d = min(i, d);
                l = min(j, l);
                r = min(j, r);
            }
        }
    }

    for (int i = d; i <= u; i++)
    {
        for (int j = l; j <= r; j++)
        {
            if (s[i][j] == '.')
            {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}

// 本番のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int h, w;
// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
// int ansx, ansy;
// vector<pair<int, int>> v;

// vector<vector<bool>> seen(510, vector<bool>(510));
// vector<vector<char>> s(510, vector<char>(510));

// void dfs(int now)
// {
//     if (now >= v.size())
//     {
//         return;
//     }

//     int x = v[now].first;
//     int y = v[now].second;

//     int cnt = 0;
//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//         if (nx < 0 || nx >= h || ny < 0 || ny >= w)
//             continue;
//         if (s[nx][ny] == '#')
//             cnt++;
//         // if (!seen[nx][ny] && s[nx][ny] == '.')
//         // {
//         //     dfs(nx, ny);
//         // }
//     }

//     if (cnt >= 2)
//     {
//         ansx = x + 1;
//         ansy = y + 1;
//         return;
//     }
//     dfs(now + 1);
// }

// int main()
// {

//     cin >> h >> w;

//     rep(i, h)
//     {
//         rep(j, w)
//         {
//             cin >> s[i][j];
//             if (s[i][j] == '.')
//             {
//                 v.push_back({i, j});
//             }
//         }
//     }

//     dfs(0);

//     cout << ansx << " " << ansy << endl;

//     return 0;
// }