// https://atcoder.jp/contests/abc319/tasks/abc319_c

// 解けたが、時間かかった

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    vector<int> c(9);

    rep(i, 9) cin >> c[i];

    vector<int> p(9);
    rep(i, 9) p[i] = i;

    double total = 0;
    double cnt = 0;

    do
    {
        total++;

        bool isOk = true;

        auto f = [&](int i, int j, int k)
        {
            vector<P> th;
            th.emplace_back(p[i], c[i]);
            th.emplace_back(p[j], c[j]);
            th.emplace_back(p[k], c[k]);

            sort(th.begin(), th.end());

            if (th[0].second == th[1].second)
                isOk = false;
        };

        f(0, 1, 2);
        f(3, 4, 5);
        f(6, 7, 8);
        f(0, 3, 6);
        f(1, 4, 7);
        f(2, 5, 8);
        f(0, 4, 8);
        f(2, 4, 6);

        if (isOk)
            cnt++;

    } while (next_permutation(p.begin(), p.end()));

    printf("%.10f", cnt / total);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     vector<int> c(9);

//     rep(i, 9) cin >> c[i];

//     vector<int> p(9);
//     rep(i, 9) p[i] = i;

//     int cnt = 0;
//     int total = 0;

//     do
//     {
//         total++;
//         bool isOk = true;

//         auto f = [&](int i, int j, int k)
//         {
//             vector<P> th;
//             th.emplace_back(p[i], c[i]);
//             th.emplace_back(p[j], c[j]);
//             th.emplace_back(p[k], c[k]);

//             sort(th.begin(), th.end());

//             if (th[0].second == th[1].second)
//                 isOk = false;
//         };

//         f(0, 1, 2);
//         f(3, 4, 5);
//         f(6, 7, 8);
//         f(0, 3, 6);
//         f(1, 4, 7);
//         f(2, 5, 8);
//         f(0, 4, 8);
//         f(2, 4, 6);

//         if (isOk)
//             cnt++;

//     } while (next_permutation(p.begin(), p.end()));

//     double ans = (double)cnt / (double)total;

//     printf("%.10f\n", ans);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {

//     vector<vector<int>> c(3, vector<int>(3));

//     rep(i, 3) rep(j, 3) cin >> c[i][j];

//     vector<pair<int, int>> indices;
//     rep(i, 3) rep(j, 3) indices.emplace_back(i, j);

//     double bunbo = 0;
//     double bunshi = 0;
//     do
//     {
//         bunbo++;

//         vector<vector<int>> row(3);
//         vector<vector<int>> col(3);
//         vector<int> cross1;
//         vector<int> cross2;

//         bool isOk = true;
//         for (auto [x, y] : indices)
//         {

//             if (row[x].size() == 2 && row[x][0] == row[x][1])
//             {
//                 isOk = false;
//                 break;
//             }
//             if (col[y].size() == 2 && col[y][0] == col[y][1])
//             {
//                 isOk = false;
//                 break;
//             }

//             if (cross1.size() == 2 && cross1[0] == cross1[1])
//             {
//                 isOk = false;
//                 break;
//             }

//             if (cross2.size() == 2 && cross2[0] == cross2[1])
//             {
//                 isOk = false;
//                 break;
//             }

//             row[x].push_back(c[x][y]);
//             col[y].push_back(c[x][y]);

//             if (x == y)
//                 cross1.push_back(c[x][y]);
//             if (x + y == 2)
//                 cross2.push_back(c[x][y]);
//         }

//         if (isOk)
//             bunshi++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     printf("%.10f", bunshi / bunbo);

//     return 0;
// }