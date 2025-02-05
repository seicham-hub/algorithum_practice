// https://atcoder.jp/contests/abc347/tasks/abc347_c

// 一つだけWA なぜかわからなかった...
// 2025_02_06もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int w = a + b;
    vector<int> d(2 * n);

    rep(i, n)
    {
        int di;
        cin >> di;
        di--;

        int diff = di % w;
        d[i] = diff;
        d[i + n] = diff + w;
    }

    rep(i, 2 * n - 1)
    {
        if (d[i + 1] - d[i] >= b + 1)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {
//     int n, a, b;
//     cin >> n >> a >> b;

//     ll divi = a + b;
//     vector<ll> d(n);

//     rep(i, n)
//     {
//         cin >> d[i];
//         d[i]--;
//     }

//     rep(i, n)
//     {
//         d[i] %= (a + b);
//     }

//     ll mini = 1e18;
//     rep(i, n) mini = min(mini, d[i]);

//     rep(i, n) d[i] -= mini;

//     rep(i, n)
//     {
//         if (d[i] >= a)
//         {
//             cout << "No" << endl;
//             return 0;
//         }
//     }

//     cout << "Yes" << endl;

//     return 0;
// }