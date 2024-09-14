#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, a;
    cin >> n >> a;

    vector<int> t(n);
    rep(i, n)
    {
        int ti;

        cin >> ti;

        t[i] = ti + a;
    }

    for (int i = 1; i < n; i++)
    {
        if (t[i] - t[i - 1] < a)
            t[i] += a - (t[i] - t[i - 1]);
    }

    for (auto a : t)
    {
        cout << a << endl;
    }

    return 0;
}