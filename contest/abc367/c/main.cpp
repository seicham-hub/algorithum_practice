// https://atcoder.jp/contests/abc367/tasks/abc367_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int n, k;
vector<vector<int>> ans;

int count(vector<int> tmp)
{
    int result = 0;
    for (auto t : tmp)
        result += t;

    return result;
}

void dfs(int now, vector<int> tmp, vector<int> &r)
{

    if (tmp.size() >= n)
    {
        if (count(tmp) % k == 0)
        {
            ans.push_back(tmp);
        }

        return;
    }

    for (int i = 1; i <= r[now]; i++)
    {
        vector<int> tmp_c = tmp;
        tmp_c.push_back(i);
        dfs(now + 1, tmp_c, r);
    }
}

int main()
{

    cin >> n >> k;

    vector<int> r(n);

    rep(i, n) cin >> r[i];

    dfs(0, {}, r);

    for (auto a : ans)
    {
        rep(i, n)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<int> r(n);

//     rep(i, n) cin >> r[i];

//     vector<vector<int>> ans;

//     function<void(int, ll, vector<int>)> rec = [&](int i, ll total, vector<int> tmp)
//     {
//         if (i > n - 1)
//         {
//             if (total % k == 0)
//                 ans.push_back(tmp);
//             return;
//         }

//         for (int j = 1; j <= r[i]; j++)
//         {
//             vector<int> ntmp = tmp;
//             ntmp.push_back(j);
//             rec(i + 1, total + j, ntmp);
//         }
//     };

//     rec(0, 0, {});

//     for (auto aa : ans)
//     {
//         for (int ai : aa)
//             cout << ai << " ";
//         cout << "\n";
//     }

//     return 0;
// }