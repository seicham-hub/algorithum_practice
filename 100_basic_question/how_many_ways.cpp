// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_7_B&lang=ja

// B - 105
// B - ATCoder

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, ans = 0;
    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            for (int k = j + 1; k <= n; k++)
                if (i + j + k == x)
                    ans++;
    }
    cout << ans << endl;

    return 0;
}