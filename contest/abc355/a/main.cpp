#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    set<int> candidate;

    rep(i, 3)
    {
        candidate.insert(i + 1);
    }

    int a, b;
    cin >> a >> b;

    candidate.erase(a);
    candidate.erase(b);

    if (candidate.size() == 1)
    {
        cout << *candidate.begin() << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}