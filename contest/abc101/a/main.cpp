#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    string s;

    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+')
            ans++;
        else
            ans--;
    }

    cout << ans << endl;

    return 0;
}