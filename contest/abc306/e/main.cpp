#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n, k, q;
    cin >> n >> k >> q;
    vector<int> x(q), y(q);

    vector<int> a(n);
    int sum = 0;

    rep(i, q)
    {
        cin >> x[i] >> y[i];

        if (y[i] >= a[k - 1])
        {
            sum += y[i] - a[k - 1];
        }
        else
        {
            if (x[i] < k)
                sum = sum - a[x[i] - 1] + a[k];
        }
        a[x[i] - 1] = y[i];
        sort(a.begin(), a.end(), greater<int>());

        cout << sum << endl;
    }

    return 0;
}