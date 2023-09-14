#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);

    vector<vector<int>> s(101, vector<int>(101, 0));

    rep(i, n)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];

        for (int j = a[i] + 1; j <= b[i]; j++)
        {
            for (int k = c[i] + 1; k <= d[i]; k++)
            {
                s[j][k] = 1;
            }
        }
    }

    int ans = 0;

    rep(i, 101)
    {
        rep(j, 101)
        {
            if (s[i][j] == 1)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}