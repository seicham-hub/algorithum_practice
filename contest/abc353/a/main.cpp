#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);

    rep(i, n) cin >> h[i];

    int base = h[0];
    rep(i, n)
    {
        if (h[i] > base)
        {
            cout << i + 1 << endl;
            ;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}