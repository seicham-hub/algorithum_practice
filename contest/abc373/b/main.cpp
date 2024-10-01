#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string s;
    cin >> s;
    map<char, int> mp;

    string base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    rep(i, s.size())
    {
        mp[s[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i < 26; i++)
    {
        ans += abs(mp[base[i]] - mp[base[i - 1]]);
    }

    cout << ans << endl;

    return 0;
}