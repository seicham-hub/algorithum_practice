// https://atcoder.jp/contests/abc298/tasks/abc298_c

// 0521もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;

    cin >> n >> q;
    vector<vector<int>> numToBox(200001);
    vector<vector<int>> boxn(n + 1);

    for (int num = 0; num < q; num++)
    {

        int f, i, j;
        cin >> f;
        if (f == 1)
        {
            cin >> i >> j;

            numToBox[i].push_back(j);
            boxn[j].push_back(i);
        }
        else if (f == 2)
        {
            cin >> i;
            sort(boxn[i].begin(), boxn[i].end());

            for (int k = 0; k < boxn[i].size(); k++)
            {
                cout << boxn[i][k] << " ";
            }
            cout << endl;
        }
        else if (f == 3)
        {
            cin >> i;
            sort(numToBox[i].begin(), numToBox[i].end());

            for (int k = 0; k < numToBox[i].size(); k++)
            {
                // 末尾にごみが残るのでerase
                numToBox[i].erase(unique(numToBox[i].begin(), numToBox[i].end()), numToBox[i].end());
                // if (k >= 1 && numToBox[i][k] == numToBox[i][k - 1])
                //     continue;
                cout << numToBox[i][k] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}