// 0411もう一度
// 0412もう一度

// 重複なしの集計処理、バケット法による解答
// 配列numを用意して各要素num[i]が存在するか

#include <iostream>
using namespace std;

int main()
{
    int n, curN, d[101] = {}, result = 0;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> curN;
        d[curN]++;
    }

    for (int i = 1; i <= 100; i++)
    {
        if (d[i] > 0)
            result++;
    }

    cout << result << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     int N;
//     int d[110];
//     cin >> N;

//     for (int i = 0; i < N; i++)
//         cin >> d[i];

//     int num[110] = {};

//     for (int i = 0; i < N; i++)
//     {
//         num[d[i]]++;
//     }

//     int res = 0;
//     for (int i = 1; i <= 100; i++)
//     {
//         if (num[i])
//         {
//             res++;
//         }
//     }

//     cout << res << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int N, count = 0, before = -9;

//     vector<int> d;
//     cin >> N;
//     d.resize(N);
//     for (int i = 0; i < N; i++)
//         cin >> d[i];
//     sort(d.begin(), d.end());

//     for (int i = 0; i < N; i++)
//     {
//         if (before == d[i])
//             continue;
//         count++;
//         before = d[i];
//     }

//     cout << count << endl;

//     return 0;
// }
