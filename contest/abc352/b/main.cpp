#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string s, t;
    cin >> s >> t;

    vector<int> ans;

    int now = 0;
    rep(i, t.size())
    {

        if (s[now] == t[i])
        {
            ans.push_back(i + 1);
            now++;
        }
    }

    rep(i, ans.size()) cout << ans[i] << " ";

    return 0;
}