// n個の整数A1,...Anからいくつかを選び、合計をKにすることができるかどうか
// 動的計画法でO(NK)で解ける。

#include <iostream>
using namespace std;

int N, K, A[1009];
int dp[10009];

int main()
{
    // 入力
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // ここからが DP の遷移
    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = K - A[i]; j >= 0; j--)
        {
            if (dp[j] == 1)
                dp[j + A[i]] = 1;
        }
    }

    // 答えを出力
    if (dp[K] == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}