#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    int sweet_count = 0;

    rep(i, n)
    {
        string s;
        cin >> s;

        if (sweet_count >= 2)
        {
            cout << "No" << endl;
            return 0;
        }

        if (s == "sweet")
            sweet_count++;
        else
            sweet_count = 0;
    }

    cout << "Yes" << endl;

    return 0;
}