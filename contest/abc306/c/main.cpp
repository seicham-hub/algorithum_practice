#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(3 * n);

    vector<int> cnt(n + 1, 0);
    vector<int> f(n + 1);
    map<int, int> ans;

    rep(i, 3 * n)
    {
        cin >> a[i];
        cnt[a[i]]++;
        if (cnt[a[i]] == 2)
        {
            f[a[i]] = i;
            ans[i] = a[i];
        }
    }

    sort(f.begin(), f.end());

    for (int i = 1; i <= n; i++)
    {
        int amount = f[i];

        if (i != n)
            cout << ans[amount] << " ";
        else
            cout << ans[amount] << endl;
    }

    return 0;
}