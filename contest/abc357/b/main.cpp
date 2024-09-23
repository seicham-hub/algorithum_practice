// https://atcoder.jp/contests/abc357/tasks/abc357_b
// 大文字、小文字の変換
// 2024_09_14もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    int lower = 0, upper = 0;

    for (char &c : s)
    {
        if (islower(c))
            lower++;
        else
            upper++;
    }

    if (lower < upper)
    {
        for (char &c : s)
        {
            c = toupper(c);
        }
    }
    else
    {
        for (char &c : s)
        {
            c = tolower(c);
        }
    }
    cout << s << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     int lower = 0, upper = 0;

//     for (char c : s)
//     {
//         if (islower(c))
//             lower++;
//         else
//             upper++;
//     }

//     if (lower < upper)
//     {
//         for (char &c : s)
//             c = toupper(c);
//     }
//     else
//     {
//         for (char &c : s)
//             c = tolower(c);
//     }

//     cout << s << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     string s;
//     cin >> s;

//     int lower = 0, upper = 0;

//     for (char si : s)
//     {
//         if (islower(si))
//             lower++;
//         else
//             upper++;
//     }

//     if (lower < upper)
//     {
//         for (char &si : s)
//         {
//             if (islower(si))
//                 si = toupper(si);
//         }
//     }
//     else
//     {
//         for (char &si : s)
//         {
//             if (isupper(si))
//                 si = tolower(si);
//         }
//     }

//     cout << s << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     string s;
//     cin >> s;

//     int lower = 0, upper = 0;

//     for (char si : s)
//     {
//         if ('a' <= si && si <= 'z')
//             lower++;
//         if ('A' <= si && si <= 'Z')
//             upper++;
//     }

//     if (lower > upper)
//         rep(i, s.size())
//         {
//             if ('A' <= s[i] && s[i] <= 'Z')
//                 s[i] += 'a' - 'A';
//         }
//     else
//         rep(i, s.size())
//         {
//             if ('a' <= s[i] && s[i] <= 'z')
//                 s[i] += 'A' - 'a';
//         }

//     cout << s << endl;

//     return 0;
// }