// https://atcoder.jp/contests/abc304/tasks/abc304_b
// 0606もう一度 OK

/*
6/8やり直し分
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string ns = to_string(n);

    for (int i = 3; i < ns.size(); i++)
    {
        ns[i] = '0';
    }

    cout << ns << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     string ns = to_string(n);

//     for (int i = 3; i < ns.size(); i++)
//     {
//         ns[i] = '0';
//     }

//     cout << ns << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     string s = to_string(n);

//     for (int i = 3; i < s.size(); i++)
//     {
//         s[i] = '0';
//     }
//     cout << s << endl;

//     return 0;
// }

// // 別解
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     for (int r = 1000;; r * 10)
//     {
//         if (n < r)
//         {
//             int w = r/1000;
//             cout << (n / w) * w << endl;

//             return 0;
//         }
//     }
// }

// 本番時のコード
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     long long n;

//     cin >> n;

//     if (n <= (long long)pow(10, 3) - 1)
//         cout << n << endl;
//     else if (n <= (long long)pow(10, 4) - 1)
//     {
//         cout << (n / 10) * 10 << endl;
//     }
//     else if (n <= (long long)pow(10, 5) - 1)
//     {
//         cout << (n / 100) * 100 << endl;
//     }
//     else if (n <= (long long)pow(10, 6) - 1)
//     {
//         cout << (n / 1000) * 1000 << endl;
//     }
//     else if (n <= (long long)pow(10, 7) - 1)
//     {
//         cout << (n / 10000) * 10000 << endl;
//     }
//     else if (n <= (long long)pow(10, 8) - 1)
//     {
//         cout << (n / 100000) * 100000 << endl;
//     }
//     else if (n <= (long long)pow(10, 9) - 1)
//     {
//         cout << (n / 1000000) * 1000000 << endl;
//     }

//     return 0;
// }