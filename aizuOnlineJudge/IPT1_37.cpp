
// Transformation
// 0316もう一度

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(string str, int a, int b)
{

    for (int i = a; i <= b; i++)
        cout << str[i];
    cout << endl;
}

string reverse(string str, int a, int b)
{
    int left = a, right = b;
    while (left < right)
    {
        // インクリメントの後置きは実行される前の値が代入される
        swap(str[left++], str[right--]);
    }

    return str;
}

string replace(string str, string p, int a, int b)
{

    int p_length = b - a + 1;
    for (int i = 0; i < p_length; i++)
    {
        str[a + i] = p[i];
    }

    return str;
}

int main()
{
    string str, p, order;
    int q, a, b;

    cin >> str;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> order >> a >> b;
        switch (order[2])
        {
        case 'i':
            print(str, a, b);
            break;
        case 'v':

            str = reverse(str, a, b);
            break;
        case 'p':
            cin >> p;
            str = replace(str, p, a, b);
            break;
        }
    }
}

// #include <iostream>
// #include <string>
// using namespace std;

// int main()
// {
//     string str, order, p;
//     int count, a, b;

//     cin >> str;
//     cin >> count;

//     for (int i = 0; i < count; i++)
//     {
//         cin >> order;

//         if (order == "print")
//         {
//             cin >> a >> b;
//             cout << str.substr(a, b - a + 1) << endl;
//         }
//         else if (order == "reverse")
//         {
//             cin >> a >> b;

//             for (int j = 0; j < (b - a + 1) / 2; j++)
//             {
//                 char tempChar;
//                 tempChar = str[a + j];
//                 str[a + j] = str[b - j];
//                 str[b - j] = tempChar;
//             }
//         }
//         else if (order == "replace")
//         {
//             cin >> a >> b >> p;
//             int pi = 0;
//             for (int j = a; j <= b; j++)
//             {
//                 str[j] = p[pi];
//                 pi++;
//             }
//         }
//     }

//     return 0;
// }
