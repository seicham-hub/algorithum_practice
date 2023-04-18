// https://atcoder.jp/contests/abc128/tasks/abc128_c

// 解けなかった...→一つの電球が点灯しているとき次の電球は？のループしか思いつかない、どう書けば実装できるか思いつかない
// 初めにあり得る電球のONOFFパターンすべてを持っておく！

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    int n, m, k[11], s[11][11], p[11], ans = 0;

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> s[i][j];
        }
    }

    for (int i = 1; i <= m; i++)
        cin >> p[i];

    // ランプの状態を整数値に一対一に紐づける
    for (int msk = 0; msk < (1 << n); msk++)
    {
        int onLump = 0;
        for (int i = 1; i <= m; i++)
        {

            int onSwich = 0;
            for (int j = 1; j <= k[i]; j++)
            {
                if (msk & (1 << s[i][j] - 1))
                    onSwich++;
            }
            if (onSwich % 2 == p[i])
                onLump++;
        }
        if (onLump == m)
            ans++;
    }

    cout << ans << endl;

    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int N, M;
//     vector<int> S[10];
//     int P[10];

//     cin >> N >> M;
//     for (int i = 0; i < M; i++)
//     {
//         int k;
//         cin >> k;
//         for (int j = 0; j < k; j++)
//         {
//             int s;
//             cin >> s;
//             s--;
//             S[i].push_back(s);
//         }
//     }

//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {

//             cout << S[i][j] << endl;
//         }
//     }

//     for (int i = 0; i < M; i++)
//         cin >> P[i];

//     int ans = 0;
//     // << はビットシフト　N=3の時は 000(0) 001(1) 010(2) のようになる。
//     // ビットマスクを利用して、電球のON,OFFのすべての状態を網羅することができる。
//     for (int msk = 0; msk < (1 << N); msk++)
//     {
//         int ok = 0;
//         for (int m = 0; m < M; m++)
//         {
//             int cnt = 0;
//             // S[m]の各要素をひとつずつ取り出す、要素はループ内でsで受ける。
//             for (int s : S[m])
//                 // &はビットごとのand演算子。2つの整数を引数にとり、それらの整数の各ビットに対して、AND操作を実行。
//                 // 両方の対応するビットが1(オン)の場合にのみ1を返し、それ以外の場合は0を返す。
//                 // すべてのスイッチの状態（msk)をforで探索し、今考えている電球のスイッチがONになっているかどうか調べる。
//                 if (msk & (1 << s))
//                     cnt++;
//             if (cnt % 2 == P[m])
//                 ok++;
//         }
//         if (ok == M)
//             ans++;
//     }
//     cout << ans << endl;
//     return 0;
// }

// *
// 0418実施分　自分のコード
// *
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, m, k[11], s[11][11], p[11], result = 0;
//     bool onOff[11];
//     cin >> n >> m;

//     for (int i = 1; i <= m; i++)
//     {
//         cin >> k[i];
//         for (int j = 1; j <= k[i]; j++)
//         {
//             cin >> s[i][j];
//         }
//     }

//     for (int i = 1; i <= m; i++)
//     {
//         cin >> p[i];
//     }

//     for (int i=1;i<=m;i++){

//     }

//     cout << result << endl;

//     return 0;
// }
