// https://atcoder.jp/contests/abc054/tasks/abc054_c

// 0421もう一度
// 0424もう一度

/*
0424解きなおし
*/

#include <bits/stdc++.h>
using namespace std;
bool g[8][8] = {};

int main()
{
    int n, m, ans = 0;

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int now, next;
        cin >> now >> next;
        g[now][next] = true;
        g[next][now] = true;
    }

    vector<int> indices(n);
    iota(indices.begin(), indices.end(), 1);

    do
    {
        if (indices[0] != 1)
            break;

        bool ok = true;
        for (int i = 0; i < n - 1; i++)
        {
            int now = indices[i], next = indices[i + 1];
            if (!g[now][next])
            {
                ok = false;
                break;
            }
        }

        if (ok)
            ans++;

    } while (next_permutation(indices.begin(), indices.end()));

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int g[8][8];

// int main()
// {

//     int n, m, ans = 0;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int v, u;
//         cin >> v >> u;
//         g[v][u] = true;
//         g[u][v] = true;
//     }

//     vector<int> p(n);
//     iota(p.begin(), p.end(), 1);

//     do
//     {
//         if (p[0] != 1)
//             continue;
//         bool ok = true;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = p[i];
//             int next = p[i + 1];

//             if (!g[now][next])
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//             ans++;

//     } while (next_permutation(p.begin(), p.end()));

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, m, a[30], b[30], ans = 0;
//     cin >> n >> m;

//     for (int i = 0; i < m; i++)
//     {
//         cin >> a[i] >> b[i];
//     }

//     vector<int> indices(n);
//     iota(indices.begin(), indices.end(), 1);

//     do
//     {
//         if (indices[0] != 1)
//             break;

//         int cnt = 0;
//         for (int i = 0; i < n - 1; i++)
//         {
//             int now = indices[i];
//             int next = indices[i + 1];

//             for (int j = 0; j < m; j++)
//             {
//                 if ((a[j] == now && b[j] == next) || (b[j] == now && a[j] == next))
//                 {
//                     cnt++;
//                     break;
//                 }
//             }
//         }
//         if (cnt == n - 1)
//             ans++;

//     } while (next_permutation(indices.begin(), indices.end()));

//     cout << ans << endl;

//     return 0;
// }
