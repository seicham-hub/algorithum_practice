#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    string s, t;

    cin >> n >> s >> t;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[i])
            cnt++;
        if (s[i] == '1' && t[i] == 'l')
            cnt++;
        if (s[i] == 'l' && t[i] == '1')
            cnt++;
        if (s[i] == '0' && t[i] == 'o')
            cnt++;
        if (s[i] == 'o' && t[i] == '0')
            cnt++;
    }

    if (cnt == n)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}