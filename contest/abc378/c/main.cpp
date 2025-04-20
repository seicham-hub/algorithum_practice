// https://atcoder.jp/contests/abc378/tasks/abc378_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n) cin >> a[i];

    map<int, int> maxInd;

    vector<int> b(n);

    rep(i, n)
    {
        if (maxInd.count(a[i]))
            b[i] = maxInd[a[i]] + 1;
        else
            b[i] = -1;
        maxInd[a[i]] = i;
    }

    rep(i, n) cout << b[i] << " ";

    return 0;
}