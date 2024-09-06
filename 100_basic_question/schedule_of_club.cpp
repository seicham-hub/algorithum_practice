// https://atcoder.jp/contests/joi2014yo/tasks/joi2014yo_d
// 解けたけど、時間かかりすぎ（1時間位）
// 2024_09_04もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    string owner;
    cin >> owner;

    vector<vector<ll>> dp(n + 1, vector<ll>((1 << 3), 0));

    map<char, int> mp = {{'J', 2}, {'O', 1}, {'I', 0}};

    for (int i = 1; i <= n; i++)
    {
        for (int msk = 1; msk < (1 << 3); msk++)
        {
            char now_ow = owner[i - 1];
            if (msk & (1 << mp[now_ow]))
            {

                if (i == 1 && msk & (1 << 2))
                {
                    dp[i][msk] = 1;
                }
                else
                {
                    for (int before = 0; before < (1 << 3); before++)
                    {

                        if (msk & before && dp[i - 1][before] != 0)
                        {
                            dp[i][msk] += dp[i - 1][before];
                            dp[i][msk] %= 10007;
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << 3); i++)
    {
        ans += dp[n][i];
        ans %= 10007;
    }

    cout << ans << endl;

    return 0;
}

// お手本コード
// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 10007;
// int main() {
//     int N;
//     string S;
//     cin >> N >> S;

//     auto add = [&](long long &a, long long b) -> void {
//         a += b;
//         if (a >= MOD) a -= MOD;
//     };
//     vector<vector<long long>> dp(N+1, vector<long long>(8, 0));
//     dp[0][1] = 1;
//     for (int i = 0; i < N; ++i) {
//         int sekinin;
//         if (S[i] == 'J') sekinin = 0;
//         else if (S[i] == 'O') sekinin = 1;
//         else sekinin = 2;
//         for (int bit = 0; bit < (1<<3); ++bit) {
//             for (int bit2 = 0; bit2 < (1<<3); ++bit2) {
//                 if (!(bit2 & (1<<sekinin))) continue;
//                 if (!(bit & bit2)) continue;
//                 add(dp[i+1][bit2], dp[i][bit]);
//             }
//         }
//     }
//     long long res = 0;
//     for (int bit = 0; bit < (1<<3); ++bit) add(res, dp[N][bit]);
//     cout << res << endl;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {
//     int n;
//     cin >> n;

//     string supervisor;

//     cin >> supervisor;

//     map<char, int> mp = {{'J', 2}, {'O', 1}, {'I', 0}};

//     vector<vector<ll>> dp(n + 1, vector<ll>((1 << 3), 0));

//     for (int i = 1; i <= n; i++)
//     {
//         for (int msk = 1; msk < (1 << 3); msk++)
//         {
//             int now_sp = mp[supervisor[i - 1]];
//             if (msk & (1 << now_sp))
//                 // 最初はJ君がカギを持っているので絶対参加
//                 if (i == 1 && msk & (1 << 2))
//                 {
//                     dp[i][msk] = 1;
//                 }
//                 else
//                 {
//                     for (int before = 0; before < 8; before++)
//                         if (msk & before && dp[i - 1][before] != -1)
//                         {
//                             dp[i][msk] += dp[i - 1][before];
//                             dp[i][msk] %= 10007;
//                         }
//                 }
//         }
//     }

//     ll ans = 0;

//     for (int i = 0; i < (1 << 3); i++)
//     {
//         ans += dp[n][i];
//         ans %= 10007;
//     }

//     cout << ans << endl;

//     return 0;
// }