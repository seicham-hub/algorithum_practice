#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    vector<int> a(64);
    unsigned long long ans = 0;

    rep(i, 64)
    {
        cin >> a[i];
    }

    for (int i = 63; i >= 0; i--)
    {
        if (a[i] == 1)
        {

            ans = ans | (1LL << i);
        }
    }

    cout << ans << endl;
    return 0;
}