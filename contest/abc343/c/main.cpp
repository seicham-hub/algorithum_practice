// https://atcoder.jp/contests/abc343/tasks/abc343_c

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;

    string ans = "";

    ll now = 1;
    while (pow(now, 3) <= n)
    {
        ll target = pow(now, 3);

        string converted = to_string(target);

        bool isPalindrome = true;
        rep(i, converted.size() / 2)
        {
            if (converted[i] != converted[converted.size() - 1 - i])
                isPalindrome = false;
        }

        if (isPalindrome)
            ans = converted;

        now++;
    }

    cout << ans << endl;

    return 0;
}