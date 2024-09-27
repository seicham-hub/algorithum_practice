// https://atcoder.jp/contests/abc369/tasks/abc369_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<char> s(n);

    rep(i, n)
    {
        int ai;
        char si;
        cin >> ai >> si;
        ai--;

        a[i] = ai;
        s[i] = si;
    }

    int ans = 1e6;

    rep(l, 100)
    {
        rep(r, 100)
        {

            int bl = l;
            int br = r;
            int tmp = 0;
            rep(i, n)
            {
                if (s[i] == 'L')
                {
                    tmp += abs(a[i] - bl);
                    bl = a[i];
                }
                else if (s[i] == 'R')
                {
                    tmp += abs(a[i] - br);
                    br = a[i];
                }
            }

            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}