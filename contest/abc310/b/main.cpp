// https://atcoder.jp/contests/abc310/tasks/abc310_b
// 時間かかりすぎ、きれいではない
// 順序入れ替えた場合を考えるとき、２回目のforはそのまま0始まりにすればよくね？
// またはsortした後のものを考えればよくね？

// 0716もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> p(n), c(n);
    vector<multiset<int>> f(n);

    rep(i, n)
    {
        cin >> p[i] >> c[i];
        rep(j, c[i])
        {
            int temp;
            cin >> temp;
            f[i].insert(temp);
        }
    }

    bool ans = false;
    rep(i, n)
    {

        rep(j, n)
        {
            bool haveAllFunc = true;

            for (auto x : f[i])
            {
                if (f[j].find(x) == f[j].end())
                {
                    haveAllFunc = false;
                }
            }

            ans = ans || p[i] >= p[j] && haveAllFunc && (p[i] > p[j] || f[j].size() > f[i].size());
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}

/*
解答コード
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N, M;
//     cin >> N >> M;

//     vector<int> P(N), C(N);
//     vector<multiset<int>> F(N);

//     for (int i = 0; i < N; ++i)
//     {
//         cin >> P[i] >> C[i];

//         for (int j = 0; j < C[i]; ++j)
//         {
//             int temp;
//             cin >> temp;
//             F[i].insert(temp);
//         }
//     }

//     bool ans = false;
//     for (int i = 0; i < N; ++i)
//     {
//         for (int j = 0; j < N; ++j)
//         {
//             bool isSuperset = true;
//             for (const auto &item : F[i])
//             {
//                 if (F[j].find(item) == F[j].end())
//                 {
//                     isSuperset = false;
//                     break;
//                 }
//             }
//             ans = ans || (P[i] >= P[j] && isSuperset && (P[i] > P[j] || F[j].size() > F[i].size()));
//         }
//     }

//     cout << (ans ? "Yes" : "No") << endl;
//     return 0;
// }

/*
自分の解答
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// bool checkUpgrade()
// {
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     vector<int> p(n);
//     vector<int> c(n);
//     vector<vector<int>> f(n, vector<int>(m));

//     rep(i, n)
//     {
//         cin >> p[i];
//         cin >> c[i];
//         rep(j, c[i]) cin >> f[i][j];
//     }

//     vector<map<int, bool>> mp(n);
//     rep(i, n)
//     {
//         rep(j, c[i])
//         {
//             mp[i][f[i][j]] = true;
//         }
//     }

//     rep(i, n)
//     {

//         for (int j = i + 1; j < n; j++)
//         {
//             // iが下位の時
//             bool oki = true;
//             for (auto [x, _] : mp[i])
//             {
//                 if (mp[i][x] && mp[j][x] == false)
//                 {
//                     oki = false;
//                     break;
//                 }
//             }

//             if (p[i] < p[j])
//                 oki = false;

//             if (p[i] == p[j])
//             {
//                 bool tmpOK = false;
//                 for (auto [y, v] : mp[j])
//                 {

//                     if (v == true && mp[i][y] == false)
//                     {
//                         tmpOK = true;
//                     }
//                 }

//                 if (tmpOK == false)
//                     oki = false;
//             }

//             // jが下位の時
//             bool okj = true;
//             for (auto [x, _] : mp[j])
//             {
//                 if (mp[j][x] && mp[i][x] == false)
//                 {
//                     okj = false;
//                     break;
//                 }
//             }
//             if (p[j] < p[i])
//                 okj = false;

//             if (p[i] == p[j])
//             {
//                 bool tmpOK = false;
//                 for (auto [y, v] : mp[i])
//                 {

//                     if (v == true && mp[j][y] == false)
//                     {
//                         tmpOK = true;
//                     }
//                 }

//                 if (tmpOK == false)
//                     okj = false;
//             }

//             if (oki || okj)
//             {
//                 cout << "Yes" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "No" << endl;

//     return 0;
// }