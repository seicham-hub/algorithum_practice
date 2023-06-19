#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    string s, ans = "";
    cin >> n >> s;

    rep(i, n)
    {
        ans = ans + s[i] + s[i];
    }

    cout << ans << endl;

    return 0;
}