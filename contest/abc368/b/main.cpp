// https://atcoder.jp/contests/abc368/tasks/abc368_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans = 0;

    auto compare = [](int a, int b)
    {
        return a > b;
    };

    while (true)
    {

        sort(a.begin(), a.end(), compare);
        a[0]--;
        a[1]--;
        ans++;

        int count = 0;
        rep(i, n)
        {
            if (a[i] >= 1)
                count++;
        }

        if (count <= 1)
            break;
    }

    cout << ans << endl;

    return 0;
}