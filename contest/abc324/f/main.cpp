// https://atcoder.jp/contests/abc324/tasks/abc324_f
// 0205もう一度
// 割り算の計算で誤差がでそうだとは思ったが...

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

struct Edge
{
    int to;
    int b;
    int c;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);

    rep(i, m)
    {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        --u;
        --v;
        g[u].push_back((Edge){v, b, c});
    }

    auto f = [&](double x)
    {
        const double INF = 1e18;
        vector<double> dp(n, -INF);
        dp[0] = 0;
        rep(i, n)
        {
            for (auto e : g[i])
            {
                dp[e.to] = max(dp[e.to], dp[i] + e.b - e.c * x);
            }
        }

        return dp[n - 1] >= 0;
    };

    double ac = 0;
    double wa = 1e4;

    rep(i, 52)
    {
        double wj = (ac + wa) / 2;
        if (f(wj))
            ac = wj;
        else
            wa = wj;
    }

    printf("%.10f", ac);

    return 0;
}

// 解答のコード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// using ll = long long;

// void chmax(double &x, double y)
// {
//     x = max(x, y);
// }

// struct Edge
// {
//     int to, b, c;
// };

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<Edge>> g(n);
//     rep(i, m)
//     {
//         int u, v, b, c;
//         cin >> u >> v >> b >> c;
//         --u;
//         --v;
//         g[u].push_back((Edge){v, b, c});
//     }

//     auto f = [&](double x)
//     {
//         const double INF = 1e18;
//         vector<double> dp(n, -INF);
//         dp[0] = 0;
//         rep(i, n)
//         {
//             for (auto e : g[i])
//             {
//                 chmax(dp[e.to], dp[i] + e.b - e.c * x);
//             }
//         }
//         return dp[n - 1] >= 0;
//     };

//     // 二分探索の上限下限
//     double ac = 0,
//            wa = 1e4;
//     // 実数で二分探索するときは回数でやるのがおすすめ
//     // 誤差10^-9なので全体の長さを考えると、10^-13以下にしないといけない
//     // (1/2)^k =< (1/10)^13
//     rep(ti, 50)
//     {
//         double wj = (ac + wa) / 2;

//         if (f(wj))
//             ac = wj;
//         else
//             wa = wj;
//     }

//     printf("%.10f\n", ac);

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// using ll = long long;

// int n, m;
// double ans = 0;
// map<int, vector<pair<int, int>>> uv;
// vector<int> b(250000), c(250000);

// void dfs(int now, ll b_sum, ll c_sum)
// {
//     if (now == n)
//     {
//         ans = max(ans, (double)b_sum / (double)c_sum);
//         // cout << ans << endl;
//         return;
//     }

//     for (auto p : uv[now])
//     {
//         ll b_now_sum = b_sum;
//         ll c_now_sum = c_sum;
//         int next = p.first;
//         int ind = p.second;

//         b_now_sum += b[ind];
//         c_now_sum += c[ind];
//         dfs(next, b_now_sum, c_now_sum);
//     }
// }

// int main()
// {

//     cin >> n >> m;

//     rep(i, m)
//     {
//         int u, v;
//         cin >> u >> v >> b[i] >> c[i];
//         uv[u].push_back({v, i});
//     }

//     dfs(1, 0, 0);

//     cout << ans << endl;

//     return 0;
// }