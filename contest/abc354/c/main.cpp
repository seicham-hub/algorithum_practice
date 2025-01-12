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
        cin >> a[i] >> c[i];
    }

    vector<int> indices;
    rep(i, n) indices.push_back(i);

    sort(indices.begin(), indices.end(), [&](int x, int y)
         { return a[x] > a[y]; });

    vector<int> ans;
    ans.push_back(indices[0]);
    for (int i = 1; i < n; i++)
    {
        int now = indices[i];
        if (c[ans.back()] > c[now])
            ans.push_back(now);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto ansi : ans)
        cout << ansi + 1 << " ";
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
//     vector<int> a(n), c(n);

//     rep(i, n)
//     {
//         cin >> a[i] >> c[i];
//     }

//     vector<int> indices;
//     rep(i, n) indices.push_back(i);

//     sort(indices.begin(), indices.end(), [&](int i, int j)
//          { return a[i] > a[j]; });

//     vector<int> ans;

//     for (int ind : indices)
//     {
//         if (!ans.size() || c[ans.back() - 1] > c[ind])
//             ans.push_back(ind + 1);
//     }

//     sort(ans.begin(), ans.end());

//     cout << ans.size() << endl;
//     for (int ansi : ans)
//         cout << ansi << " ";

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using P = pair<int, int>;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<P> ac(n);

//     rep(i, n) cin >> ac[i].first >> ac[i].second;

//     vector<int> indices;
//     rep(i, n) indices.push_back(i);

//     sort(indices.begin(), indices.end(), [&](int a, int b)
//          { return ac[a].first > ac[b].first; });

//     vector<int> ans;
//     int before = 1e9;
//     rep(i, n)
//     {
//         int now = indices[i];
//         if (ac[now].second <= before)
//         {
//             ans.push_back(now + 1);
//             before = ac[now].second;
//         }
//     }

//     sort(ans.begin(), ans.end());

//     cout << ans.size() << endl;
//     rep(i, ans.size())
//     {
//         cout << ans[i] << " ";
//     }

//     cout << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using P = pair<int, int>;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<int> a(n), c(n);
//     rep(i, n)
//     {
//         cin >> a[i];
//         cin >> c[i];
//     }

//     vector<int> ind(n);
//     rep(i, n) ind[i] = i;

//     sort(ind.begin(), ind.end(), [&](int i, int j)
//          { return a[i] > a[j]; });

//     vector<int> ans;
//     for (int i : ind)
//     {
//         if (ans.size() == 0 || c[ans.back()] > c[i])
//         {
//             ans.push_back(i);
//         }
//     }

//     sort(ans.begin(), ans.end());

//     cout << ans.size() << endl;
//     rep(i, ans.size())
//     {
//         cout << ans[i] + 1 << " ";
//     }
//     cout << endl;

//     return 0;
// }

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
