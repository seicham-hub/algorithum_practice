#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int m, sum = 0;
    cin >> m;
    vector<int> d(m);

    rep(i, m)
    {
        cin >> d[i];
        sum += d[i];
    }

    int middle = (sum + 1) / 2;

    int tmpSum = 0;

    rep(i, m)
    {

        if (middle <= tmpSum + d[i])
        {
            cout << i + 1 << " " << middle - tmpSum << endl;
            return 0;
        }

        tmpSum += d[i];
    }

    return 0;
}