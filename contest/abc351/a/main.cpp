#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    vector<int> a(9), b(8);

    int tTotal = 0;
    rep(i, 9)
    {
        cin >> a[i];
        tTotal += a[i];
    }

    int aTotal = 0;
    rep(i, 8)
    {
        cin >> b[i];
        aTotal += b[i];
    }

    cout << tTotal - aTotal + 1 << endl;

    return 0;
}