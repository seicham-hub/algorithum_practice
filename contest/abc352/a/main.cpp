#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int start = x > y ? y : x;
    int end = x > y ? x : y;

    for (int i = start; i <= end; i++)
    {
        if (i == z)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}