// https://atcoder.jp/contests/cpsco2019-s1/tasks/cpsco2019_s1_c

// 0425もう一度

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int divisions[2] = {5, 1};

ll count_coins(ll price)
{
    ll result = 0;
    for (ll i = 1e9; i >= 1; i /= 10)
    {

        for (auto d : divisions)
        {

            result += price / ll(d * i);
            price %= (d * i);
        }
    }

    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 1e18;

    function<void(int, int, ll)> dfs = [&](int index, int count, ll sum_price)
    {
        if (count == k)
        {
            ans = min(ans, count_coins(sum_price));
            return;
        }

        if (index == a.size() - 1)
            return;

        dfs(index + 1, count, sum_price);
        ll new_price = sum_price + a[index];
        dfs(index + 1, count + 1, new_price);
    };

    dfs(0, 0, 0);

    cout << ans << endl;

    return 0;
}

/*
0425解きなおし分
*/

// #include "bits/stdc++.h"
// using namespace std;

// int n, k, c[10] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 5}, minCoin = 10000000;
// long long a[33];

// void dfs(long long sum, int takeNum, int nowInd)
// {
//     if (takeNum == k)
//     {
//         int tmp_coin = 0;
//         while (sum > 0)
//         {
//             tmp_coin += c[sum % 10];
//             sum /= 10;
//         }
//         minCoin = min(tmp_coin, minCoin);
//         return;
//     }
//     else if (nowInd < n)
//     {
//         dfs(sum, takeNum, nowInd + 1);
//         dfs(sum + a[nowInd], takeNum + 1, nowInd + 1);
//     }
// }

// int main()
// {

//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     dfs(0, 0, 0);
//     cout << minCoin << endl;

//     return 0;
// }

// #include "bits/stdc++.h"
// using namespace std;

// int n, k, ans = 1000000000, c[10] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 5};
// long long A[32];

// void dfs(long long sum, int takeNum, int nowInd)
// {
//     if (takeNum == k)
//     {
//         int cnt = 0;
//         while (sum > 0)
//         {
//             cnt += c[sum % 10];
//             sum /= 10;
//         }
//         ans = min(ans, cnt);
//     }
//     else if (nowInd < n)
//     {
//         dfs(sum + A[nowInd], takeNum + 1, nowInd + 1);
//         dfs(sum, takeNum, nowInd + 1);
//     }
// }

// int main()
// {

//     cin >> n >> k;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }

//     dfs(0, 0, 0);

//     cout << ans << endl;

//     return 0;
// }

// #include "bits/stdc++.h"
// using namespace std;

// int N, K, ans = 1000000000, C[10] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 5};
// long long A[32];

// void DFS(long long X, int Y, int Z)
// {
//     if (Y == K)
//     {
//         long long x = X;
//         int count = 0;
//         while (x != 0)
//         {
//             count += C[x % 10];
//             x /= 10;
//         }
//         ans = min(ans, count);
//     }
//     else if (Z != N)
//     {
//         DFS(X, Y, Z + 1);
//         DFS(X + A[Z], Y + 1, Z + 1);
//     }
// }

// int main()
// {
//     cin >> N >> K;
//     for (int i = 0; i < N; i++)
//     {
//         cin >> A[i];
//     }
//     DFS(0, 0, 0);
//     cout << ans;
// }

// 自分のコード修正したもの
// 硬貨の数え方悪い、vector削除
// ただ、bit探索の中でさらにforを回しているので遅いと思われる。確実に2^32回るのでよくない？
// 2^22が10^7くらいなので限界はこのくらい

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, k, C[10] = {0, 1, 2, 3, 4, 1, 2, 3, 4, 5};
//     long long int a[40], min_ans = 3300000000;
//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int msk = 0; msk < (1 << n); msk++)
//     {
//         int cnt = 0;
//         int tmp_sum = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (msk & (1 << i))
//             {
//                 cnt++;
//                 tmp_sum += a[i];
//             }
//         }

//         if (cnt != k)
//             continue;

//         long long int tmp_min = 0;
//         while (tmp_sum > 0)
//         {
//             tmp_min += C[tmp_sum % 10];
//             tmp_sum /= 10;
//         }

//         min_ans = min(tmp_min, min_ans);
//     }

//     cout << min_ans << endl;

//     return 0;
// }

// 自分で書いたコード
// うまくいかないテストケースがある

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, k;
//     long long int a[40], min_ans = 3300000000;
//     cin >> n >> k;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }

//     for (int msk = 1; msk < (1 << n); msk++)
//     {
//         vector<int> syutoku;
//         for (int i = 0; i < n; i++)
//         {
//             if (msk & (1 << i))
//                 syutoku.push_back(i);
//         }

//         if (syutoku.size() != k)
//             continue;

//         long long int tmp_sum = 0;
//         for (int i = 0; i < syutoku.size(); i++)
//         {
//             tmp_sum += a[syutoku[i]];
//         }

//         long long int tmp_min = 0;
//         for (int i = 9; i >= 0; i--)
//         {

//             while ((tmp_sum - 5 * pow(10, i)) >= 0)
//             {
//                 tmp_sum = tmp_sum - 5 * pow(10, i);
//                 tmp_min++;
//                 if (tmp_sum == 0)
//                     break;
//             }

//             while ((tmp_sum - pow(10, i)) >= 0)
//             {
//                 tmp_sum = tmp_sum - pow(10, i);
//                 tmp_min++;
//                 if (tmp_sum == 0)
//                     break;
//             }

//             if (tmp_sum == 0)
//                 break;
//         }

//         min_ans = min(tmp_min, min_ans);
//     }

//     cout << min_ans << endl;

//     return 0;
// }
