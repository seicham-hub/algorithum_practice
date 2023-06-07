#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    string s[9];

    char dy[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (s[i][j] == '*')
            {
                x = i;
                y = j;
            }
        }
    }

    cout << dy[y] << abs(x - 8) << endl;
    return 0;
}