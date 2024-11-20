#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string s;
    cin >> s;

    vector<int> ans;
    int n = s.size();

    int start = 1;

    while (start < s.size())
    {
        int tmp = 0;
        while (start < s.size() && s[start] != '|')
        {
            tmp++;
            start++;
        }
        ans.push_back(tmp);
        start++;
    }

    rep(i, ans.size()) cout << ans[i] << " ";

    return 0;
}