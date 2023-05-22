// https://atcoder.jp/contests/abc298/tasks/abc298_b
// 行列を回転させる時、a(行)(列)にはいるのは、a(後ろから何番目か)(行)である。i,jが０~始まるかで異なる結果となる...

// 0521もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[110][110], b[110][110];
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> b[i][j];
        }
    }

    // 最大４回
    for (int num = 0; num < 4; num++)
    {
        int ad[110][110] = {0};
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                ad[i][j] = a[n + 1 - j][i];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = ad[i][j];
            }
        }

        bool ok = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                {
                    if (b[i][j] != 1)
                        ok = false;
                }
            }
        }

        if (ok == true)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}