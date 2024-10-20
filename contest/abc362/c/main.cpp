// https://atcoder.jp/contests/abc362/tasks/abc362_c

// 分からなかった...
// 2024_10_19もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> l(n), r(n);

    rep(i, n)
    {
        cin >> l[i] >> r[i];
    }

    ll suml = 0, sumr = 0;

    rep(i, n)
    {
        suml += l[i];
        sumr += r[i];
    }

    if (suml > 0 || 0 > sumr)
    {
        cout << "No" << endl;
        return 0;
    }

    ll remin = -suml;
    vector<ll> ans = l;

    rep(i, n)
    {
        ll canAdd = r[i] - l[i];

        if (remin > canAdd)
        {
            ans[i] = r[i];
            remin -= canAdd;
        }
        else
        {
            ans[i] += remin;
            break;
        }
    }

    cout << "Yes" << endl;
    rep(i, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> l(n), r(n);
//     rep(i, n) cin >> l[i] >> r[i];

//     ll sumL = 0, sumR = 0;

//     rep(i, n)
//     {
//         sumL += l[i];
//         sumR += r[i];
//     }

//     if (sumL > 0 || 0 > sumR)
//     {
//         cout << "No" << endl;
//         return 0;
//     }

//     vector<int> ans = l;
//     ll rem = -sumL;

//     rep(i, n)
//     {

//         ll canAdd = r[i] - l[i];
//         if (rem > canAdd)
//         {
//             ans[i] = r[i];
//             rem -= canAdd;
//         }
//         else
//         {
//             ans[i] += rem;
//             break;
//         }
//     }

//     cout << "Yes" << endl;
//     rep(i, n) cout << ans[i] << " ";
//     cout << endl;

//     return 0;
// }