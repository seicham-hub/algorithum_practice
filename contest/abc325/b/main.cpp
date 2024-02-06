#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;

    vector<int> x(n), w(n);

    rep(i, n)
    {
        int wi, xi;
        cin >> wi >> xi;
        w[i] = wi;
        x[i] = xi;
    }

    for (int i = 0; i <= 23; i++)
    {
        ll now_sum = 0;
        rep(j, n)
        {
            int t = x[j] + i;
            if (t > 23)
                t -= 24;
            if (9 <= t && t <= 17)
                now_sum += w[j];
        }
        ans = max(ans, now_sum);
    }

    cout << ans << endl;

    return 0;
}