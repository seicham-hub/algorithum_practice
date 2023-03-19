// Card Game
// 0316もう一度

#include <iostream>
#include <string>

using namespace std;

int main()
{

    int n, tPoint = 0, hPoint = 0;
    string tAnimal, hAnimal;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tAnimal >> hAnimal;
        if (tAnimal == hAnimal)
        {
            tPoint++;
            hPoint++;
        }
        else if (tAnimal.compare(hAnimal) > 0)
        {
            tPoint += 3;
        }
        else
        {
            hPoint += 3;
        }
    }

    cout << tPoint << " " << hPoint << endl;

    return 0;
}

// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     int n, i;
//     cin >> n;
//     string s1, s2;
//     int t = 0, h = 0;

//     for (i = 0; i < n; i++)
//     {
//         cin >> s1 >> s2;
//         if (s1.compare(s2) == 0)
//         {
//             t++, h++;
//         }
//         // 's1' -'s2'の結果と同じ
//         else if (s1.compare(s2) > 0)
//             t += 3;
//         else
//             h += 3;
//     }
//     cout << t << " " << h << endl;
// }

// 自分で書いたコード　rose roselle 等の場合考え切れてなかった
// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {

//     int n, taroPoint = 0, hanakoPoint = 0, size;
//     string tWord, hWord;

//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> tWord >> hWord;
//         if (tWord == hWord)
//         {
//             taroPoint += 1;
//             hanakoPoint += 1;
//         }
//         size = tWord.size() > hWord.size() ? tWord.size() : hWord.size();

//         for (int j = 0; j < size; j++)
//         {
//             if (tWord[j] - hWord[j] > 0)
//             {
//                 taroPoint += 3;
//                 break;
//             }
//             else if (tWord[j] - hWord[j] < 0)
//             {
//                 hanakoPoint += 3;
//                 break;
//             }
//         }
//     }

//     cout << taroPoint << " " << hanakoPoint << endl;

//     return 0;
// }
