// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja

// 2024_08_28もう一度
// 2024_08_29もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    map<pair<int, int>, int> graph;

    for (int i = 0; i < e; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;

        graph[{s, t}] = d;
    }

    vector<vector<int>> dp((1 << v), vector<int>(v, INT_MAX));
    dp[1][0] = 0;

    for (int msk = 1; msk < (1 << v); msk++)
    {
        for (int i = 0; i < v; i++)
        {
            int before = msk & ~(1 << i);
            for (int k = 0; k < v; k++)
                if (before & (1 << k) && graph.count({k, i}) && dp[before][k] != INT_MAX)
                    dp[msk][i] = min(dp[msk][i], dp[before][k] + graph[{k, i}]);
        }
    }

    int ans = INT_MAX;
    int full_msk = (1 << v) - 1;

    for (int i = 1; i < v; i++)
    {
        if (graph.count({i, 0}) && dp[full_msk][i] != INT_MAX)
            ans = min(ans, dp[full_msk][i] + graph[{i, 0}]);
    }

    if (ans != INT_MAX)
        cout << ans << endl;
    else
        cout << -1 << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int v, e;
//     cin >> v >> e;

//     map<pair<int, int>, int> graph;

//     for (int i = 0; i < e; i++)
//     {
//         int s, t, d;
//         cin >> s >> t >> d;
//         graph[{s, t}] = d;
//     }

//     vector<vector<int>> dp(1 << v, vector<int>(v, INT_MAX));
//     dp[1][0] = 0;

//     for (int msk = 1; msk < (1 << v); msk++)
//     {
//         for (int i = 0; i < v; i++)
//         {
//             int before = msk & ~(1 << i);
//             for (int k = 0; k < v; k++)
//                 if (before & (1 << k) && dp[before][k] != INT_MAX && graph.count({k, i}))
//                     dp[msk][i] = min(dp[msk][i], dp[before][k] + graph[{k, i}]);
//         }
//     }

//     int ans = INT_MAX;

//     for (int i = 1; i < v; i++)
//         if (dp[(1 << v) - 1][i] != INT_MAX && graph.count({i, 0}))
//             ans = min(ans, dp[(1 << v) - 1][i] + graph[{i, 0}]);

//     if (ans != INT_MAX)
//         cout << ans << endl;
//     else
//         cout << -1 << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int calc_min_diff(int &start, int v, map<pair<int, int>, int> &graph)
// {
//     vector<vector<int>> dp(1 << v, vector<int>(v, INT_MAX));
//     dp[0][0] = 0;
//     dp[1 << start][start] = 0;
//     for (int msk = (1 << start); msk < (1 << v); msk++)
//     {
//         for (int i = 0; i < v; i++)
//         {
//             // int before = msk - pow(2, i);
//             // if (before < 0)
//             //     continue;

//             int before = msk & ~(1 << i);

//             for (int k = 0; k < v; k++)
//             {
//                 if ((before & (1 << k)) && graph.count({k, i}) && dp[before][k] != INT_MAX)
//                     dp[msk][i] = min(dp[msk][i], dp[before][k] + graph[{k, i}]);
//             }
//         }
//     }

//     int ans = INT_MAX;

//     for (int i = 0; i < v; i++)
//         if (graph.count({i, start}) && dp[(1 << v) - 1][i] != INT_MAX)
//             ans = min(ans, dp[(1 << v) - 1][i] + graph[{i, start}]);

//     return ans;
// }

// int main()
// {
//     int v, e;
//     cin >> v >> e;

//     map<pair<int, int>, int> graph;

//     for (int i = 0; i < e; i++)
//     {
//         int s, t, d;
//         cin >> s >> t >> d;
//         graph[{s, t}] = d;
//     }

//     int ans = INT_MAX;

//     for (int start = 0; start < 1; start++)
//         ans = min(ans, calc_min_diff(start, v, graph));

//     if (ans != INT_MAX)
//         cout << ans << endl;
//     else
//         cout << -1 << endl;

//     return 0;
// }