// https://atcoder.jp/contests/abc336/tasks/abc336_c

// 2025_02_15もう一度
// 時間かかったのとエッジケース

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    ll n;
    cin >> n;
    n--;

    string ans = "";
    unordered_map<int, int> mp = {{0, 0}, {1, 2}, {2, 4}, {3, 6}, {4, 8}};

    while (true)
    {
        ans += to_string(mp[n % 5]);
        n = n / 5;

        if (n == 0)
            break;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)
// using ll = long long;
// using P = pair<int, int>;

// int main()
// {

//     ll n;
//     cin >> n;
//     n--;

//     ll dx[5] = {0, 2, 4, 6, 8};

//     string ans = "";

//     if (n == 0)
//     {
//         cout << 0 << endl;
//         return 0;
//     }

//     while (n > 0)
//     {

//         ans += (to_string(dx[n % 5]));
//         n = n / 5;
//     }

//     reverse(ans.begin(), ans.end());

//     cout << ans << endl;

//     return 0;
// }