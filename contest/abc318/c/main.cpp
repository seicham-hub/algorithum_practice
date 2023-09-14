#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, d, p;

    cin >> n >> d >> p;

    vector<int> f(n);

    long long f_sum = 0;

    rep(i, n)
    {
        cin >> f[i];
        f_sum += f[i];
    }

    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    vector<long long> p_sum(n + 1);
    rep(i, n)
    {
        p_sum[i + 1] = p_sum[i] + f[i];
    }

    vector<long long> pr(n + 1);
    rep(i, n + 1)
    {

        if (i % d != 0)
        {
            pr[i] = f_sum - p_sum[i] + (long long)p * ((i / d) + 1);
        }
        else
        {
            pr[i] = f_sum - p_sum[i] + (long long)p * (i / d);
        }
    }

    long long ans = 1e18;

    rep(i, n + 1) ans = min(ans, pr[i]);

    cout << ans << endl;

    return 0;
}