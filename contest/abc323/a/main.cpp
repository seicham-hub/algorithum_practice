#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string s;
    cin >> s;

    for (int i = 1; i < 16; i++)
    {
        if (i % 2 == 1 && s[i] != '0')
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}