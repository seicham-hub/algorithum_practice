// https://atcoder.jp/contests/abc369/tasks/abc369_a
// 2024_09_14もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;

    for (int i = -200; i < 300; i++)
    {
        if (i - a == b - i)
            ans++;
        else if (i - b == a - i)
            ans++;

        else if (b - a == i - b)
            ans++;
        else if (a - b == i - a)
            ans++;

        else if (a - i == b - a)
            ans++;
        else if (b - i == a - b)
            ans++;
    }

    cout << ans << endl;

    return 0;
}