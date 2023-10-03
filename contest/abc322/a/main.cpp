#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, count = 0, ans = -1;
    cin >> n;
    string s;
    cin >> s;

    rep(i, n)
    {
        if (s[i] == 'A')
            count = 1;
        else if (s[i] == 'B' && count == 1)
            count = 2;
        else if (s[i] == 'C' && count == 2)
        {
            ans = i - 1;
            break;
        }
        else
            count = 0;
    }

    cout << ans << endl;

    return 0;
}