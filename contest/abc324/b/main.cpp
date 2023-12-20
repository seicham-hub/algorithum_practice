#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    long long n;
    cin >> n;

    while (n > 1 && n % 3 == 0)
    {
        n = n / 3;
    }
    while (n > 1 && n % 2 == 0)
    {
        n = n / 2;
    }

    if (n == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}