#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;

int main()
{
    int h;
    cin >> h;

    ll tall = 0;
    int i = 0;

    while (tall <= h)
    {
        tall += pow(2, i);
        i++;
    }

    cout << i << endl;

    return 0;
}