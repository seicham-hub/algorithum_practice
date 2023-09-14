#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {

        int nn = i - m;

        if (nn >= 0)
        {
            if (nn % p == 0)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}