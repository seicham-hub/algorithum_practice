// https://atcoder.jp/contests/abc355/tasks/abc355_c

// 11_15もう一度
// 10^8を少しでも超えたら間に合わないと考えろ

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using P = pair<int, int>;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<int> row(n), col(n);

    int dia1 = 0, dia2 = 0;

    rep(ti, t)
    {
        int a;
        cin >> a;
        a--;

        int i = a / n, j = a % n;

        auto add = [&](int &x)
        {
            x++;
            if (x == n)
            {
                cout << ti + 1 << endl;
                exit(0);
            }
        };

        add(row[i]);
        add(col[j]);
        if (i == j)
            add(dia1);
        if (i + j == n)
            add(dia2);
    }

    cout << -1 << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using P = pair<int, int>;

// int main()
// {
//     int n, t;
//     cin >> n >> t;

//     vector<int> a(t);

//     rep(i, t) cin >> a[i];

//     vector<vector<int>> card(n, vector<int>(n)), bingo(n, vector<int>(n, 1e9));
//     map<int, P> place;

//     rep(i, n)
//     {
//         rep(j, n)
//         {
//             int val = n * i + j + 1;
//             place[val] = {i, j};
//         }
//     }

//     rep(cnt, t)
//     {
//         int val = a[cnt];
//         int i = place[val].first;
//         int j = place[val].second;
//         bingo[i][j] = cnt + 1;
//     }

//     int ans = 1e9;

//     rep(i, n)
//     {
//         int rowMax = -1;
//         int colMax = -1;
//         rep(j, n)
//         {
//             rowMax = max(rowMax, bingo[i][j]);
//             colMax = max(colMax, bingo[j][i]);
//         }
//         ans = min(ans, rowMax);
//         ans = min(ans, colMax);
//     }

//     int crossMax1 = -1;
//     rep(i, n)
//     {
//         crossMax1 = max(crossMax1, bingo[i][i]);
//     }
//     ans = min(ans, crossMax1);

//     int crossMax2 = -1;
//     rep(i, n)
//     {
//         crossMax2 = max(crossMax2, bingo[n - 1 - i][i]);
//     }
//     ans = min(ans, crossMax2);

//     if (ans == 1e9)
//         cout << -1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }