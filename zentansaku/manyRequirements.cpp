// https://atcoder.jp/contests/abc165/tasks/abc165_c

#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[51], b[51], c[51], d[51], ans = 0;
;

void recursion(string cur)
{

    if (cur.size() == n)
    {
        int tmp_max = 0;
        for (int i = 1; i <= q; i++)
        {
            if (cur[b[i] - 1] - cur[a[i] - 1] == c[i])
                tmp_max += d[i];
        }
        ans = max(ans, tmp_max);
        return;
    }
    int last = 1;
    if (cur.size() >= 1)
        last = cur[cur.size() - 1] - '0';

    for (int i = last; i <= m; i++)
    {
        string next = cur;
        next += '0' + i;
        recursion(next);
    }
}

int main()
{

    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    string str;
    recursion(str);

    cout << ans << endl;

    return 0;
}
