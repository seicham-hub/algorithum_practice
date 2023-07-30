#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    vector<string> arr = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    string s;
    cin >> s;

    rep(i, arr.size())
    {
        if (s == arr[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}