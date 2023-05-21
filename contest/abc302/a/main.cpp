#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long a, b, ans = 0;

    cin >> a >> b;

    ans += a / b;
    if (a % b != 0)
    {

        ans++;
    }

    cout << ans << endl;
    return 0;
}