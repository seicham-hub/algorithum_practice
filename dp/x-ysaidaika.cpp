// https://atcoder.jp/contests/dp/tasks/dp_l
// 0504もう一度

/*
・ありうる局面の列挙
・局面間の遷移を列挙

dp[i][j] = 元の数列から連続する区間ai,....,aj-1を抜き出した状態の局面から出発して
双方最善を尽くした時のX-Yの値
※左側は閉区間で、右側が回区間

本来であればDPテーブル匂いて、「手番が先手か後手か」の情報を持たせたいが、
今回はj-iで自然にわかる。

*/

#include <iostream>
#include <vector>
using namespace std;

// DP テーブル
long long dp[3100][3100];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 初期条件
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;

    // DP
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len <= n; i++)
        {
            int j = i + len;

            // 先手番 (自分のターンの残り石の個数と最初の残し石数の奇遇が一致する)
            if ((n - len) % 2 == 0)
                dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);

            // 後手番
            else
                dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
        }
    }

    cout << dp[0][n] << endl;

    return 0;
}