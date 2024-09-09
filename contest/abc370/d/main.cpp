// https://atcoder.jp/contests/abc370/tasks/abc370_d
// 2024_09_09もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    int h, w, q;
    cin >> h >> w >> q;

    vector<int> r(q), c(q);

    vector<vector<bool>> is_block(h, vector<bool>(w, true));

    for (int i = 0; i < q; i++)
    {
        cin >> r[i] >> c[i];

        r[i]--;
        c[i]--;
    }
    vector<set<int>> block_column(w), block_row(h);

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            block_column[j].insert(i);
            block_row[i].insert(j);
        }

    ll ans = h * w;

    for (int i = 0; i < q; i++)
    {
        int x = r[i];
        int y = c[i];
        if (is_block[x][y])
        {
            is_block[x][y] = false;
            block_column[y].erase(x);
            block_row[x].erase(y);
            ans--;
        }
        else
        {

            // left
            auto it_left = block_row[x].lower_bound(y);

            if (it_left != block_row[x].begin())
            {
                it_left--;

                is_block[x][*it_left] = false;
                block_column[*it_left].erase(x);
                block_row[x].erase(*it_left);
                ans--;
            }

            // right
            auto it_right = block_row[x].upper_bound(y);

            if (it_right != block_row[x].end())
            {
                is_block[x][*it_right] = false;
                block_column[*it_right].erase(x);
                block_row[x].erase(*it_right);
                ans--;
            }

            // up
            auto it_up = block_column[y].lower_bound(x);

            if (it_up != block_column[y].begin())
            {
                it_up--;

                is_block[*it_up][y] = false;
                block_column[y].erase(*it_up);
                block_row[*it_up].erase(y);
                ans--;
            }

            // down
            auto it_down = block_column[y].upper_bound(x);

            if (it_down != block_column[y].end())
            {
                is_block[*it_down][y] = false;
                block_column[y].erase(*it_down);
                block_row[*it_down].erase(y);
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int h, w, q;
//     cin >> h >> w >> q;

//     vector<int> r, c;

//     vector<vector<bool>> is_block(h, vector<bool>(w, true));

//     for (int i = 0; i < q; i++)
//     {
//         cin >> r[i] >> c[i];

//         r[i]--;
//         c[i]--;
//     }

//     map<pair<int, int>, map<char, int>> boom;

//     int dx[4] = {0, 1, 0, -1};
//     int dy[4] = {1, 0, -1, 0};

//     for (int i = 0; i < q; i++)
//     {
//         int x = r[i];
//         int y = c[i];
//         if (!is_block[x][y])
//         {
//             is_block[x][y] = false;
//         }
//         else
//         {
//             for (int j = 0; j < 4; j++)
//             {
//                 int nx = x + dx[j];
//                 int ny = y + dy[j];

//                 if (0 <= nx && nx < h && 0 <= ny && ny < w)
//                 {
//                     // right
//                     if (j == 0)
//                         boom[x][ny] = boom[x][y] + 1
//                 }
//             }
//         }
//     }

//     return 0;
// }