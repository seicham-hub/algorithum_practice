// https://atcoder.jp/contests/abc366/tasks/abc366_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);

    int m = 0;
    rep(i, n)
    {

        cin >> s[i];
        m = max(m, int(s[i].size()));
    }

    reverse(s.begin(), s.end());

    string init = "";
    rep(i, n) init += '*';
    vector<string> t(m, init);

    rep(i, n)
    {
        string col = s[i];

        rep(j, m)
        {
            if (col.size() > j)
                t[j][i] = col[j];
        }
    }

    for (string &ti : t)
    {
        // while (*(ti.end() - 1) == '*')
        // {

        //     ti.erase(ti.end() - 1, ti.end());
        // }

        while (ti.back() == '*')
            ti.pop_back();
    }

    for (string ti : t)
    {
        cout << ti << endl;
    }

    return 0;
}