#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> r(n);
    rep(i, n) cin >> r[i];

    vector<vector<int>> ans;

    function<void(int, ll, vector<int>)> rec = [&](int i, ll total, vector<int> tmp)
    {
        if (i > n - 1 && total % k == 0)
        {
            ans.push_back(tmp);
        }

        for (int j = 1; j <= r[i]; j++)
        {
            vector<int> ntmp = tmp;
            ntmp.push_back(j);
            rec(i + 1, total + j, ntmp);
        }
    };

    rec(0, 0, {});

    for (auto aa : ans)
    {
        for (int ai : aa)
            cout << ai << " ";
        cout << "\n";
    }

    return 0;
}