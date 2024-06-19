// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja

// 2024_06_19もう一度

#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<int> &col, vector<pair<int, int>> &preplaced)
{
    for (auto p : preplaced)
    {
        int r = p.first;
        int c = p.second;

        if (col[r] != c)
            return false;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 8; j++)
        {
            int row_diff = j - i;
            if (col[i] == col[j] || col[i] + row_diff == col[j] || col[i] - row_diff == col[j])
                return false;
        }
    }

    return true;
}

int main()
{
    int k;
    int n = 8;
    cin >> k;

    vector<pair<int, int>> preplaced(k);

    for (int i = 0; i < k; i++)
        cin >> preplaced[i].first >> preplaced[i].second;

    vector<int> col;
    for (int i = 0; i < n; i++)
        col.push_back(i);

    do
    {
        if (is_valid(col, preplaced))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (j == col[i])
                        cout << 'Q';
                    else
                        cout << '.';
                }
                cout << endl;
            }
        }

    } while (next_permutation(col.begin(), col.end()));

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n = 8;
// vector<pair<int, int>> pre_placed;

// bool is_valid(vector<int> column)
// {
//     // すでに置いてあるqueenと比較
//     for (auto p : pre_placed)
//     {
//         int r = p.first;
//         int c = p.second;

//         if (column[r] != c)
//             return false;
//     }

//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int diff = abs(i - j);
//             if (column[i] == column[j] || column[i] + diff == column[j] || column[i] - diff == column[j])
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     int k;

//     cin >> k;

//     pre_placed.resize(k);

//     for (int i = 0; i < k; i++)
//     {
//         cin >> pre_placed[i].first >> pre_placed[i].second;
//     }

//     vector<int> column;
//     for (int i = 0; i < n; i++)
//         column.push_back(i);

//     do
//     {
//         if (is_valid(column))
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     if (j == column[i])
//                         cout << 'Q';
//                     else
//                         cout << '.';
//                 }
//                 cout << endl;
//             }
//         }

//     } while (next_permutation(column.begin(), column.end()));

//     return 0;
// }

// お手本コード
// 各行、各列に一つだけqueenが存在するのでこれを全探索
// 列を順列で探索し、それに対して行を全探索する
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// const int N = 8;
// vector<int> col(N);                // 列の順列
// vector<pair<int, int>> pre_placed; // 既に配置されたクイーンの位置

// bool is_valid()
// {
//     // 既に配置されたクイーンの位置を確認
//     for (auto p : pre_placed)
//     {
//         int r = p.first;
//         int c = p.second;
//         for (int i = 0; i < N; ++i)
//         {
//             if (i == r)
//                 continue;
//             int diff = abs(i - r);
//             if (col[i] == c || col[i] == c + diff || col[i] == c - diff)
//             {
//                 return false;
//             }
//         }
//     }
//     // 新たに配置するクイーンの位置を確認
//     for (int i = 0; i < N; ++i)
//     {
//         for (int j = i + 1; j < N; ++j)
//         {
//             int diff = abs(i - j);
//             if (col[i] == col[j] || col[i] == col[j] + diff || col[i] == col[j] - diff)
//             {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main()
// {
//     int k;
//     cin >> k;
//     pre_placed.resize(k);
//     for (int i = 0; i < k; ++i)
//     {
//         cin >> pre_placed[i].first >> pre_placed[i].second;
//     }

//     // 初期状態の列の順列を設定
//     for (int i = 0; i < N; ++i)
//     {
//         col[i] = i;
//     }

//     // 順列全探索
//     do
//     {
//         if (is_valid())
//         {
//             vector<string> board(N, string(N, '.'));
//             for (int i = 0; i < N; ++i)
//             {
//                 board[i][col[i]] = 'Q';
//             }
//             for (int i = 0; i < N; ++i)
//             {
//                 cout << board[i] << endl;
//             }
//             break;
//         }
//     } while (next_permutation(col.begin(), col.end()));

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> ans_queen;

// void disable_grid(int &x, int &y, vector<vector<bool>> &can_put_map)
// {
//     for (int i = 0; i < 8; i++)
//         can_put_map[x][i] = false;
//     for (int i = 0; i < 8; i++)
//         can_put_map[i][y] = false;

//     int dx[4] = {-1, -1, 1, 1};
//     int dy[4] = {1, -1, 1, -1};

//     for (int i = 0; i < 4; i++)
//     {
//         int tmp_x = x;

//         int tmp_y = y;

//         while (0 <= tmp_x && tmp_x < 8 && 0 <= tmp_y && tmp_y < 8)
//         {
//             can_put_map[tmp_x][tmp_y] = false;
//             tmp_x += dx[i];
//             tmp_y += dy[i];
//         }
//     }
// }

// void dfs(vector<vector<bool>> can_map, vector<pair<int, int>> queens)
// {
//     if (queens.size() == 8)
//     {
//         ans_queen = queens;
//         return;
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//         {

//             if (can_map[i][j])
//             {
//                 vector<vector<bool>> copy_map = can_map;
//                 vector<pair<int, int>> copy_queens = queens;
//                 copy_queens.push_back({i, j});
//                 disable_grid(i, j, copy_map);
//                 dfs(copy_map, copy_queens);
//             }
//         }
//     }
// }

// int main()
// {
//     int k;
//     cin >> k;

//     vector<pair<int, int>> queens;

//     for (int i = 0; i < k; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         queens.push_back({x, y});
//     }

//     vector<vector<bool>> can_put_map(8, vector<bool>(8, true));

//     for (pair<int, int> queen : queens)
//     {
//         int x = queen.first;
//         int y = queen.second;

//         disable_grid(x, y, can_put_map);
//     }

//     dfs(can_put_map, queens);

//     vector<vector<char>> ans(8, vector<char>(8, '.'));

//     for (auto q : ans_queen)
//     {
//         ans[q.first][q.second] = 'Q';
//     }

//     for (int i = 0; i < 8; i++)
//     {
//         for (int j = 0; j < 8; j++)
//             cout << ans[i][j];
//         cout << endl;
//     }
//     return 0;
// }