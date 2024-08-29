// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g

// めちゃちゃ時間かかったけど、通り数を計算する方法が分からなかった
// 2024_08_28もう一度
// 2024_08_29もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    map<pair<int, int>, pair<ll, ll>> graph;

    for (int i = 0; i < m; i++)
    {
        int s, t;
        ll d, time;
        cin >> s >> t >> d >> time;
        s--, t--;

        graph[{s, t}] = {d, time};
        graph[{t, s}] = {d, time};
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(n, LONG_LONG_MAX));

    // way[msk][node] 現在nodeにいるときの方法数
    vector<vector<ll>> way(1 << n, vector<ll>(n, 0));

    dp[1][0] = 0;
    way[1][0] = 1;

    for (int msk = 1; msk < (1 << n); msk++)
    {
        for (int i = 0; i < n; i++)
        {
            int before = msk & ~(1 << i);
            for (int k = 0; k < n; k++)
            {
                if (before & (1 << k) && graph.count({k, i}) && dp[before][k] != LONG_LONG_MAX)
                    if (graph[{k, i}].second >= dp[before][k] + graph[{k, i}].first)
                    {
                        ll now_time_cost = dp[before][k] + graph[{k, i}].first;

                        if (dp[msk][i] > now_time_cost)
                        {
                            dp[msk][i] = dp[before][k] + graph[{k, i}].first;
                            way[msk][i] = way[before][k];
                        }
                        else if (dp[msk][i] == now_time_cost)
                        {
                            way[msk][i] += way[before][k];
                        }
                    }
            }
        }
    }

    ll min_dist = LONG_LONG_MAX;
    ll min_time_way;

    for (int i = 0; i < n; i++)
    {
        if (graph.count({i, 0}) && dp[(1 << n) - 1][i] != LONG_LONG_MAX)

            if (graph[{i, 0}].second >= dp[(1 << n) - 1][i] + graph[{i, 0}].first)
            {
                ll total_dist = dp[(1 << n) - 1][i] + graph[{i, 0}].first;
                if (total_dist < min_dist)
                {
                    min_dist = total_dist;
                    min_time_way = way[(1 << n) - 1][i];
                }
                else if (total_dist == min_dist)
                {
                    min_time_way += way[(1 << n) - 1][i];
                }
            }
    }

    if (min_dist != LONG_LONG_MAX)
        cout << min_dist << " " << min_time_way << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}