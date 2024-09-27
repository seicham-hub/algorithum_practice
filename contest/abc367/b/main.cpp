// https://atcoder.jp/contests/abc367/tasks/abc367_b

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    string x;
    cin >> x;

    string xcp = x;
    while (xcp.back() == '0')
    {
        xcp.pop_back();
        if (xcp.back() == '.')
        {
            xcp.pop_back();
            break;
        }
    }

    cout << xcp << endl;

    return 0;
}