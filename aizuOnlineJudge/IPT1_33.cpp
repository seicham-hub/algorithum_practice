// Ring
// 0315もう一度

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, p;
    cin >> s >> p;
    s = s + s;

    if (s.find(p) != -1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

// 自分で書いたやつ↓
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {

//     string s, p, checkStr, rr;
//     bool result = false;

//     cin >> s;
//     cin >> p;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == p[0])
//         {
//             int pLen = p.size(), sLen = s.size();
//             if (sLen < i + pLen)
//             {
//                 checkStr = s.substr(i, sLen - i) + s.substr(0, pLen - sLen + i);
//             }
//             else
//             {
//                 checkStr = s.substr(i, p.size());
//             }

//             if (checkStr == p)
//                 result = true;
//         }
//     }

//     rr = result == false ? "No" : "Yes";

//     cout << rr << endl;

//     return 0;
// }
