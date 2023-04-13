#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, result = 0;
    string s;

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            if (s.substr(i, 3) == "ABC")
                result++;
        }
    }
    cout << result << endl;

    return 0;
}
