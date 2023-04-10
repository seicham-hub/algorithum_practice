#include <iostream>
#include <string>
using namespace std;

int main()
{
    int result = 0;
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            result++;
    }

    cout << result << endl;

    return 0;
}
