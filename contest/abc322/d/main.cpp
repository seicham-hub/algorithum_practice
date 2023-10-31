// https://atcoder.jp/contests/abc322/tasks/abc322_d

// 方針は思いついたが、保存するデータ構造が分からなかった
// 1006もう一度
// 1027もう一度 ありえん時間かかりすぎ ok

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

void Rotate(vector<string> &p)
{
    vector<string> w(4, "....");

    rep(i, 4) rep(j, 4)
    {
        w[j][3 - i] = p[i][j];
    }

    p = w;
    return;
}

bool can_put(int di, int dj, vector<vector<int>> &exist, vector<string> p)
{
    rep(i, 4) rep(j, 4)
    {
        if (p[i][j] == '#')
        {
            int ni = i + di;
            int nj = j + dj;

            if (!(ni >= 0 && ni < 4 && nj >= 0 && nj < 4))
                return false;
            if (exist[ni][nj])
                return false;
            exist[ni][nj] = 1;
        }
    }
    return true;
}

void dfs(int cnt, vector<vector<int>> exist, const vector<vector<string>> &ps)
{
    if (cnt == 3)
    {
        rep(i, 4) rep(j, 4)
        {
            if (!exist[i][j])
                return;
        }
        cout << "Yes" << endl;
        exit(0);
    }

    for (int di = -3; di <= 3; di++)
    {
        for (int dj = -3; dj <= 3; dj++)
        {
            auto ex2 = exist;
            if (can_put(di, dj, ex2, ps[cnt]))
            {
                dfs(cnt + 1, ex2, ps);
            }
        }
    }
}

