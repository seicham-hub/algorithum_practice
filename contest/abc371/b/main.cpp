#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{

    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    vector<char> b(m);

    vector<string> ans(m, "No");
    vector<bool> is_first(n, false);

    rep(i, m)
    {
        cin >> a[i] >> b[i];
        a[i]--;
    }

    rep(i, m)
    {
        int house = a[i];
        int sex = b[i];
        if (b[i] == 'M' && is_first[house] == false)
        {
            ans[i] = "Yes";
            is_first[house] = true;
        }
    }

    for (auto ai : ans)
    {
        cout << ai << endl;
    }

    return 0;
}