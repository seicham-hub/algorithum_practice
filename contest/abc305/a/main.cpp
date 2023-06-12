#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, index;

    cin >> n;

    rep(i, 21)
    {
        int dist = 5 * i;
        if (dist == n)
        {
            cout << dist << endl;
            return 0;
        }
        if (dist >= n)
        {
            index = i;
            break;
        }
    }

    if (abs(5 * index - n) > abs(5 * (index - 1) - n))
    {
        cout << 5 * (index - 1) << endl;
    }
    else
    {
        cout << 5 * index << endl;
    }

    return 0;
}