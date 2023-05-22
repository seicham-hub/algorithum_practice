#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flg1 = false, flg2 = true;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'o')
            flg1 = true;
        if (s[i] == 'x')
            flg2 = false;
    }

    if (flg1 == true && flg2 == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}