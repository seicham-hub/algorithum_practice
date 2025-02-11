// https://atcoder.jp/contests/abc341/tasks/abc341_c

// TLEとなった...
// 配列を作り直したりする操作は気を付けろ
// 2025_02_10もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int h, w, n;
    string t;
    cin >> h >> w >> n >> t;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    unordered_map<char, P> mp;

    mp['L'] = {0, -1};
    mp['R'] = {0, 1};
    mp['U'] = {-1, 0};
    mp['D'] = {1, 0};

    auto dfs = [&](auto dfs, int x, int y, int tInd) -> bool
    {
        if (tInd == t.size())
            return true;

        auto [dx, dy] = mp[t[tInd]];

        int nx = x + dx, ny = y + dy;
        if (s[nx][ny] == '.')
            return dfs(dfs, nx, ny, tInd + 1);

        return false;
    };

    int ans = 0;

    rep(i, h) rep(j, w)
    {

        if (s[i][j] == '#')
            continue;

        if (dfs(dfs, i, j, 0))
            ans++;
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int h, w, n;
//     cin >> h >> w >> n;
//     string t;
//     cin >> t;

//     vector<string> grid(h);

//     rep(i, h)
//             cin >>
//         grid[i];

//     unordered_map<char, P> mp;
//     mp['L'] = {0, -1};
//     mp['R'] = {0, 1};
//     mp['U'] = {-1, 0};
//     mp['D'] = {1, 0};

//     auto dfs = [&](auto dfs, int x, int y, int cnt) -> bool
//     {
//         if (grid[x][y] == '#')
//             return false;

//         if (cnt == t.size())
//             return true;

//         auto [dx, dy] = mp[t[cnt]];

//         int nx = x + dx, ny = y + dy;
//         if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '.')
//             return dfs(dfs, nx, ny, cnt + 1);

//         return false;
//     };

//     int ans = 0;
//     rep(i, h) rep(j, w)
//     {

//         if (dfs(dfs, i, j, 0))
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }