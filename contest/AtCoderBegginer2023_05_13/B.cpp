// https://atcoder.jp/contests/abc301/tasks/abc301_b

// 0514もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < a.size(); i++)
    {
        if (a[i - 1] + 1 < a[i])
            a.insert(a.begin() + i, a[i - 1] + 1);
        if (a[i - 1] - 1 > a[i])
            a.insert(a.begin() + i, a[i - 1] - 1);
    }

    for (auto ans : a)
        cout << ans << " ";

    return 0;
}

// 本番のコード（自分）

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, a[110];
//     cin >> n;

//     vector<int> ans;

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     for (int i = 0; i < n - 1; i++)
//     {
//         if (abs(a[i + 1] - a[i]) == 1)
//         {
//             ans.push_back(a[i]);
//         }
//         else if (a[i + 1] > a[i])
//         {
//             int num = a[i + 1] - a[i];
//             for (int j = 0; j < num; j++)
//             {
//                 ans.push_back(a[i] + j);
//             }
//         }
//         else if (a[i] > a[i + 1])
//         {
//             int num = a[i] - a[i + 1];
//             for (int j = 0; j < num; j++)
//             {
//                 ans.push_back(a[i] - j);
//             }
//         }
//     }
//     ans.push_back(a[n - 1]);

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }
