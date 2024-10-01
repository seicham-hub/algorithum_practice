#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    vector<string> s(12);

    int ans = 0;
    rep(i, 12)
    {
        cin >> s[i];
        if (i + 1 == s[i].size())
            ans++;
    }

    cout << ans << endl;

    return 0;
}