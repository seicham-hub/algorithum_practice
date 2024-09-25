#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, t, p;
    cin >> n >> t >> p;

    vector<int> hair(n);

    rep(i, n) cin >> hair[i];

    int ans;
    rep(i, t + 1)
    {
        int count = 0;
        rep(j, n)
        {
            if (hair[j] + i >= t)
                count++;
        }

        if (count >= p)
        {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}