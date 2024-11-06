#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> nv(n);
    rep(i, n) nv[i] = i + 1;

    int cnt = 0;
    for (int i = l - 1; i < r; i++)
    {
        nv[i] = r - cnt;
        cnt++;
    }

    rep(i, n) cout << nv[i] << " ";

    return 0;
}