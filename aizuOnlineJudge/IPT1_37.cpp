
// Transformation
// 0316もう一度

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, order, p;
    int count, a, b;

    cin >> str;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> order;

        if (order == "print")
        {
            cin >> a >> b;
            cout << str.substr(a, b - a + 1) << endl;
        }
        else if (order == "reverse")
        {
            cin >> a >> b;

            for (int j = 0; j < (b - a + 1) / 2; j++)
            {
                char tempChar;
                tempChar = str[a + j];
                str[a + j] = str[b - j];
                str[b - j] = tempChar;
            }
        }
        else if (order == "replace")
        {
            cin >> a >> b >> p;
            int pi = 0;
            for (int j = a; j <= b; j++)
            {
                str[j] = p[pi];
                pi++;
            }
        }
    }

    return 0;
}
