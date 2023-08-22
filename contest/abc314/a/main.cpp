#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    string ans = "";
    string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

    rep(i, n + 2)
    {
        ans += pi[i];
    }

    cout << ans << endl;

    return 0;
}