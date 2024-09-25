#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> a_cp = a;

    sort(a_cp.begin(), a_cp.end());

    auto target = a_cp.end() - 2;

    int ans = 0;
    rep(i, n)
    {
        if (*target == a[i])
            ans = i + 1;
    }

    cout << ans << endl;

    return 0;
}