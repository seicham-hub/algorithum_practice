// https://atcoder.jp/contests/abc304/tasks/abc304_a

/*
6/8やり直し分
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) \
    for (int i = 0; i < (n); ++i)

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    vector<long long> a(n);

    rep(i, n) cin >> s[i] >> a[i];

    int si = 0;
    rep(i, n) if (a[si] > a[i]) si = i;

    for (int i = si; i < si + n; i++)
    {
        cout << s[(i + n) % n] << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) \
//     for (int i = 0; i < (n); ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<string> s(n);
//     vector<long long> a(n);

//     rep(i, n) cin >> s[i] >> a[i];

//     long long m = 1e9 + 1;
//     int si = 0;
//     rep(i, n) if (m > a[i])
//     {
//         m = a[i];
//         si = i;
//     }

//     rep(i, n) cout << s[(si + i) % n] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) \
//     for (int i = 0; i < (n); ++i)

// int main()
// {

//     int n;
//     cin >> n;
//     vector<string> s(n);
//     vector<int> a(n);

//     rep(i, n) cin >> s[i] >> a[i];
//     // int min_a = 1e9;
//     // rep(i, n) min_a = min(min_a, a[i]);
//     int si = 0;
//     rep(i, n) if (a[i] < a[si]) si = i;

//     rep(i, n)
//     {
//         int ni = (si + i) % n;
//         cout << s[ni] << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// long long a[101];
// string s[101];

// int ind = 0;

// int main()
// {

//     cin >> n;

//     long long min = 500;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> s[i] >> a[i];
//         if (a[i] < min || i == 0)
//         {
//             min = a[i];
//             ind = i;
//         }
//     }

//     for (int i = ind; i < ind + n; i++)
//     {
//         cout << s[i % n] << endl;
//     }

//     return 0;
// }
