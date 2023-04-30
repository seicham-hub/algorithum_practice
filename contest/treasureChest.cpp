#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, first = 0, middle = 0, end = 0;
    bool flg = false;

    string s;

    cin >> n >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '|')
        {
            if (!flg)
            {
                first = i;
                flg = true;
            }
            else
            {
                end = i;
            }
        }
        if (s[i] == '*')
            middle = i;
    }

    if (first < middle && middle < end)
        cout << "in" << endl;
    else
        cout << "out" << endl;

    return 0;
}
