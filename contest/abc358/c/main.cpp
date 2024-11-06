// https://atcoder.jp/contests/abc358/tasks/abc358_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    rep(i, n) cin >> s[i];

    int ans = 100;

    for (int msk = 0; msk < (1 << n); msk++)
    {
        int cnt = 0;
        vector<bool> taste(m);

        for (int i = 0; i < n; i++)
        {
            if (msk & 1 << i)
            {
                rep(j, s[i].size())
                {
                    if (s[i][j] == 'o')
                        taste[j] = true;
                }
                cnt++;
            }
        }

        bool isOk = true;
        rep(k, m) if (!taste[k]) isOk = false;

        if (isOk)
            ans = min(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}