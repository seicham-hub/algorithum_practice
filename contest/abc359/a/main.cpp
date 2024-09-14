#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    int ans = 0;

    vector<string> s(n);
    rep(i, n)
    {
        cin >> s[i];

        if (s[i] == "Takahashi")
            ans++;
    }

    cout << ans << endl;

    return 0;
}