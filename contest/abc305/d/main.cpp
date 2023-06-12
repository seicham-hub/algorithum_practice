// https://atcoder.jp/contests/abc305/tasks/abc305_d

// 0612もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    unsigned n;
    cin >> n;

    vector<unsigned> a(n), fa(n);

    for (auto &&ai : a)
    {
        cin >> ai;
    }

    // fa[i] := a[i]分後までに何分寝たか
    for (unsigned i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            fa[i] = fa[i - 1] + a[i] - a[i - 1];
        else
        {
            fa[i] = fa[i - 1];
        }
    }

    unsigned q;
    cin >> q;

    // f(x) := x分までに何分寝たか
    auto f{[&a, &fa](auto x) -> unsigned
           {
               const auto j = upper_bound(begin(a) + 1, end(a), x) - begin(a) - 1;
               return fa[j] + (fa[j + 1] - fa[j]) / (a[j + 1] - a[j]) * (x - A[j]);
           }};

    for (unsigned i = 0; i < q; i++)
    {
        unsigned l, r;
        cin >> l >> r;
        cout << f(r) - f(l) << endl;
    }

    return 0;
}

// 本番のコード

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     rep(i, n) cin >> a[i];
//     int q;
//     cin >> q;
//     vector<long long> l(q), r(q);
//     rep(i, q)
//     {
//         cin >> l[i] >> r[i];
//     }

//     vector<long long> ans;

//     rep(i, q)
//     {
//         int sind = lower_bound(a.begin(), a.end(), l[i]) - a.begin() - 1;

//         long long tmpa = 0;

//         long long start = l[i];
//         while (true)
//         {

//             if (r[i] <= a[sind + 1])
//             {

//                 if (sind % 2 == 1)
//                 {
//                     tmpa += r[i] - a[sind];
//                 }

//                 break;
//             }

//             if (sind % 2 == 1)
//             {
//                 tmpa += a[sind + 1] - start;
//             }

//             start = a[sind + 1];
//             sind++;
//         }

//         ans.push_back(tmpa);
//     }

//     rep(i, ans.size())
//     {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }