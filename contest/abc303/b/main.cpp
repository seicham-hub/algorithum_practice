#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, a[60][60], ans = 0;
    int dx[2] = {-1, 1};

    cin >> n >> m;

    vector<vector<bool>> ma(n + 1, vector<bool>(n + 1, false));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (j + dx[k] < n && 0 <= j + dx[k])
                {
                    int now = a[i][j];
                    int next = a[i][j + dx[k]];
                    ma[now][next] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!ma[i][j] && i < j)
            {
                ans++;
            }
            // cout << i << " " << j << ma[n][j] << endl;
        }
    }

    cout << ans << endl;
    return 0;
}