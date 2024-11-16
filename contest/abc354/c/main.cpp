// https://atcoder.jp/contests/abc354/tasks/abc354_c

// 解けたが、見通し悪かった

// 2024_11_16もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), c(n);
    rep(i, n)
    {
        cin >> a[i];
        cin >> c[i];
    }

    vector<int> ind(n);
    rep(i, n) ind[i] = i;

    sort(ind.begin(), ind.end(), [&](int i, int j)
         { return a[i] > a[j]; });

    vector<int> ans;
    for (int i : ind)
    {
        if (ans.size() == 0 || c[ans.back()] > c[i])
        {
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    rep(i, ans.size())
    {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using P = pair<int, int>;

// int main()
// {

//     int n;
//     cin >> n;

//     vector<P> ac(n);
//     map<P, int> ind;

//     rep(i, n)
//     {
//         cin >> ac[i].first >> ac[i].second;
//         ind[{ac[i].first, ac[i].second}] = i;
//     }

//     auto compare = [&](P a, P b)
//     {
//         if (a.first != b.first)
//         {
//             return a.first > b.first;
//         }
//         else
//         {
//             return a.second > b.second;
//         }
//     };

//     sort(ac.begin(), ac.end(), compare);

//     vector<bool> card(n, true);

//     int remove = 0;
//     int st = ac[0].first;
//     int cost = ac[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         if (st > ac[i].first)
//         {
//             if (cost < ac[i].second)
//             {
//                 remove++;
//                 int index = ind[{ac[i].first, ac[i].second}];
//                 card[index] = false;
//                 continue;
//             }
//         }
//         st = ac[i].first;
//         cost = ac[i].second;
//     }

//     cout << n - remove << endl;
//     rep(i, n)
//     {
//         if (card[i])
//             cout << i + 1 << " ";
//     }

//     return 0;
// }
