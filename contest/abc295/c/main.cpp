#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);

    vector<int> colorCnt(1e9 + 1);
    ll ans = 0;

    rep(i, n) cin >> a[i];

    rep(i, n)
    {
        colorCnt[a[i]]++;
        if (colorCnt[a[i]] == 2)
        {
            ans++;
            colorCnt[a[i]] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}