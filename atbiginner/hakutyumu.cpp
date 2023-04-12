// 0412もう一度

// 自分で書いたコードdreamの次にerが来たとき、dreamで区切るかdreamerで区切るか
// の判断がつかない
// dreamはdreamerの中に完全に被っており、このような関係をprefixと呼ぶ。
// 後ろから見よう！

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

int main()
{
    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for (int i = 0; i < 4; i++)
        reverse(divide[i].begin(), divide[i].end());

    bool can = true;
    for (int i = 0; i < S.size();)
    {
        bool can2 = false; // 4個の文字列たちどれかでdivideできるか

        for (int j = 0; j < 4; j++)
        {
            string d = divide[j];
            if (S.substr(i, d.size()) == d)
            {
                can2 = true;
                i += d.size(); // divide出来たらiを進める
            }
        }
        if (!can2)
        {
            can = false;
            break;
        }
    }

    if (can)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

// 自分で書いたコード
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int curStrInd = 0;
//     string s, t = "";
//     cin >> s;

//     while (true)
//     {

//         if (s[curStrInd] == 'd')
//         {
//             if (s.substr(curStrInd, 6) == "dreamer")
//             {
//                 t += "dreamer";
//                 curStrInd += 6;
//             }
//             else
//             {
//                 t += "dream";
//                 curStrInd += 5;
//             }
//         }
//         else if (s[curStrInd] == 'e')
//         {
//             if (s.substr(curStrInd, 6) == "eraser")
//             {
//                 t += "eraser";
//                 curStrInd += 6;
//             }
//             else
//             {
//                 t += "erase";
//                 curStrInd += 5;
//             }
//         }
//         else
//         {
//             cout << "NO" << endl;
//             break;
//         }

//         if (t.size() >= s.size())
//         {
//             if (t == s)
//                 cout << "YES" << endl;
//             else
//                 cout << "NO" << endl;
//             break;
//         }
//     }
//     return 0;
// }
