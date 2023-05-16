#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, init = 0;
    string s;
    cin >> s >> n;

    vector<int> canChange;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?')
            canChange.push_back(i);
        if (s[i] == '1')
        {
            init += pow(2, s.size() - 1 - i) * 1;
        }
    }

    if (init > n)
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int c : canChange)
    {
        int in = init;
        init += pow(2, s.size() - 1 - c) * 1;
        if (init <= n)
        {
            continue;
        }
        else
        {
            init = in;
        }
    }

    cout << init << endl;

    return 0;
}
