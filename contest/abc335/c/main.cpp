// https://atcoder.jp/contests/abc335/tasks/abc335_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n, q;
    cin >> n >> q;

    vector<P> his;

    rep(i, n) his.emplace_back(n - i, 0);

    map<char, P> mp = {{'R', {1, 0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};

    rep(i, q)
    {
        int a;
        cin >> a;

        if (a == 1)
        {

            char di;
            cin >> di;
            auto [x, y] = his.back();
            auto [dx, dy] = mp[di];

            his.emplace_back(x + dx, y + dy);
        }
        else
        {
            int p;
            cin >> p;
            p--;

            auto [x, y] = his[his.size() - 1 - p];
            cout << x << " " << y << endl;
        }
    }

    return 0;
}