// https://atcoder.jp/contests/abc126/tasks/abc126_d

#include <bits/stdc++.h>
using namespace std;

using Graph = vector<int>;

int main()
{
    int n, u[110000], v[110000];
    long long w[110000];

    for (int i = 0; i < n; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    Graph G(n);

    for (int i = 0; i < n; i++)
    {
        if (w[i] % 2 == 0)
            G[u[i]] = G[v[i]] = 1;
    }

    return 0;
}
