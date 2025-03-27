// https://atcoder.jp/contests/abc312/tasks/abc312_c
// 最大のxを考えるとき、条件を満たす数式がxによって単調増加、単調減少なら二分探索か
// 解けなかった... なぜ下記で間違ってるのか分からない →間隔に頼りすぎた

// 0730もう一度
// 0801もう一度 ok
// 2025_03_19もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll left = 0;
    ll right = 1e9 + 1;

    while (abs(left - right) > 1)
    {

        auto check = [&](ll x) -> bool
        {
            int cntA = upper_bound(a.begin(), a.end(), x) - a.begin();

            int indB = lower_bound(b.begin(), b.end(), x) - b.begin();
            int cntB = m - indB;

            return cntA >= cntB;
        };

        ll mid = (left + right) / 2;
        if (check(mid))
            right = mid;
        else
            left = mid;
    }

    cout << right << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n), b(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     auto check = [&](int x) -> bool
//     {
//         int seller = upper_bound(a.begin(), a.end(), x) - a.begin();
//         int buyer = m - (lower_bound(b.begin(), b.end(), x) - b.begin());

//         return seller >= buyer;
//     };

//     int left = 0;
//     int right = 1e9 + 10;

//     while (abs(left - right) != 1)
//     {

//         int mid = (left + right) / 2;

//         if (check(mid))
//             right = mid;
//         else
//             left = mid;
//     }

//     cout << right << endl;

//     return 0;
// }

// なぜ以下で解けないのかわからない→わかった
// aの要素しか試していないが、買う人の数が変化するのはb[i]+1の時もあるので、これも考慮に入れなければならない

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> a(n), b(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     rep(i, n)
//     {
//         auto it = lower_bound(b.begin(), b.end(), a[i]);
//         if (it == b.end())
//             continue;
//         int ind = it - b.begin();

//         if (i + 1 >= m - ind)
//         {
//             cout << a[i] << endl;
//             return 0;
//         }
//     }

//     // cout << b.back() + 1 << endl;

//     return 0;
// }

// /*
// 8/2やり直し分
// */

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, m;
// vector<int> a, b;

// bool check(int mid)
// {
//     auto buyI = upper_bound(a.begin(), a.end(), mid);
//     int buyP = buyI - a.begin();

//     auto selI = lower_bound(b.begin(), b.end(), mid);
//     int selP = m - (selI - b.begin());

//     return (buyP - selP) >= 0;
// }

// int main()
// {

//     cin >> n >> m;

//     a.resize(n);
//     b.resize(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     int left = 0;
//     int right = 1e9 + 1;

//     while (abs(right - left) > 1)
//     {
//         int mid = (right + left) / 2;

//         if (check(mid))
//             right = mid;
//         else
//             left = mid;
//     }

//     cout << right << endl;

//     return 0;
// }

/*
7/30やり直し分
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, m;
// vector<int> a, b;

// bool check(int mid)
// {
//     auto sIt = upper_bound(a.begin(), a.end(), mid);
//     int sellP = sIt - a.begin();

//     auto bIt = lower_bound(b.begin(), b.end(), mid);
//     int buyP = m - (bIt - b.begin());

//     return sellP >= buyP;
// }

// int main()
// {

//     cin >> n >> m;

//     a.resize(n);
//     b.resize(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     int left = 0;
//     int right = 1e9 + 1;

//     while (abs(right - left) > 1)
//     {
//         int mid = (left + right) / 2;
//         if (check(mid))
//             right = mid;
//         else
//             left = mid;
//     }

//     cout << right << endl;

//     return 0;
// }

/*
解答のコード
*/
// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, m, ans = 0;
// vector<int> a, b;

// bool check(int mid)
// {

//     auto selIt = upper_bound(a.begin(), a.end(), mid);
//     int selNum = selIt - a.begin();

//     auto buyIt = lower_bound(b.begin(), b.end(), mid);
//     int buyNum = m - (buyIt - b.begin());

//     return (selNum - buyNum >= 0);
// }

// int main()
// {

//     cin >> n >> m;

//     a.resize(n);
//     b.resize(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());

//     int left = -1;
//     int right = 1e9 + 1;

//     while (abs(right - left > 1))
//     {
//         int mid = (right + left) / 2;

//         if (check(mid))
//             right = mid;
//         else
//             left = mid;
//     }

//     cout << right << endl;
//     return 0;
// }

/*
本番のコード
Aのi番目とBのi番目、i+1番目を考えた
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// bool desc(int a, int b)
// {
//     return a > b;
// }

// int main()
// {
//     int n, m, ans = 0;
//     cin >> n >> m;

//     vector<int> a(n), b(m);

//     rep(i, n) cin >> a[i];
//     rep(i, m) cin >> b[i];

//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end(), desc);

//     int loopm = min(n, m);

//     rep(i, loopm)
//     {
//         int nowp = a[i];

//         if (b[i] >= nowp)

//             if (i == m - 1)
//             {
//                 ans = nowp;
//             }
//             else if (b[i + 1] < nowp)
//             {
//                 ans = nowp;
//             }
//     }

//     if (ans == 0)
//         cout << b[0] + 1 << endl;
//     else
//         cout << ans << endl;

//     return 0;
// }