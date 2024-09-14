#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int r, g, b;
    cin >> r >> g >> b;

    string c;
    cin >> c;

    if (c == "Red")
        r = 200;
    if (c == "Green")
        g = 200;
    if (c == "Blue")
        b = 200;

    int ans = 300;
    ans = min(r, g);
    ans = min(ans, b);

    cout << ans << endl;

    return 0;
}