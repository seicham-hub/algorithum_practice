#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    char before;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            before = s[i];
            continue;
        }
        if (s[i] == before)
        {
            cout << "No" << endl;
            return 0;
        }
        before = s[i];
    }

    cout << "Yes" << endl;
    return 0;
}