// https://atcoder.jp/contests/abc302/tasks/abc302_d
// 0521もう一度 ok

/*
0526やり直し分
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, d;

    cin >> n >> m >> d;

    vector<long long> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (true)
    {
        if (b.size() == 0 || a.size() == 0)
            break;
        long long aLast = a.back();
        long long bLast = b.back();
        if (abs(aLast - bLast) <= d)
        {
            cout << aLast + bLast << endl;
            return 0;
        }

        if (aLast > bLast)
            a.pop_back();
        else
            b.pop_back();
    }

    cout << -1 << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long n, m, d;

//     cin >> n >> m >> d;

//     vector<long long> a(n), b(m);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin >> b[i];
//     }

//     while (true)
//     {
//         abs(a.back() - b.back());
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long n, m, d, ans = -1;

//     cin >> n >> m >> d;

//     vector<long long> a(n), b(m);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         cin >> b[i];
//     }

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     while (a.size() > 0 && b.size() > 0)
//     {

//         long long x = a.back();
//         long long y = b.back();

//         if (abs(x - y) <= d)
//         {
//             cout << x + y << endl;
//             return 0;
//         }

//         if (x > y)
//             a.pop_back();
//         else
//             b.pop_back();
//     }

//     cout << ans << endl;
//     return 0;
// }