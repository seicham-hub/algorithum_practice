#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

bool isNibu = true;
int ans = 0;
int n, m;
vector<int> c(110000, -1);
vector<vector<int>> g;

void dfs(int now, int col)
{

    c[now] = col;

    for (auto next : g[now])
    {
        if (c[next] == col)
        {
            isNibu = false;
            return;
        }
        if (c[next] != -1)
            continue;
        dfs(next, (col + 1) % 2);
    }

    return;
}

int main()
{

    cin >> n >> m;

    vector<int> a(m), b(m);
    g.resize(n + 1);

    rep(i, m)
    {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    dfs(1, 0);

    if (isNibu)
    {
        int b = 0;
        int w = 0;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
                b++;
            else if (c[i] == 1)
                w++;
        }

        cout << 1LL * b * w - m << endl;
    }
    else
    {
        cout << 1LL * n * (n - 1) / 2 - m << endl;
    }

    return 0;
}
