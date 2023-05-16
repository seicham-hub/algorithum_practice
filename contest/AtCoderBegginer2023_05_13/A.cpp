#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t = 0, a = 0;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'T')
            t++;
        else
            a++;
    }

    if (t > a)
        cout << "T" << endl;
    else if (t < a)
        cout << "A" << endl;
    else
        cout << char('T' + 'A' - s.back()) << endl;

    return 0;
}

// 自分の解答
//

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, aP = 0, tP = 0;
//     string s;
//     cin >> n >> s;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == 'T')
//         {
//             tP++;
//         }
//         else if (s[i] == 'A')
//         {
//             aP++;
//         }
//     }

//     if (tP - aP > 0)
//     {
//         cout << "T" << endl;
//     }
//     else if (tP - aP < 0)
//     {
//         cout << "A" << endl;
//     }
//     else if (tP - aP == 0)
//     {
//         if (s[s.size() - 1] == 'A')
//         {
//             cout << "T" << endl;
//         }
//         else
//         {
//             cout << "A" << endl;
//         }
//     }

//     return 0;
// }
