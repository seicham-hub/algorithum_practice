#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> aq;
    rep(i, n)
    {
        int a;
        cin >> a;
        aq.push(a);
    }

    int empty = k;

    int ans = 0;
    while (!aq.empty())
    {
        int now = aq.front();
        if (empty >= now)
        {
            empty -= now;
            aq.pop();
        }
        else
        {
            ans++;
            empty = k;
        }
    }
    ans++;

    cout << ans << endl;

    return 0;
}