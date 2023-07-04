#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

bool desc_asc(pair<double, int> &left, pair<double, int> &right)
{
    if (left.first == right.first)
    {
        return left.second < right.second;
    }
    else
    {
        return left.first < right.first;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), b(n);

    vector<pair<double, int>> ans(n);

    rep(i, n)
    {
        cin >> a[i] >> b[i];

        double p = (double)(a[i] + b[i]) / (double)a[i];

        ans[i] = {p, i};
    }

    sort(ans.begin(), ans.end(), desc_asc);

    rep(i, n)
    {
        if (i == n - 1)
        {
            cout << ans[i].second + 1 << endl;
            continue;
        }
        cout << ans[i].second + 1 << " ";
    }

    return 0;
}