// https://atcoder.jp/contests/abc150/tasks/abc150_c
// 0421もう一度 時間かかりすぎ

/*
0424解きなおし
*/
#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, a = 0, b = 0;
    cin >> n;

    vector<int> p(n), q(n);

    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> q[i];

    do
    {
        a++;
    } while (next_permutation(p.begin(), p.end()));
    do
    {
        b++;
    } while (next_permutation(q.begin(), q.end()));

    cout << abs(a - b) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {
//     int N;
//     cin >> N;
//     vector<int> P(N), Q(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> P[i];
//     }
//     for (int i = 0; i < N; i++)
//     {
//         cin >> Q[i];
//     }

//     int a = 0, b = 0;
//     while (next_permutation(P.begin(), P.end()))
//     {
//         ++a;
//     }
//     while (next_permutation(Q.begin(), Q.end()))
//     {
//         ++b;
//     }
//     cout << abs(a - b) << endl;
//     return 0;
// }

// 自分が書いたコード

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, p[10], q[10], a, b;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> p[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         cin >> q[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 1);

//     int cnt = 0;
//     do
//     {
//         cnt++;
//         int pCnt = 0, qCnt = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (p[i] == indices[i])
//                 pCnt++;
//             if (q[i] == indices[i])
//                 qCnt++;

//             if (pCnt < i + 1 && qCnt < i + 1)
//                 break;
//         }

//         if (pCnt == n)
//             a = cnt;
//         if (qCnt == n)
//             b = cnt;

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << abs(a - b) << endl;

//     return 0;
// }
