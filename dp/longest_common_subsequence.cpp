// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=ja

// 2024_07_04もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    for (int count = 0; count < q; count++)
    {
        string A, B;

        cin >> A >> B;

        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = 1; i <= A.size(); i++)
        {
            for (int j = 1; j <= B.size(); j++)
            {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        cout << dp[A.size()][B.size()] << endl;
    }

    return 0;
}