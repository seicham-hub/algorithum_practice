// https://atcoder.jp/contests/abc304/tasks/abc304_a

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) \
    for (int i = 0; i < (n); ++i)

int main()
{

    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> a(n);

    rep(i, n) cin >> s[i] >> a[i];
    // int min_a = 1e9;
    // rep(i, n) min_a = min(min_a, a[i]);
    int si = 0;
    rep(i, n) if (a[i] < a[si]) si = i;

    rep(i, n)
    {
        int ni = (si + i) % n;
        cout << s[ni] << endl;
    }

    return 0;
}

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
