// https://atcoder.jp/contests/abc304/tasks/abc304_c

// 0606もう一度　BFSの実装を固める
// 配列よりvectorで宣言するのがおすすめ、初期値が０で初期化される為
// グローバル変数で定義したほうがメモリ領域多めにとれるっぽい
// REは配列外参照の可能性大

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);

    rep(i, n) cin >> x[i] >> y[i];

    auto near = [&](int a, int b)
    {
        int dx = x[a] - x[b];
        int dy = y[a] - y[b];

        return dx * dx + dy * dy <= d * d;
    };

    queue<int> q;
    vector<bool> ans(n);

    ans[0] = true;
    q.push(0);
    while (!q.empty())
    {

        int v = q.front();
        q.pop();
        rep(u, n)
        {
            if (near(v, u))
            {
                if (ans[u])
                    continue;
                ans[u] = true;
                q.push(u);
            }
        }
    }

    rep(i, n)
    {
        if (ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}

// 本番のコード
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, d;

//     cin >> n >> d;

//     int ux, uy;

//     vector<pair<int, int>> hu(n);

//     queue<pair<int, int>> q;
//     map<int, bool> m;

//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;

//         hu[i] = {x, y};
//         if (i == 0)
//         {
//             q.push({x, y});
//             m[i] = true;
//         }
//     }

//     while (!q.empty())
//     {

//         int ux = q.front().first;
//         int uy = q.front().second;
//         q.pop();

//         for (int i = 0; i < n; i++)
//         {
//             int nx = hu[i].first;
//             int ny = hu[i].second;
//             double dist = sqrt((nx - ux) * (nx - ux) + (ny - uy) * (ny - uy));
//             if (dist <= d && !m[i])
//             {
//                 q.push({nx, ny});
//                 m[i] = true;
//             }
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (m[i])
//             cout << "Yes" << endl;
//         else
//             cout << "No" << endl;
//     }

//     return 0;
// }