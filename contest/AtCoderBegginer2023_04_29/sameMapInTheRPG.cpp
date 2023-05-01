// 0428もう一度
// 0501もう一度
// https://atcoder.jp/contests/abc300/tasks/abc300_b

// 各値を1ずつシフトするという操作を銅表現すれば良いのか分からず、時間がかかった。
// 移動距離で引いた数に対して余りを考えるか(必ず元の数を足してあげる必要がある）、swapで入れ替えるかすればよい。

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, a[31][31], b[31][31];
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            bool ok = true;
            for (int k = 0; k < h; k++)
            {
                for (int l = 0; l < w; l++)
                {
                    if (a[(k + i) % h][(l + j) % w] != b[k][l])
                        ok = false;
                }
            }

            if (ok)
            {
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int h, w;
//     cin >> h >> w;
//     vector<string> A(h), B(h);
//     for (auto &x : A)
//         cin >> x;
//     for (auto &x : B)
//         cin >> x;

//     for (int s = 0; s < h; s++)
//     {
//         for (int t = 0; t < w; t++)
//         {

//             int ok = 1;
//             for (int i = 0; i < h; i++)
//             {
//                 for (int j = 0; j < w; j++)
//                 {
//                     if (A[(i - s + h) % h][(j - t + w) % w] != B[i][j])
//                         ok = 0;
//                 }
//             }

//             if (ok)
//             {
//                 cout << "Yes" << endl;
//                 exit(0);
//             }
//         }
//     }

//     cout << "No" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int h, w;
//     bool ans = false;
//     char a[31][31], b[31][31];

//     cin >> h >> w;

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cin >> b[i][j];
//         }
//     }

//     for (int i = 0; i <= h; i++)
//     {

//         for (int k = 0; k < h - 1; k++)
//         {
//             swap(a[k], a[k + 1]);
//         }

//         int cnt = 0;
//         while (cnt < w + 1)
//         {
//             cnt++;
//             for (int j = 0; j < h; j++)
//             {
//                 for (int jn = 0; jn < w - 1; jn++)
//                 {
//                     swap(a[j][jn], a[j][jn + 1]);
//                 }
//             }
//             bool ok = true;
//             for (int l = 0; l < h; l++)
//             {
//                 if (!ok)
//                     break;
//                 for (int m = 0; m < w; m++)
//                 {
//                     if (a[l][m] != b[l][m])
//                     {
//                         ok = false;
//                         break;
//                     }
//                 }
//             }

//             if (ok)
//                 ans = true;
//         }
//     }

//     if (ans)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }
