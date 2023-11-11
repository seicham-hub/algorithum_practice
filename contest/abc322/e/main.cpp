// https://atcoder.jp/contests/abc322/tasks/abc322_e
// わからなかった
// 11/06もう一度
// 11/11もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int n, k, p;

int int_pow(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;
}

int encode(const vector<int> &a)
{

    int result = 0;
    int keta = 0;
    for (auto x : a)
    {
        if (x > p)
            x = p;
        result += x * int_pow(p + 1, keta);
        keta++;
    }

    return result;
}

vector<int> decode(int en_num)
{

    vector<int> result(k, 0);

    int i = 0;
    while (en_num)
    {
        result[i] = en_num % (p + 1);
        en_num = en_num / (p + 1);
        i++;
    }

    return result;
}

int main()
{

    cin >> n >> k >> p;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(k));

    rep(i, n)
    {
        cin >> c[i];
        rep(j, k)
        {
            cin >> a[i][j];
        }
    }

    // dp[i][a] iまで実行するか決めた場合に、ステータスがa1,a2,///,akとなる時のコスト最小値

    vector<int> a_full(k, p);
    int j_max = encode(a_full);

    vector<vector<long long>> dp(n + 1, vector<long long>(j_max + 1, 1e12));

    dp[0][0] = 0;

    rep(i, n)
    {
        rep(j, j_max + 1)
        {
            vector<int> j_arr = decode(j);
            rep(m, k)
            {
                j_arr[m] += a[i][m];
                if (j_arr[m] > p)
                    j_arr[m] = p;
            }

            int next = encode(j_arr);
            dp[i + 1][next] = min(dp[i][j] + c[i], dp[i + 1][next]);
            dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
        }
    }

    if (dp[n][j_max] >= 1e12)
        cout << -1 << endl;
    else
        cout << dp[n][j_max] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int n, k, p;
//     cin >> n >> k >> p;
//     vector<int> c(n);
//     vector<vector<int>> a(n, vector<int>(k));

//     rep(i, n)
//     {
//         cin >> c[i];
//         rep(j, k) cin >> a[i][j];
//     }

//     return 0;
// }