int main()
{

    vector<vector<string>> ps(3);

    rep(i, 3)
    {
        ps[i].resize(4);
        rep(j, 4)
        {
            cin >> ps[i][j];
        }
    }

    rep(i, 4)
    {
        rep(j, 4)
        {
            vector<vector<int>> exist(4, vector<int>(4, 0));
            dfs(0, exist, ps);
            Rotate(ps[1]);
        }
        Rotate(ps[2]);
    }
    cout << "No" << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// void Rotate(vector<string> &v)
// {
//     vector<string> w = v;
//     // 左に90土回転
//     rep(i, 4) rep(j, 4)
//     {
//         w[3 - j][i] = v[i][j];
//     }
// }

// bool can_put(vector<vector<int>> &exist, const vector<string> &p, int di, int dj)
// {
//     rep(i, 4) rep(j, 4)
//     {
//         if (p[i][j] == '#')
//         {
//             int ni = i + di;
//             int nj = j + dj;
//             if (!(0 <= ni && ni < 4 && 0 <= nj && nj < 4))
//                 return false;
//             if (exist[ni][nj] = '#')
//                 return false;
//             exist[ni][nj] = 1;
//         }
//     }
//     return true;
// }

// void dfs(int i, const vector<vector<int>> &exist, const vector<vector<string>> &ps)
// {
//     if (i == 3)
//     {
//         int ok = 1;
//         rep(i, 4) rep(j, 4) ok &= exist[i][j];
//         if (ok)
//         {
//             cout << "Yes" << endl;
//             exit(0);
//         }
//     }

//     for (int di = -3; di <= 3; di++)
//     {
//         for (int dj = -3; dj <= 3; dj++)
//         {
//             auto ex2 = exist;
//             bool flag = can_put(ex2, ps[i], di, dj);
//             if (flag)
//                 dfs(i + 1, ex2, ps);
//         }
//     }
// }

// int main()
// {
//     vector<vector<string>> ps(3);
//     rep(i, 3)
//     {
//         ps[i].resize(4);
//         for (auto &s : ps[i])
//             cin >> s;
//     }

//     rep(i, 4)
//     {
//         rep(j, 4)
//         {
//             vector<vector<int>> exist(4, vector<int>(4, 0));
//             dfs(0, exist, ps);
//             Rotate(ps[2]);
//         }
//         Rotate(ps[3]);
//     }

//     cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// bool isIn(int di, int dj, vector<string> const &p, vector<string> &g)
// {

//     vector<string> gv = g;
//     rep(i, 4) rep(j, 4)
//     {
//         if (p[i][j] == '#')
//         {
//             if (i + di >= 0 && i + di < 4 && j + dj >= 0 && j + dj < 4 && gv[i + di][j + dj] != '#')
//                 gv[i + di][j + dj] = '#';
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     g = gv;
//     return true;
// }

// void Rotate(vector<string> &p)
// {
//     vector<string> pl(4, "....");

//     rep(i, 4) rep(j, 4)
//     {
//         pl[j][3 - i] = p[i][j];
//     }

//     p = pl;
// }

// bool checkFull(const vector<string> &grid)
// {

//     rep(i, 4) rep(j, 4)
//     {
//         if (grid[i][j] != '#')
//             return false;
//     }
//     return true;
// }

// bool dfs(int cnt, vector<string> p1, vector<string> p2, vector<string> p3, vector<string> &grid)
// {
//     vector<string> p;
//     if (cnt == 0)
//         p = p1;
//     else if (cnt == 1)
//         p = p2;
//     else if (cnt == 2)
//         p = p3;
//     else if (cnt == 3)
//     {
//         return checkFull(grid);
//     }

//     for (int i = -3; i < 7; i++)
//     {
//         for (int j = -3; j < 7; j++)
//         {
//             vector<string> grid2 = grid;
//             if (isIn(i, j, p, grid2))
//             {

//                 int ncnt = cnt + 1;
//                 if (dfs(ncnt, p1, p2, p3, grid2))
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// int main()
// {

//     vector<string> p1(4), p2(4), p3(4);

//     rep(i, 4) cin >> p1[i];
//     rep(i, 4) cin >> p2[i];
//     rep(i, 4) cin >> p3[i];

//     for (int k = 0; k < 4; k++)
//     {
//         for (int l = 0; l < 4; l++)
//         {
//             vector<string> grid(4, "....");

//             if (dfs(0, p1, p2, p3, grid))
//             {
//                 cout << "Yes" << endl;
//                 exit(0);
//             }

//             Rotate(p2);
//         }
//         Rotate(p3);
//     }

//     cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// // sを出力してプログラムを終了
// void Print(const string &s)
// {
//     cout << s << endl;
//     exit(0);
// }

// // 右に90度回転
// void Rotate(vector<string> &v)
// {
//     vector<string> w = v;
//     rep(i, 4) rep(j, 4) w[3 - j][i] = v[i][j];
//     v = w;
// }

// // (i,j)がグリッド内部かを判定する
// bool in(int i, int j)
// {
//     return 0 <= i and i < 4 and 0 <= j and j < 4;
// }

// // p を (di, dj) を左上の位置として配置できるか？

// bool can_put(vector<vector<int>> &exist, const vector<string> &p, int di, int dj)
// {
//     rep(i, 4) rep(j, 4)
//     {
//         if (p[i][j] == '#')
//         {
//             int ni = i + di;
//             int nj = j + dj;
//             if (!in(ni, nj))
//                 return false;
//             if (exist[ni][nj] == 1)
//                 return false;
//             exist[ni][nj] = 1;
//         }
//     }
//     return true;
// }

// // ポリオミノを再起で置いていく関数

// void dfs(int i, const vector<vector<int>> &exist, const vector<vector<string>> &ps)
// {
//     if (i == 3)
//     {
//         int ok = 1;
//         rep(u, 4) rep(v, 4) ok &= exist[u][v];
//         if (ok)
//             Print("Yes");
//         return;
//     }

//     for (int di = -3; di <= 3; di++)
//     {
//         for (int dj = -3; dj <= 3; dj++)
//         {
//             auto ex2 = exist;
//             bool flag = can_put(ex2, ps[i], di, dj);
//             if (flag)
//                 dfs(i + 1, ex2, ps);
//         }
//     }
// }

// int main()
// {

//     vector<vector<string>> ps(3);
//     rep(i, 3)
//     {
//         ps[i].resize(4);
//         for (auto &s : ps[i])
//             cin >> s;
//     }

//     rep(t, 4)
//     {
//         rep(u, 4)
//         {
//             vector<vector<int>> vec(4, vector<int>(4, 0));
//             dfs(0, vec, ps);
//             Rotate(ps[2]);
//         }

//         Rotate(ps[1]);
//     }
//     Print("No");
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     rep(i, 4)
//     {
//         int is_left_top = true;
//         rep(i, 4)
//         {
//             char c;
//             cin >> c;
//             if (c == '#')
//             {
//                 if (is_left_top)
//             }
//         }
//     }

//     return 0;
// }