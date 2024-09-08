#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    }

    int before = 1;

    for (int i = 1; i <= n; i++)
    {
        if (before >= i)
            before = a[before][i];
        else
            before = a[i][before];
    }

    cout << before << endl;

    return 0;
}