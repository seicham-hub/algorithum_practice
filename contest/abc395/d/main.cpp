// https://atcoder.jp/contests/abc395/tasks/abc395_d

// わからなかった...

// 2025_03_05もう一度
// 2025_04_20もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> p2b(n);
    vector<int> b2h(n);
    vector<int> h2b(n);

    rep(i, n) p2b[i] = i;
    rep(i, n) b2h[i] = i;
    rep(i, n) h2b[i] = i;

    rep(qi, q)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            p2b[a] = h2b[b];
        }
        else if (type == 2)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            //
            swap(h2b[a], h2b[b]);
            b2h[h2b[a]] = a;
            b2h[h2b[b]] = b;
        }
        else
        {
            int a;
            cin >> a;
            a--;
            int ans = b2h[p2b[a]];
            cout << ans + 1 << '\n';
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     int n, q;
//     cin >> n >> q;

//     vector<set<int>> nest(n);
//     vector<int> pigeon(n);

//     rep(i, n) nest[i].insert(i);
//     rep(i, n) pigeon[i] = i;

//     rep(i, q)
//     {

//         int o, a, b;
//         cin >> o;

//         if (o == 1)
//         {
//             cin >> a >> b;
//             a--, b--;
//             int nestInd = pigeon[a];

//             // 既存の巣から削除
//             nest[nestInd].erase(a);

//             // 新しい巣へ
//             nest[b].insert(a);
//             pigeon[a] = b;
//         }

//         if (o == 2)
//         {
//             cin >> a >> b;
//             a--, b--;
//             swap(nest[a], nest[b]);
//             for (auto p : nest[a])
//             {
//                 pigeon[p] = a;
//             }
//             for (auto p : nest[b])
//             {
//                 pigeon[p] = b;
//             }
//         }

//         if (o == 3)
//         {
//             cin >> a;
//             a--;
//             cout << pigeon[a] + 1 << endl;
//         }
//     }

//     return 0;
// }