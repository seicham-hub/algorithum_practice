// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d
// 分からなかった

// M<=20というのがヒント
// 2^20にすれば行けるのでは？
// 出てくる種類の順番を決めてみる。 20!だが、これをbitにすれば2^20で行けそう

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // 無限大として扱う大きな数
//---------------------------------------------------------------------------------------------------
int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> cnt(M, 0);                         // 各種類の個数を数える
    vector<vector<int>> rui(M, vector<int>(N, 0)); // 累積和の配列
    vector<int> dp(1 << M, INF);                   // DP配列、状態数は 2^M

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--; // 0-indexedにする
        cnt[A[i]]++;
        rui[A[i]][i] = 1;
    }

    // 累積和を構築
    for (int a = 0; a < M; a++)
    {
        for (int i = 1; i < N; i++)
        {
            rui[a][i] += rui[a][i - 1];
        }
    }

    dp[0] = 0; // 初期状態

    // ビットマスクDPを実行
    for (int msk = 0; msk < (1 << M); msk++)
    {
        int done = 0;

        // 既に選ばれた種類の合計数を数える
        for (int i = 0; i < M; i++)
            if (msk & (1 << i))
                done += cnt[i];

        // 次に選べる種類を決める
        for (int nxt = 0; nxt < M; nxt++)
        {
            if (!(msk & (1 << nxt)))
            {                      // まだ選ばれていない種類
                int tot = dp[msk]; // 現在の最小コスト

                // 種類nxtのぬいぐるみが選んだものの後ろにcnt個並んだ時
                int nxt_cnt = rui[nxt][done + cnt[nxt] - 1];
                if (done > 0)
                    nxt_cnt -= rui[nxt][done - 1];

                // [done, done+cnt[nxt])について初期状態がnxtでない個数をカウント
                // 取り出す必要があるぬいぐるみの個数
                tot += cnt[nxt] - nxt_cnt;

                // 次の状態の最小コストを更新
                dp[msk | (1 << nxt)] = min(dp[msk | (1 << nxt)], tot);
            }
        }
    }

    // 最終状態の最小コストを出力
    cout << dp[(1 << M) - 1] << endl;

    return 0;
}
