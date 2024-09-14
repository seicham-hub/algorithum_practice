#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    a.insert(a.begin() + k, x);

    for (int ai : a)
        cout << ai << " ";

    return 0;
}