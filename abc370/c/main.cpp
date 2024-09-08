#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    string s, t;
    cin >> s >> t;

    vector<int> change_index;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] > t[i])
            change_index.push_back(i);
    }

    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < t[i])
            change_index.push_back(s.size() - i - 1);
    }

    vector<string> ans;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());

    for (auto i : change_index)
    {
        s[i] = t[i];
        ans.push_back(s);
    }

    if (ans.size() == 0)
        cout << 0 << endl;
    else
    {
        cout << ans.size() << endl;

        for (string a : ans)
            cout << a << endl;
    }

    return 0;
}