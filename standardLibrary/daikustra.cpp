// N個の都市と、M個の道路がある。
// ある都市から各都市まで移動する時間の最短を求めることができる。
// 計算量O(MlogN)

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int N, M, S, A[500009], B[500009], C[500009];
int dist[100009];
vector<pair<int, int>> G[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

int main()
{
    // グラフを入力する
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d%d%d", &A[i], &B[i], &C[i]);
        G[A[i]].push_back(make_pair(B[i], C[i]));
        G[B[i]].push_back(make_pair(A[i], C[i]));
    }
    scanf("%d", &S);

    // 距離を初期化する
    for (int i = 1; i <= N; i++)
        dist[i] = 1000000007;

    // 優先度付きキューには (距離, 頂点番号) の組を入れる
    Q.push(make_pair(0, S));
    dist[S] = 0;
    while (!Q.empty())
    {
        int pos = Q.top().second;
        Q.pop();
        for (int i = 0; i < G[pos].size(); i++)
        {
            int to = G[pos][i].first, cost = G[pos][i].second;
            if (dist[to] > dist[pos] + cost)
            {
                dist[to] = dist[pos] + cost;
                Q.push(make_pair(dist[to], to));
            }
        }
    }

    // 距離を出力する
    for (int i = 1; i <= N; i++)
        printf("%d\n", dist[i]);
    return 0;
}