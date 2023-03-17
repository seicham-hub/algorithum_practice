// Finding a Word

// 0316もう一度

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main()
{

    string W, Ti = "";
    int result = 0;
    char currentC;

    cin >> W;
    cin >> Ti;

    while (Ti != "END_OF_TEXT")
    {

        for (int i = 0; i < Ti.size(); i++)
        {
            if (Ti[i] >= 'A' && Ti[i] <= 'Z')
                Ti[i] += 'a' - 'A';
        }
        if (Ti == W)
            result += 1;

        cin >> Ti;
    }

    cout << result << endl;
}

// なぜかタイムアウトエラー　getcharはstdio.hインクルード必要
// #include <iostream>
// #include <stdio.h>
// #include <string>
// using namespace std;

// int main()
// {

//     string W, Ti;
//     int result = 0;
//     char currentC;

//     cin >> W;

//     while (true)
//     {
//         Ti = "";
//         while ((currentC = getchar()) != ' ' && currentC != '\n')
//         {
//             Ti += currentC;
//         }

//         if (Ti == "END_OF_TEXT")
//             break;

//         if (Ti == W)
//             result += 1;
//     }

//     cout << (int)result << endl;

//     return 0;
// }
