#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int r;
    cin >> r;

    int goal = 0;

    if (1 <= r && r <= 99)
        goal = 100 - r;
    else if (100 <= r && r <= 199)
        goal = 200 - r;
    else if (200 <= r && r <= 299)
        goal = 300 - r;

    cout << goal << endl;

    return 0;
}