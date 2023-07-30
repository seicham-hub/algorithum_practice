#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);

    rep(i, n)
    {
        cin >> s[i];
    }

    rep(i, n)
    {
        rep(j, m)
        {
            if (n - i >= 9 && m - j >= 9)
            {

                bool bl1 = true;
                rep(k, 3)
                {
                    rep(l, 3)
                    {
                        if (s[i + k][j + l] != '#')
                            bl1 = false;
                        if (s[i + 6 + k][j + 6 + l] != '#')
                            bl1 = false;
                    }
                }

                bool whi1 = true;

                rep(k, 4)
                {
                    if (s[i + k][j + 3] != '.')
                        whi1 = false;

                    if (s[i + 5 + k][j + 5] != '.')
                        whi1 = false;
                }
                rep(k, 3)
                {
                    if (s[i + 3][j + k] != '.')
                        whi1 = false;
                    if (s[i + 5][j + 6 + k] != '.')
                        whi1 = false;
                }

                if (bl1 && whi1)
                {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
    }

    return 0;
}