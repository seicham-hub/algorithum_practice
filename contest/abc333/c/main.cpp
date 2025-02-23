// https://atcoder.jp/contests/abc333/tasks/abc333_c

// 解けたが、時間かかりすぎ

// 2025_02_23もういちど

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;

    vector<ll> repUnit;

    for (ll i = 1; i < 1e12; i = i * 10 + 1)
        repUnit.push_back(i);

    set<ll> cand;

    rep(i, repUnit.size())
    {
        rep(j, repUnit.size())
        {
            rep(k, repUnit.size())
            {
                cand.insert(repUnit[i] + repUnit[j] + repUnit[k]);
            }
        }
    }

    vector<ll> tmp;

    for (auto c : cand)
    {
        tmp.push_back(c);
    }

    cout << tmp[n - 1] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n;
//     cin >> n;
//     n--;

//     string th = "1";
//     string tw = "1";
//     string on = "1";

//     rep(i, n)
//     {

//         if (tw.size() == on.size())
//         {
//             if (th.size() == tw.size())
//             {
//                 th += '1';
//                 tw = "1";
//                 on = "1";
//                 continue;
//             }
//             else
//             {
//                 tw += '1';
//                 on = "1";
//                 continue;
//             }
//         }
//         else
//         {
//             on += '1';
//             continue;
//         }
//     }

//     reverse(th.begin(), th.end());
//     reverse(tw.begin(), tw.end());
//     reverse(on.begin(), on.end());

//     rep(i, tw.size())
//     {
//         th[i] = '2';
//     }

//     rep(i, on.size())
//     {
//         th[i] = '3';
//     }

//     reverse(th.begin(), th.end());

//     cout << th << endl;
//     return 0;
// }