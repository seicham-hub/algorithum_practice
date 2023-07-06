// https://atcoder.jp/contests/abc308/tasks/abc308_c
// 0704もう一度 ok

/*
 0706やり直し分
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> ab(n);

    rep(i, n)
    {
        long long a, b;
        cin >> a >> b;

        ab[i] = {a, a + b};
    }

    vector<int> per(n);
    iota(per.begin(), per.end(), 0);

    auto compare = [&](int i, int j)
    {
        auto [ai, aibi] = ab[i];
        auto [aj, ajbj] = ab[j];

        if (ai * ajbj == aj * aibi)
        {
            return i < j;
        }

        return ai * ajbj > aj * aibi;
    };

    sort(per.begin(), per.end(), compare);

    rep(i, n)
    {
        cout << per[i] + 1 << " \n"[i == n - 1];
    }

    return 0;
}

// 正解コード
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;

//     vector<pair<int, int>> ab;
//     rep(i, n)
//     {
//         int a, b;
//         cin >> a >> b;
//         ab.emplace_back(a, a + b);
//     }
//     vector<int> p(n);
//     iota(p.begin(), p.end(), 0);

//     auto f = [&](int i, int j)
//     {
//         auto [ai, aj] = ab[i];
//         auto [bi, bj] = ab[j];

//         if ((long long)ai * bj == (long long)bi * aj)
//         {
//             return i < j;
//         }
//         else
//         {
//             return (long long)ai * bj > (long long)bi * aj;
//         }
//     };

//     sort(p.begin(), p.end(), f);

//     rep(i, n)
//     {
//         cout << p[i] + 1 << " \n"[i == n - 1];
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// bool desc_asc(pair<double, int> &left, pair<double, int> &right)
// {
//     if (left.first == right.first)
//     {
//         return left.second < right.second;
//     }
//     else
//     {
//         return left.first < right.first;
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long> a(n), b(n);

//     vector<pair<double, int>> ans(n);

//     rep(i, n)
//     {
//         cin >> a[i] >> b[i];

//         double p = (double)(a[i] + b[i]) / (double)a[i];

//         ans[i] = {p, i};
//     }

//     sort(ans.begin(), ans.end(), desc_asc);

//     rep(i, n)
//     {
//         if (i == n - 1)
//         {
//             cout << ans[i].second + 1 << endl;
//             continue;
//         }
//         cout << ans[i].second + 1 << " ";
//     }

//     return 0;
// }