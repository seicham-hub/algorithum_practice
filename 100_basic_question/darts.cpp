// https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c
// わからなかった

// 2024_06_21もう一度
// 2024_06_22もう一度

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> p(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> p[i];

    vector<ll> q;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            q.push_back(p[i] + p[j]);

    sort(q.begin(), q.end());

    ll ans = 0;
    for (int qi : q)
    {
        auto it = upper_bound(q.begin(), q.end(), m - qi);
        if (it == q.begin() || it == q.end())
            continue;
        it--;
        ans = max(ans, qi + *it);
    }

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int main()
// {
//     int n, m;
//     cin >> n >> m;

//     vector<int> p(n + 1, 0);

//     for (int i = 1; i <= n; i++)
//         cin >> p[i];

//     vector<ll> q;
//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             q.push_back(p[i] + p[j]);
//         }
//     }

//     sort(q.begin(), q.end());

//     ll ans = 0;

//     for (int i = 0; i < q.size(); i++)
//     {
//         auto it = upper_bound(q.begin(), q.end(), m - q[i]);

//         if (it == q.begin() || it == q.end())
//             continue;

//         it--;
//         ll qj = *it;
//         ans = max(ans, q[i] + qj);
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int n, m;

// int main()
// {

//     cin >> n >> m;

//     vector<int> p(n + 1, 0);

//     map<ll, bool> is_exist;

//     for (int i = 1; i <= n; i++)
//     {
//         cin >> p[i];

//         is_exist[p[i]] = true;
//         is_exist[2 * p[i]] = true;
//     }

//     for (int i = 0; i < p.size(); i++)
//     {
//         for (int j = 0; j < p.size(); j++)
//         {
//             if (is_exist[p[i] + p[j]])
//                 if(p[i]+p[j]+)
//         }
//     }
//     return 0;
// }
