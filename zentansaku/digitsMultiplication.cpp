// https://atcoder.jp/contests/abc057/tasks/abc057_c
// 2023_0414もう一度

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n;

    cin >> n;

    int min_f = 20;

    for (ll a = 1; a * a <= n; a++)
    {
        if (n % a == 0)
        {
            ll b = n / a;

            int digit_a = to_string(a).size();
            int digit_b = to_string(b).size();
            int tmp_f = digit_a > digit_b ? digit_a : digit_b;

            min_f = min(min_f, tmp_f);
        }
    }

    cout << min_f << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     long long int n, a, b;

//     int minFab = 30;

//     cin >> n;

//     for (long long int i = 1; i * i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             a = i;
//             b = n / a;

//             string aStr = to_string(a);
//             string bStr = to_string(b);

//             int tmpMax = max(aStr.size(), bStr.size());

//             minFab = min(minFab, tmpMax);
//         }
//         else
//         {
//             continue;
//         }
//     }
//     cout << minFab << endl;
//     return 0;
// }

// 最初に自分が書いたコード
// #include <bits/stdc++.h>
// using namespace std;

// int countKeta(long long int num)
// {

//     string numStr = to_string(num);
//     return numStr.size();
// }

// int main()
// {
//     long long int n;
//     int minKeta = 20;
//     cin >> n;

//     for (long long int i = 1; i * i <= n; i++)
//     {
//         int a = i;
//         if (n % a != 0)
//             continue;
//         int b = n / a;
//         int curKeta = max(countKeta(a), countKeta(b));

//         minKeta = min(curKeta, minKeta);
//     }

//     cout << minKeta << endl;

//     return 0;
// }
