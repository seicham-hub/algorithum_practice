// 0614もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    char p, q;
    cin >> p >> q;

    int e[] = {0, 3, 4, 8, 9, 14, 23};

    cout << abs(e[p - 'A'] - e[q - 'A']) << endl;

    return 0;
}

// 本番のコード

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int dx[6] = {3, 1, 4, 1, 5, 9}, tmp_ind = 0, ans = 0;

//     map<pair<int, int>, int> dist;

//     for (int i = 'A'; i < 'G'; i++)
//     {
//         dist[{i, i + 1}] = dx[tmp_ind];
//         tmp_ind++;
//     }

//     char p, q;
//     cin >> p >> q;

//     char m, M;
//     if (p > q)
//     {
//         m = q;
//         M = p;
//     }
//     else
//     {
//         m = p;
//         M = q;
//     }

//     for (int i = m; i < M; i++)
//     {
//         ans += dist[{i, i + 1}];
//     }

//     cout << ans << endl;

//     return 0;
// }