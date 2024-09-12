// https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d
// 分からなかった
// 2024_09_09もう一度

// M<=20というのがヒント
// 2^20にすれば行けるのでは？
// 出てくる種類の順番を決めてみる。 20!だが、これをbitにすれば2^20で行けそう

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> plush(n);
    vector<int> kind_count(m, 0);
    vector<vector<int>> accum(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {

        cin >> plush[i];
        plush[i]--;
        kind_count[plush[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i - 1 < 0)
            {
                if (plush[i] == j)
                    accum[i][j] = 1;
            }
            else
            {

                accum[i][j] += accum[i - 1][j];
                if (plush[i] == j)
                    accum[i][j]++;
            }
        }
    }

    vector<int> dp(1 << m, 1e6);
    dp[0] = 0;

    auto count = [&](int &kind, int &msk) -> int
    {
        int done = 0;
        for (int i = 0; i < m; i++)
        {
            if (msk & 1 << i)
                done += kind_count[i];
        }

        int exist = accum[done + kind_count[kind] - 1][kind];
        if (done - 1 >= 0)
            exist -= accum[done - 1][kind];

        return kind_count[kind] - exist;
    };

    for (int msk = 0; msk < (1 << m) - 1; msk++)
    {
        for (int i = 0; i < m; i++)
        {
            int bit = 1 << i;
            if (!(msk & bit))
                dp[msk | bit] = min(dp[msk | bit], dp[msk] + count(i, msk));
        }
    }

    cout << dp[(1 << m) - 1] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     vector<int> init(n);
//     vector<int> count_kinds(m, 0);
//     vector<vector<int>> accum(n, vector<int>(m, 0));

//     for (int i = 0; i < n; i++)
//     {
//         int p;
//         cin >> p;
//         p--;
//         init[i] = p;
//         count_kinds[p]++;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         accum[i][init[i]]++;
//         if (i - 1 >= 0)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 accum[i][j] += accum[i - 1][j];
//             }
//         }
//     }

//     vector<int> dp(1 << m, 1e6);
//     dp[0] = 0;

//     function<int(int, int)> count = [&](int kind, int msk) -> int
//     {
//         // インデックス開始位置を調べる
//         int start = 0;
//         for (int i = 0; i < m; i++)
//         {
//             if (msk & (1 << i))
//                 start += count_kinds[i];
//         }

//         int exist = accum[start + count_kinds[kind] - 1][kind];
//         if (start - 1 >= 0)
//             exist -= accum[start - 1][kind];

//         // 今回区間に並べる種類を何個持ってくる必要があるか
//         return count_kinds[kind] - exist;
//     };

//     for (int msk = 0; msk < (1 << m) - 1; msk++)
//     {
//         for (int i = 0; i < m; i++)
//         {
//             int bit = 1 << i;
//             if (!(msk & bit))
//                 dp[msk | bit] = min(dp[msk | bit], dp[msk] + count(i, msk));
//         }
//     }

//     cout << dp[(1 << m) - 1] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// const int INF = 1e9; // 無限大として扱う大きな数
// //---------------------------------------------------------------------------------------------------
// int main()
// {
//     int N, M;
//     cin >> N >> M;

//     vector<int> A(N);
//     vector<int> cnt(M, 0);                         // 各種類の個数を数える
//     vector<vector<int>> rui(M, vector<int>(N, 0)); // 累積和の配列
//     vector<int> dp(1 << M, INF);                   // DP配列、状態数は 2^M

//     for (int i = 0; i < N; i++)
//     {
//         cin >> A[i];
//         A[i]--; // 0-indexedにする
//         cnt[A[i]]++;
//         rui[A[i]][i] = 1;
//     }

//     // 累積和を構築
//     for (int a = 0; a < M; a++)
//     {
//         for (int i = 1; i < N; i++)
//         {
//             rui[a][i] += rui[a][i - 1];
//         }
//     }

//     dp[0] = 0; // 初期状態

//     // ビットマスクDPを実行
//     for (int msk = 0; msk < (1 << M); msk++)
//     {
//         int done = 0;

//         // 既に選ばれた種類の合計数を数える
//         for (int i = 0; i < M; i++)
//             if (msk & (1 << i))
//                 done += cnt[i];

//         // 次に選べる種類を決める
//         for (int nxt = 0; nxt < M; nxt++)
//         {
//             if (!(msk & (1 << nxt)))
//             {                      // まだ選ばれていない種類
//                 int tot = dp[msk]; // 現在の最小コスト

//                 // 種類nxtのぬいぐるみが選んだものの後ろにcnt個並んだ時
//                 int nxt_cnt = rui[nxt][done + cnt[nxt] - 1];
//                 if (done > 0)
//                     nxt_cnt -= rui[nxt][done - 1];

//                 // [done, done+cnt[nxt])について初期状態がnxtでない個数をカウント
//                 // 取り出す必要があるぬいぐるみの個数
//                 tot += cnt[nxt] - nxt_cnt;

//                 // 次の状態の最小コストを更新
//                 dp[msk | (1 << nxt)] = min(dp[msk | (1 << nxt)], tot);
//             }
//         }
//     }

//     // 最終状態の最小コストを出力
//     cout << dp[(1 << M) - 1] << endl;

//     return 0;
// }
