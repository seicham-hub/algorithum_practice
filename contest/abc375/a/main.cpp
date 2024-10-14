#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    rep(i, n)
    {
        if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#')
            ans++;
    }

    cout << ans;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     if (n < 3)
//     {
//         cout << 0 << endl;
//         return 0;
//     }

//     int ans = 0;
//     rep(i, n - 2)
//     {
//         if (s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#')
//             ans++;
//     }

//     cout << ans << endl;

//     return 0;
// }