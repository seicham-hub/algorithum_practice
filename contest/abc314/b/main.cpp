#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, x;
    cin >> n;
    vector<int> c(n);

    vector<vector<int>> xarr(38, vector<int>());

    rep(i, n)
    {
        cin >> c[i];
        rep(j, c[i])
        {
            int a;
            cin >> a;

            xarr[a].push_back(i + 1);
        }
    }
    cin >> x;

    map<int, int> hToNum;
    vector<vector<int>> NumToHuman(38);

    for (auto human : xarr[x])
    {
        hToNum[human] = c[human - 1];
        NumToHuman[c[human - 1]].push_back(human);
    }

    int minx = 1e9;

    for (int i = 1; i < 101; i++)
    {
        if (hToNum[i])
        {

            minx = min(minx, hToNum[i]);
        }
    }

    if (minx == 1e9)
    {

        cout << 0 << endl;
        return 0;
    }

    cout << NumToHuman[minx].size() << endl;

    for (auto ans : NumToHuman[minx])
    {
        cout << ans << " ";
    }

    return 0;
}