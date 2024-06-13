// https://atcoder.jp/contests/abc002/tasks/abc002_4

#include <bits/stdc++.h>
using namespace std;

int count_bit(int msk, int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (msk & (1 << i))
            result++;
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, unordered_map<int, bool>> known;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        known[x][y] = true;
        known[y][x] = true;
    }

    int ans = 0;

    for (int msk = 0; msk < (1 << n); msk++)
    {
        int count = count_bit(msk, n);
        if (count <= ans)
            continue;

        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (msk >> i & msk >> j & 1 && !known[i][j])
                    ok = false;
            }
        }
        if (ok)
            ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}

// 自分のコード
// 合格したが少し冗長
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m, ans = 0;
//     cin >> n >> m;

//     vector<vector<int>> candidate;
//     map<pair<int, int>, bool> known;

//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         x--;
//         y--;
//         known[{x, y}] = true;
//         known[{y, x}] = true;
//     }

//     for (int msk = 0; msk < (1 << n); msk++)
//     {
//         vector<int> tmp;
//         for (int ind = 0; ind < n; ind++)
//         {
//             if (msk & (1 << ind))
//                 tmp.push_back(ind);
//         }
//         candidate.push_back(tmp);
//     }

//     for (auto c : candidate)
//     {
//         bool ok = true;

//         for (int i = 0; i < c.size(); i++)
//         {
//             for (int j = i + 1; j < c.size(); j++)
//             {
//                 if (!known[{c[i], c[j]}])
//                     ok = false;
//             }
//         }

//         if (ok)
//             ans = max(ans, (int)c.size());
//     }

//     cout << ans << endl;

//     return 0;
// }