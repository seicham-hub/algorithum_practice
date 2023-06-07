// https://atcoder.jp/contests/abc302/tasks/abc302_b
// 実装がDFSと見せかけて普通になる。直線で連続していないといけないので、開始地点からの8方向のみ考えればよい
// 0521もう一度
// 0523もう一度 OK

#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main()
{
    int h, w;
    string s[101], su = "snuke";
    vector<pair<int, int>> ans;

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
                    int suInd = 1, x, y;
                    bool ok = true;
                    while (suInd < 5)
                    {
                        x = i + dx[k] * suInd;
                        y = j + dy[k] * suInd;

                        if (x < 0 || x >= h || y < 0 || y >= w)
                        {
                            ok = false;
                            break;
                        }

                        if (s[x][y] != su[suInd])
                        {
                            ok = false;
                            break;
                        }
                        suInd++;
                    }

                    x = i;
                    y = j;

                    if (ok)
                    {
                        for (int l = 0; l < 5; l++)
                        {
                            ans.push_back({x, y});
                            x = x + dx[k];
                            y = y + dy[k];
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

// int main()
// {

//     int h, w;
//     string s[110], su = "snuke";
//     cin >> h >> w;

//     vector<pair<int, int>> ans;

//     for (int i = 0; i < h; i++)
//     {
//         cin >> s[i];
//     }

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             if (s[i][j] == 's')
//             {

//                 for (int k = 0; k < 8; k++)
//                 {

//                     int x, y;
//                     int sunukeInd = 1;
//                     bool ok = true;
//                     while (sunukeInd < 5)
//                     {
//                         x = i + dx[k] * sunukeInd;
//                         y = j + dy[k] * sunukeInd;

//                         if (x < 0 || x >= h || y < 0 || y >= w)
//                         {
//                             ok = false;
//                             break;
//                         }

//                         if (s[x][y] != su[sunukeInd])
//                         {
//                             ok = false;
//                             break;
//                         }
//                         sunukeInd++;
//                     }

//                     x = i;
//                     y = j;

//                     if (ok)
//                     {
//                         for (int l = 0; l < 5; l++)
//                         {
//                             ans.push_back({x, y});
//                             x = x + dx[k];
//                             y = y + dy[k];
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int h, w;
// int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};
// string su = "snuke";
// string s[110];
// vector<pair<int, int>> ans;

// int main()
// {

//     cin >> h >> w;

//     for (int i = 0; i < h; i++)
//     {
//         cin >> s[i];
//     }

//     for (int i = 0; i < h; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {

//             if (s[i][j] == 's')
//             {

//                 for (int k = 0; k < 8; k++)
//                 {
//                     int suInd = 1;
//                     int x = i, y = j;
//                     bool ok = true;
//                     while (suInd < 5)
//                     {
//                         x = x + dx[k];
//                         y = y + dy[k];
//                         if (x < 0 || x >= h || y < 0 || y >= w || s[x][y] != su[suInd])
//                         {
//                             ok = false;
//                             break;
//                         }
//                         suInd++;
//                     }
//                     if (ok)
//                     {
//                         x = i;
//                         y = j;
//                         for (int l = 0; l < 5; l++)
//                         {
//                             // ans.push_back({x + 1, y + 1});
//                             cout << x + 1 << y + 1 << endl;
//                             x = x + dx[k];
//                             y = y + dy[k];
//                         }
//                     }
//                 }
//             }
//         }
//     }

//     for (int j = 0; j < 5; j++)
//     {
//         cout << ans[j].first << " " << ans[j].second << endl;
//     }

//     return 0;
// }