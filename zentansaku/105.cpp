// https://atcoder.jp/contests/abc106/tasks/abc106_b
// 0414もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 0;
    cin >> n;

    // for(int i=1;<=n;i+=2)とすれば奇数のみに絞れる
    for (int i = 1; i <= n; i++)
    {

        int yakusuQuantity = 0;
        // j<=iとすれば商が0か気にしなくてよい
        for (int j = 1; j <= n; j++)
        {

            if (i / j != 0 && i % j == 0)
            {

                yakusuQuantity++;
            }
        }

        if (i % 2 == 1 && yakusuQuantity == 8)
            result++;
    }

    cout << result << endl;
    return 0;
}
