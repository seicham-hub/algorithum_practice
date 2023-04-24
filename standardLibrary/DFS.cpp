#include <iostream>
#include <queue>
using namespace std;

int H, W;           // 迷路の大きさ
char c[1009][1009]; // 迷路のマップ、'.' の場合白マス、'#' の場合黒マス
int dist[1009][1009];

int main()
{
    // 迷路を入力する
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
            cin >> c[i][j];
    }

    // 距離を初期化する
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
            dist[i][j] = 1000000007;
    }

    // 幅優先探索により、最短移動回数を求める
    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));
    dist[1][1] = 0;

    while (!Q.empty())
    {
        int cx = Q.front().first, cy = Q.front().second;
        Q.pop();

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int ex = cx + dx[i], ey = cy + dy[i];
            if (c[ex][ey] != '.' || dist[ex][ey] != 1000000007)
                continue;
            Q.push(make_pair(ex, ey));
            dist[ex][ey] = dist[cx][cy] + 1;
        }
    }

    // 最短距離を出力する
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (j >= 2)
                cout << " ";
            cout << dist[i][j];
        }
        cout << endl;
    }
    return 0;
}