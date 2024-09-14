#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    string s;
    cin >> s;

    bool is_exist_rice = false;

    for (char si : s)
    {
        if (is_exist_rice && si == 'M')
        {
            cout << "Yes" << endl;
            return 0;
        }

        if (si == 'R')
            is_exist_rice = true;
    }

    cout << "No" << endl;

    return 0;
}