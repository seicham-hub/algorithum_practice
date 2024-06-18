// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int count_bit(int &msk, int &n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (msk & (1 << i))
            result++;
    }

    return result;
}

int main()
{
    int n, k;
    ll ans = 1e18;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int msk = 1; msk < (1 << n); msk++)
    {
        if (count_bit(msk, n) != k)
            continue;

        int before = a[0];
        ll cost = 0;
        for (int i = 1; i < n; i++)
        {
            if (msk & (1 << i))
            {
                if (a[i] > before)
                    before = a[i];
                else
                {
                    int diff = abs(before - a[i]) + 1;
                    cost += diff;
                    before = a[i] + diff;
                }
            }
            else
                before = max(before, a[i]);
        }

        ans = min(ans, cost);
    }

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int count_bit(int &msk, int &n)
// {
//     int result = 0;
//     for (int i = 0; i < n; i++)
//         if (msk & (1 << i))
//             result++;

//     return result;
// }
// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     ll ans = -1;

//     vector<ll> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     for (int msk = 1; msk < (1 << n); msk++)
//     {

//         int count = count_bit(msk, n);
//         if (count != k)
//             continue;

//         ll before = a[0];
//         ll cost = 0;
//         for (int i = 1; i < n; i++)
//         {
//             if (msk & (1 << i))
//             {

//                 if (before - a[i] >= 0)
//                 {

//                     cost += before - a[i] + 1;
//                     before = before + 1;
//                 }
//                 else
//                     before = a[i];
//             }
//             else
//             {
//                 before = max(before, a[i]);
//             }
//         }

//         if (ans == -1)
//             ans = cost;
//         else
//             ans = min(ans, cost);
//     }

//     std::cout << ans << endl;

//     return 0;
// }