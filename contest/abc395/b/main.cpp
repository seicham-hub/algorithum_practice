#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using P = pair<int, int>;

int main()
{

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector(n, '#'));

    auto paint = [&](int ii, int jj)
    {
        int i = ii - 1;
        int j = jj - 1;

        int cnt = j - i + 1;

        rep(k, cnt)
        {
            rep(l, cnt)
            {
                if (ii % 2 == 1)
                    grid[k + i][j - l] = '#';
                else
                    grid[k + i][j - l] = '.';
            }
        }
    };

    rep(i, n)
    {
        int ii = i + 1;
        int jj = n + 1 - ii;

        if (ii <= jj)
        {
            paint(ii, jj);
        }
    }

    rep(i, n)
    {
        rep(j, n)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}