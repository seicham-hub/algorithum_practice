#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    string td;
    cin >> n >> td;
    vector<string> s(n);

    vector<vector<int>> count_al(n, vector<int>(26, 0));
    rep(i, n)
            cin >>
        s[i];

    vector<int> ans;

    rep(i, n)
    {
        if (td.size() == s[i].size())
        {
            int diff = 0;
            rep(j, td.size())
            {
                if (s[i][j] != td[j])
                    diff++;
            }
            if (diff <= 1)
                ans.push_back(i + 1);
        }
        else if ((td.size() - s[i].size()) == 1)
        {
            int diff = 0;

            rep(j, td.size())
            {
                if (td[j] != s[i][j])
            }
        }
    }

    return 0;
}