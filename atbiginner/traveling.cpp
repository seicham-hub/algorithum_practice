// 0412もう一度
// 偶数と奇数に関する性質をパリティと言う。
// xi+yiの偶奇に着目。xi+yiは毎秒ごとに必ず偶奇が入れ替わる。
// dtとdistの偶奇が一致していれば、行ったり戻ったりを繰り返してたどり着ける。

#include <iostream>
using namespace std;

int main()
{
    int N;
    int t[110000], x[110000], y[110000];
    cin >> N;
    t[0] = x[0] = 0;
    for (int i = 0; i < N; i++)
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];

    bool can = true;
    for (int i = 0; i < N; i++)
    {
        int dt = t[i + 1] - t[i];
        int dist = abs(x[i + 1] - x[i]);
        if (dt < dist)
            can = false;
        if (dist % 2 != dt % 2)
            can = false;
    }
    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

// 自分のコード

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, t[100001] = {}, x[100001], y[100001], curx = 0, cury = 0;
//     bool result = true;
//     cin >> n;

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> t[i] >> x[i] >> y[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         int canMoveDistance = t[i] - t[i - 1];
//         int diff = abs(x[i] + y[i] - curx - cury);

//         if (canMoveDistance < diff)
//         {
//             result = false;
//             break;
//         }
//         else
//         {
//             if ((canMoveDistance - diff) % 2 == 0)
//                 ;
//             else
//             {
//                 result = false;
//                 break;
//             }
//         }

//         curx = x[i];
//         cury = y[i];
//     }

//     if (result == true)
//         cout << "Yes" << endl;
//     else
//         cout << "No" << endl;

//     return 0;
// }
