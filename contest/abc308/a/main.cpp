#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    vector<int> s(8);

    rep(i, 8) cin >> s[i];

    bool ans = true;

    rep(i, 8)
    {
        if (s[i] < 100 || s[i] > 675)
        {
            ans = false;
            break;
        }
        if (s[i] % 25 != 0)
        {
            ans = false;
            break;
        }
        if (i >= 1 && s[i - 1] > s[i])
        {
            ans = false;
            break;
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}