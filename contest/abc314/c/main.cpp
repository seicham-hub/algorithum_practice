#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<int>> mp(m + 1);

    vector<int> c(n);
    rep(i, n)
    {
        cin >> c[i];
        mp[c[i]].push_back(i);
    }

    for (int i = 1; i <= m; i++)
    {
        string tmpS = s;
        for (int j = 0; j < mp[i].size(); j++)
        {
            if (mp[i].size() == 1)
                break;
            int nowI = mp[i][j];
            int nextI = mp[i][(j + 1) % mp[i].size()];

            s[nextI] = tmpS[nowI];
        }
    }

    cout << s << endl;

    return 0;
}