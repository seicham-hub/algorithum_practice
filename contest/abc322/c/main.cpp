#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;

    rep(i, m)
    {
        int a;
        cin >> a;
        a--;
        q.push(a);
    }

    vector<int> ans(n);

    rep(i, n)
    {
        int d = q.front();
        ans[i] = d - i;
        if (d - i == 0)
            q.pop();
    }

    rep(i, n)
    {

        cout << ans[i] << endl;
    }

    return 0;
}