// https://atcoder.jp/contests/abc312/tasks/abc312_c
// 最大のxを考えるとき、条件を満たす数式がxによって単調増加、単調減少なら二分探索か
// 解けなかった... なぜ下記で間違ってるのか分からない

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    return 0;
}

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