#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    string n;
    cin >> n;

    int one = 0;
    int two = 0;
    int three = 0;

    rep(i, n.size())
    {
        if (n[i] == '1')
            one++;
        if (n[i] == '2')
            two++;
        if (n[i] == '3')
            three++;
    }

    if (one == 1 && two == 2 && three == 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}