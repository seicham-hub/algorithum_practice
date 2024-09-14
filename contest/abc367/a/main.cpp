// https://atcoder.jp/contests/abc367/tasks/abc367_a

// 以下でもOK
// while(b != c){
//  b %= 24;
// }

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    set<int> wake;

    if (b < c)
    {
        for (int s = c; s <= 23; s++)
            wake.insert(s);
        for (int e = 0; e <= b; e++)
            wake.insert(e);
    }
    else if (c < b)
    {
        for (int s = c; s <= b; s++)
        {
            wake.insert(s);
        }
    }

    if (wake.count(a))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}