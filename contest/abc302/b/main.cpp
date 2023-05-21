// https://atcoder.jp/contests/abc302/tasks/abc302_b
// 実装がDFSと見せかけて普通になる。直線で連続していないといけないので、開始地点からの8方向のみ考えればよい
// 0521もう一度

#include <bits/stdc++.h>
using namespace std;

int h, w;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
string su = "snuke";
string s[110];
vector<pair<int, int>> ans;

int main()
{

    cin >> h >> w;

    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            if (s[i][j] == 's')
            {

                for (int k = 0; k < 8; k++)
                {
                    int suInd = 1;
                    int x = i, y = j;
                    bool ok = true;
                    while (suInd < 5)
                    {
                        x = x + dx[k];
                        y = y + dy[k];
                        if (x < 0 || x >= h || y < 0 || y >= w || s[x][y] != su[suInd])
                        {
                            ok = false;
                            break;
                        }
                        suInd++;
                    }
                    if (ok)
                    {
                        x = i;
                        y = j;
                        for (int l = 0; l < 5; l++)
                        {
                            // ans.push_back({x + 1, y + 1});
                            cout << x + 1 << y + 1 << endl;
                            x = x + dx[k];
                            y = y + dy[k];
                        }
                    }
                }
            }
        }
    }

    for (int j = 0; j < 5; j++)
    {
        cout << ans[j].first << " " << ans[j].second << endl;
    }

    return 0;
}