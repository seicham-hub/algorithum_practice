// https://atcoder.jp/contests/dp/tasks/dp_k
// 0504もう一度
// 0508もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 残っている石の数がｎの時、自分が勝つか
    vector<bool> dp(k + 1);
    dp[0] = false;

    for (int i = 1; i <= k; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] = dp[i] | !dp[i - a[j]];
        }
    }

    if (dp[k])
        cout << "First" << endl;
    else
        cout << "Second" << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     // 石の個数がnで残った石がこの状態で先手or後手が勝つか負けるか
//     vector<bool> dp(k + 1);

//     dp[0] = false;

//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {

//             if (i - a[j] >= 0)
//                 dp[i] = dp[i] || !dp[i - a[j]];
//         }
//     }

//     if (dp[k])
//         cout << "First" << endl;
//     else
//         cout << "Second" << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// // 山の石がi個で自分の手番の時勝利するかどうか
// bool dp[100010];

// int main()
// {
//     int n, k, a[100010];
//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i - a[j] >= 0)
//                 dp[i] = dp[i] | !dp[i - a[j]];
//         }
//     }

//     if (dp[k])
//         cout << "First" << endl;
//     else
//         cout << "Second" << endl;

//     return 0;
// }

/*
5/8やり直し分
*/

// #include <bits/stdc++.h>
// using namespace std;

// bool dp[100010];

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n + 1);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i - a[j] >= 0)
//             {
//                 dp[i] = dp[i] | !dp[i - a[j]];
//             }
//         }
//     }

//     if (dp[k])
//         cout << "First" << endl;
//     else
//         cout << "Second" << endl;

//     return 0;
// }

/*
5/4やり直し分
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // 山がi個残っている時に自分の手番の際の勝ち負けをdp[i]
// bool dp[100010];

// int main()
// {
//     int n, k;

//     cin >> n >> k;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     sort(a.begin(), a.end());

//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i - a[j] < 0)
//                 break;
//             else
//                 // cout << "i=" << i << " a[j]=" << a[j] << " dp[i]=" << dp[i] << endl;
//                 dp[i] = dp[i] | !dp[i - a[j]];
//         }
//     }

//     if (dp[k])
//         cout << "First" << endl;
//     else
//         cout << "Second" << endl;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// bool dp[110000];

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n);

//     for (int i = 0; i < n; i++)
//         cin >> a[i];

//     // DP dp[i]は残りの石がi個のときの局面の勝敗
//     for (int i = 1; i <= k; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i - a[j] >= 0)
//                 dp[i] |= !dp[i - a[j]];
//         }
//     }

//     if (dp[k])
//         cout << "First" << endl;
//     else
//         cout << "Second" << endl;

//     return 0;
// }