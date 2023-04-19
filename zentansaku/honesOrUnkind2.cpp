#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[16], x[16][15], y[16][15], maxHonest = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }

    for (int msk = 0; msk < (1 << n); msk++)
    {
        int tmp_max = 0;
        bool mujun = false;
        for (int i = 1; i <= n; i++)
        {
            if (mujun)
                break;

            // mskの仮定における正直者のとき
            if (msk & (1 << i - 1))
            {
                tmp_max++;
                for (int j = 1; j <= a[i]; j++)
                {
                    // 正直者が正直と言っているのに仮定と違ったら
                    if (y[i][j] == 1 && !(msk & 1 << x[i][j] - 1))
                    {
                        mujun = true;
                        break;
                    }
                    // 正直者が不親切と言っているのに、仮定と違ったら
                    else if (y[i][j] == 0 && msk & 1 << x[i][j] - 1)
                    {

                        mujun = true;
                        break;
                    }
                }
            }
        }

        if (mujun == false)
            maxHonest = max(tmp_max, maxHonest);
    }

    cout << maxHonest << endl;

    return 0;
}
