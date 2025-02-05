#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    string s, t;
    cin >> s >> t;

    string ans = "";
    int ind = 0;

    rep(i, s.size())
    {
        char now = t[ind];
        if (now == toupper(s[i]))
        {
            ans += now;
            ind++;
        }
        if (ans.size() >= 3)
            break;
    }

    if (ans.size() == 2)
    {
        ans += 'X';
    }

    if (ans == t)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}