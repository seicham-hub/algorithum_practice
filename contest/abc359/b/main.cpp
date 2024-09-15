// https://atcoder.jp/contests/abc359/tasks/abc359_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);

    rep(i, 2 * n) cin >> a[i];

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2 * n - 2; j++)
        {
            if (i == a[j])
                if (i == a[j + 2])
                    ans++;
        }
    }

    cout << ans << endl;

    return 0;
}