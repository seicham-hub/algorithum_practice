#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, t, a;
    cin >> n >> t >> a;

    int mid = n / 2 + 1;

    if (t >= mid || a >= mid)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}