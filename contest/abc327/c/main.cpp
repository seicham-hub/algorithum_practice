#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    vector<vector<int>> a(9, vector<int>(9));

    rep(i, 9) rep(j, 9)
    {
        cin >> a[i][j];
        a[i][j]--;
    }

    // 行について調べる

    vector<int> cntR(9);
    vector<int> cntC(9);
    rep(i, 9)
    {
        bool isOk = true;
        rep(j, 9)
        {
            cntR[a[i][j]]++;
        }
        rep(j, 9)
        {
            cntC[a[j][i]]++;
        }

        rep(j, 9)
        {
            if (cntR[j] != i + 1 || cntC[j] != i + 1)
            {
                isOk = false;
                break;
            }
        }

        if (!isOk)
        {
            cout << "No" << endl;
            return 0;
        }
    }

    vector<int> cntB(9);
    rep(i, 3)
    {
        bool isOk = true;
        rep(j, 3)
        {
            rep(k, 3) rep(l, 3)
            {
                cntB[a[i * 3 + k][j * 3 + l]]++;
            }

            rep(k, 9) if (cntB[k] != 3 * i + j + 1)
            {
                isOk = false;
                break;
            }
            if (!isOk)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}