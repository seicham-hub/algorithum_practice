// https://atcoder.jp/contests/abc165/tasks/abc165_c

// 0425もう一度（時間かかりすぎ）
// 重複順列として考えると、10^10で間に合わないが、講義単調増加なので前の要素参照しなければOK

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

#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int cat[11][11][11];

int v[11];

int mx, sum;

void bkt(int k)
{
    if (k == n + 1)
    {
        mx = max(mx, sum);
        return;
        ;
    }

    for (int i = v[k - 1]; i <= m; i++)
    {
        v[k] = i;
        int ant = sum;

        for (int j = 1; j < k; j++)
            sum += cat[j][k][i - v[j]];

        bkt(k + 1);

        sum = ant;
    }
}

int main()
{
    cin >> n >> m >> q;

    for (int i = 1; i <= q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cat[a][b][c] += d;
    }

    v[1] = 1;

    bkt(2);

    cout << mx << "\n";

    return 0;
}