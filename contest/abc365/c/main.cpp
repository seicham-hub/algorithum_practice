#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    ll n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll left = 0;
    ll right = 1e18;

    auto check = [&](ll x)
    {
        ll cost = 0;
        rep(i, n)
        {
            cost += min((ll)a[i], x);
        }

        return cost > m;
    };

    while (abs(left - right) > 1)
    {
        ll mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }

    if (right == 1e18)
        cout << "infinite" << endl;
    else
        cout << left << endl;

    return 0;
}