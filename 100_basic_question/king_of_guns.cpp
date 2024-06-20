// https://atcoder.jp/contests/abc023/tasks/abc023_d
// 2024_06_19もう一度

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool check(ll &x, vector<pair<int, int>> &hs)
{

    vector<ll> seconds;
    for (auto hsi : hs)
    {
        ll hi = hsi.first;
        ll si = hsi.second;
        if (x < hi)
            return false;
        ll left_sec = (x - hi) / si;

        seconds.push_back(left_sec);
    }

    sort(seconds.begin(), seconds.end());
    for (int i = 0; i < seconds.size(); i++)
    {
        if (seconds[i] < i)
            return false;
    }

    return true;
}

int main()
{

    int n;
    cin >> n;

    vector<pair<int, int>> hs(n);

    for (int i = 0; i < n; i++)
        cin >> hs[i].first >> hs[i].second;

    ll left = -1;
    ll right = 1e15;

    while (abs(left - right) > 1)
    {

        ll mid = (left + right) / 2;
        if (check(mid, hs))
            right = mid;
        else
            left = mid;
    }

    cout << right << endl;

    return 0;
}

// 自分で書いたコード　分からなかった
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     long long ans = 0;

//     cin >> n;

//     vector<pair<int, int>> hs(n);

//     for (int i = 0; i < n; i++)
//     {
//         cin >> hs[i].first >> hs[i].second;
//     }

//     auto compare = [](const pair<int, int> &a, const pair<int, int> &b)
//     {
//         return a.second > b.second;
//     };

//     sort(hs.begin(), hs.end(), compare);

//     for (int i = 0; i < n; i++)
//     {
//     }

//     cout << ans << endl;
//     return 0;
// }