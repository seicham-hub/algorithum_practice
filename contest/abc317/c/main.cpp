#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m;
long long ans = 0;
// 町→次の町,距離
vector<vector<pair<int, long long>>> load(n + 1);
vector<bool> seen(n + 1, false);

void dfs(int i, long long total, vector<bool> visited)
{
    visited[i] = true;
    for (auto p : load[i])
    {
        int next = p.first;
        long long diff = p.second;
        if (!visited[next])
            dfs(next, total + diff, visited);
    }

    ans = max(ans, total);
    return;
}

int main()
{

    cin >> n >> m;

    load.resize(n + 1);
    seen.resize(n + 1);

    rep(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        load[a].push_back({b, c});
        load[b].push_back({a, c});
    }

    rep(j, n + 1) seen[j] = false;
    for (int i = 1; i <= n; i++)
    {
        // iが始まりの町
        dfs(i, 0, seen);
    }

    cout << ans << endl;

    return 0;
}