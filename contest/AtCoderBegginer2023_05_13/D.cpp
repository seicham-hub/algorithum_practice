// https://atcoder.jp/contests/abc301/tasks/abc301_d
// bit演算の場合は& | 一つでよい
// 0517もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long long n, ss = 0;

    cin >> s >> n;

    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            ss = ss | (1LL << i);
    }

    if (ss > n)
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '?' && (ss || 1LL << i) <= n)
        {
            ss = ss | 1LL << i;
        }
    }

    cout << ss << endl;

    return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <string>

// using namespace std;

// int main()
// {
//     string S;
//     long long N;
//     cin >> S >> N;

//     reverse(S.begin(), S.end());
//     long long s = 0;
//     for (int i = 0; i < S.size(); i++)
//     {
//         if (S[i] == '1')
//         {
//             s |= 1LL << i;
//         }
//     }

//     if (s > N)
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         for (int i = S.size() - 1; i >= 0; i--)
//         {
//             if (S[i] == '?' && (s | (1LL << i)) <= N)
//             {
//                 s |= 1LL << i;
//             }
//         }
//         cout << s << endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long int n;
//     long long init = 0;
//     string s;

//     cin >> s >> n;

//     vector<int> canChange;

//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '?')
//             canChange.push_back(i);
//         if (s[i] == '1')
//         {
//             init += pow(2, s.size() - 1 - i) * 1;
//         }
//     }

//     if (init > n)
//     {
//         cout << "-1" << endl;
//         return 0;
//     }

//     // for (int c : canChange)
//     // {
//     //     long long in = init;
//     //     init += (long long)pow(2, s.size() - 1 - c) * 1;
//     //     if (init <= n)
//     //     {
//     //         continue;
//     //     }
//     //     else
//     //     {
//     //         init = in;
//     //     }
//     // }

//     for (int i = canChange.size() - 1; i >= 0; --i)
//     {
//         long long in = init;
//         init += (long long)pow(2, s.size() - 1 - canChange[i]);
//         if (init <= n)
//         {
//             continue;
//         }
//         else
//         {
//             init = in;
//         }
//     }

//     cout << init << endl;

//     return 0;
// }
