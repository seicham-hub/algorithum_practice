#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n, k, p;
    cin >> n >> k >> p;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(k));

    rep(i, n)
    {
        cin >> c[i];
        rep(j, k) cin >> a[i][j];
    }

    return 0;
}