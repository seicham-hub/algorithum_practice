#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;
    map<char, int> left, right;

    for (int i = 'a'; i <= 'z'; i++)
    {
        left[i] = 0;
        right[i] = 0;
    }
    left['@'] = 0;
    right['@'] = 0;

    for (int i = 0; i < s.size(); i++)
    {
        left[s[i]] += 1;
        right[t[i]] += 1;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        // cout << (char)i << left[i] << right[i] << endl;
        if (left[i] == right[i])
            continue;
        else
        {
            if (i == 'a' || i == 't' || i == 'c' || i == 'o' || i == 'd' || i == 'e' || i == 'r')
            {

                // ちゃんと数字は明示してあげる必要がある。>0を省略する事はできない
                if (left[i] - right[i] > 0)
                {
                    right['@'] -= left[i] - right[i];
                }
                else if (right[i] - left[i] > 0)
                {
                    left['@'] -= right[i] - left[i];
                }
            }
            else
            {
                right['@'] = -100;
                left['@'] = -100;
                break;
            }
        }
    }

    if (right['@'] >= 0 && left['@'] >= 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
