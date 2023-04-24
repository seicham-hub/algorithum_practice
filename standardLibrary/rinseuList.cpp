// https://qiita-user-contents.imgix.net/https%3A%2F%2Fqiita-image-store.s3.ap-northeast-1.amazonaws.com%2F0%2F507979%2F443cfe0d-3eeb-17ea-e12a-45c2100ae2d9.png?ixlib=rb-4.0.0&auto=format&gif-q=60&q=75&w=1400&fit=max&s=661cccafd8ab3b355fb24a36bc61a242
// ここでは、グラフの頂点数を N、辺数を Mとします。
// 隣接行列・隣接リスト両方のグラフ表現方法において、普通の配列を使った場合、メモリ使用量O(N^2)
//  かかってしまうため、N=100000,M=300000
// など大きいデータの場合にメモリ制限超過を引き起こします。

// しかし、vector 型でそれぞれの頂点における隣接頂点を格納しておくと、合計メモリ使用量 O(M)
// で済み、データがある程度大きくてもメモリ制限超過 (MLE) を引き起こしません。

#include <bits/stdc++.h>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> G[100009];

int main()
{
    // グラフを入力する
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> A[i] >> B[i];

    // グラフを隣接リストで表現する。
    for (int i = 0; i <= M; i++)
    {
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 隣接リストで表現されたグラフを出力する。
    for (int i = 1; i <= N; i++)
    {
        cout << "Vertex #" << i << ": {";
        for (int j = 0; j < G[i].size(); j++)
        {
            if (j >= 1)
                cout << " ";
            cout << G[i][j];
        }
        cout << "}" << endl;
    }

    return 0;
}
