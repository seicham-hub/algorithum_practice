// https://atcoder.jp/contests/abc345/tasks/abc345_c

// 分からなかった...
// 2025_02_08もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

ll nc2(ll n)
{

    return n * (n - 1) / 2;
}

int main()
{

    string s;
    cin >> s;

    int n = s.size();

    vector<int> cnt(26);

    for (char c : s)
    {
        cnt[c - 'a']++;
    }

    ll ans = nc2(n);
    ll same = 0;
    rep(i, 26)
    {
        int tmpn = cnt[i];
        same += nc2(tmpn);
    }

    ans -= same;
    if (same)
        ans++;

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// ll c2(ll n)
// {

//     return n * (n - 1) / 2;
// }

// int main()
// {

//     string s;
//     cin >> s;

//     vector<int> al(26);
//     int n = s.size();

//     for (char c : s)
//     {
//         al[c - 'a']++;
//     }

//     ll same = 0;
//     rep(i, 26)
//     {
//         int tmpn = al[i];
//         same += c2(tmpn);
//     }
//     ll diff = c2(n) - same;

//     ll ans = diff;
//     if (same)
//         ans++;

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     string s;
//     cin >> s;

//     vector<int> al(26);
//     int n = s.size();

//     ll ans = (n - 1) * (n - 1 + 1) / 2;

//     for (char c : s)
//     {
//         al[c - 'a']++;
//     }

//     rep(i, 26)
//     {
//         int tmpn = al[i];
//         ll minus = (tmpn - 1) * (tmpn - 1 + 1) / 2;
//         if (minus)
//             ans -= minus - 1;
//     }

//     cout << ans << endl;

//     return 0;
// }