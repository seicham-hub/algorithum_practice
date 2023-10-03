#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    string t_top = t.substr(0, n);
    string t_end = t.substr(m - n, n);

    if (s == t_top && s == t_end)
        cout << 0 << endl;
    else if (s == t_top)
        cout << 1 << endl;
    else if (s == t_end)
        cout << 2 << endl;
    else
        cout << 3 << endl;

    return 0;
}