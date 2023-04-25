
// すべての桁が1以上 M以下であるような、増加的な N
// 桁の整数をすべて出力してください。（増加的な整数とは、
// 112や1355679のような数のことを指します。）

int n, m;

void func(string cur)
{
    if (cur.size() == n)
    {
        cout << cur << endl;
        return;
    }
    int last = 1;
    if (cur.size() >= 1)
        last = cur[cur.size() - 1];
    for (int i = last; i <= m; i++)
    {
        string nex = cur;
        nex += ('0' + i);
        func(nex);
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

    cin >> m >> n;

    return 0;
}
