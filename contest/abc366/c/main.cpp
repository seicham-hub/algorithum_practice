#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int q;
    cin >> q;

    unordered_map<int, int> ball_cnt;
    set<int> kind;

    rep(i, q)
    {
        int ord, x;
        cin >> ord;

        if (ord == 1)
        {
            cin >> x;
            ball_cnt[x]++;
            kind.insert(x);
        }
        else if (ord == 2)
        {
            cin >> x;
            ball_cnt[x]--;
            if (!ball_cnt[x])
                kind.erase(x);
        }
        else
        {
            cout << kind.size() << endl;
        }
    }

    return 0;
}