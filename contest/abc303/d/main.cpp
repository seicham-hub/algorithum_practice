#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long x, y, z, ans = 0;
    string s;
    cin >> x >> y >> z >> s;
    bool cps = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a' && !cps)
        {
            ans += x;
        }
        else if (s[i] == 'A' && cps)
        {
            ans += y;
        }
        else
        {

            if (s[i] == 'a')
            {
            }
        }
    }

    cout < < < < endl;
    return 0;
}