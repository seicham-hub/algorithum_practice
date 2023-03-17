// Counting Characters
// 0315もう一度
// 0316もう一度

#include <iostream>
#include <map>

using namespace std;

int main()
{

    int ch;

    map<int, int> mp = {};
    while ((ch = getchar()) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
            mp[ch] += 1;

        else if (ch >= 'A' && ch <= 'Z')
            mp[ch + 'a' - 'A'] += 1;
    }

    for (int i = 'a'; i <= 'z'; i++)
    {
        cout << (char)i << " : " << mp[i] << endl;
    }
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     int countTable[256] = {0};
//     char ch;

//     while ((ch = getchar()) != EOF)
//     {
//         countTable[ch]++;
//     }
//     for (int i = 'A'; i <= 'Z'; i++)
//         printf("%c : %d", i, countTable[i] + countTable[i - 32]);
// }

// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {

//     char ch;
//     map<char, int> arr;

//     for (char i = 'a'; i <= 'z'; i++)
//     {
//         arr[i] = 0;
//     }

//     while ((ch = getchar()) != EOF)
//     {
//         if (ch >= 'a' && ch <= 'z')
//             arr[ch] += 1;
//         else if (ch >= 'A' && ch <= 'Z')
//             arr[ch + ('a' - 'A')] += 1;
//     }

//     for (char i = 'a'; i <= 'z'; i++)
//     {
//         // charとちゃんと指定してあげる必要がある
//         cout << (char)i << " : " << arr[i] << endl;
//     }

//     return 0;
// }
