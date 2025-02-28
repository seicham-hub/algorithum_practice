// https://atcoder.jp/contests/abc328/tasks/abc328_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> rui(s.size() + 1);

    rep(i, s.size())
    {
        if (i == 0)
            continue;
        if (s[i] == s[i - 1])
        {
            rui[i + 1] = rui[i] + 1;
        }
        else
        {
            rui[i + 1] = rui[i];
        }
    }

    rep(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << rui[r] - rui[l] << endl;
    }

    return 0;
}