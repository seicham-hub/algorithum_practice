// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e

#include <bits/stdc++.h>
using namespace std;

int r, c;

void reverse_row(int &row, vector<vector<int>> &senbei)
{

    for (int &sen : senbei[row])
    {
        sen = sen ? 0 : 1;
    }
}

vector<int> count_on_column(vector<vector<int>> &senbei)
{
    vector<int> on_column(c);
    for (int i = 0; i < c; i++)
    {
        int count = 0;
        for (int j = 0; j < r; j++)
            if (!senbei[j][i])
                count++;

        on_column[i] = count;
    }

    return on_column;
}

int main()
{

    int ans = 0;
    cin >> r >> c;

    vector<vector<int>> senbei(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> senbei[i][j];
        }
    }

    for (int row_state = 0; row_state < (1 << r); row_state++)
    {
        vector<vector<int>> copy_senbei = senbei;
        for (int i = 0; i < r; i++)
            if (row_state & (1 << i))
            {
                reverse_row(i, copy_senbei);
            }

        // 列ごとに表(０)になってるせんべいの個数を記録
        vector<int> on_column = count_on_column(copy_senbei);

        int count = 0;
        for (int i = 0; i < c; i++)
        {
            if (on_column[i] <= r / 2)
                count += r - on_column[i];
            else
                count += on_column[i];
        }

        ans = max(ans, count);
    }

    cout << ans << endl;

    return 0;
}