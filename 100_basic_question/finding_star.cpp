// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_d

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main()
{
    int m;
    cin >> m;

    vector<P> stars;
    set<P> picture;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        stars.push_back({x, y});
    }
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        picture.insert({x, y});
    }

    vector<P> candidate_dxdy;

    for (auto p : picture)
    {
        candidate_dxdy.push_back({p.first - stars[0].first, p.second - stars[0].second});
    }

    for (P dxdy : candidate_dxdy)
    {
        bool ok = true;
        for (P star : stars)
        {
            if (!picture.count({star.first + dxdy.first, star.second + dxdy.second}))
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            cout << dxdy.first << " " << dxdy.second << endl;
            return 0;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using P = pair<int, int>;

// int main()
// {
//     int m;
//     cin >> m;

//     vector<P> stars;
//     set<P> picture;

//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         stars.push_back({x, y});
//     }
//     sort(stars.begin(), stars.end());

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         picture.insert({x, y});
//     }

//     vector<P> dxdy;

//     for (auto p : picture)
//     {
//         int dx = p.first - stars[0].first;
//         int dy = p.second - stars[0].second;

//         dxdy.push_back({dx, dy});
//     }

//     for (auto dd : dxdy)
//     {
//         bool ok = true;
//         for (auto star : stars)
//         {
//             if (!picture.count({star.first + dd.first, star.second + dd.second}))
//             {
//                 ok = false;
//                 break;
//             }
//         }

//         if (ok)
//         {
//             cout << dd.first << " " << dd.second << endl;
//             return 0;
//         }
//     }

//     return 0;
// }

// 自分で書いたコード
// 合格だけど解説のほうが分かりやすいかも

// #include <bits/stdc++.h>
// using namespace std;

// using P = pair<int, int>;

// int main()
// {
//     int m;
//     cin >> m;

//     vector<P> stars;
//     set<P> picture;

//     vector<int> ans(2);

//     for (int i = 0; i < m; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         stars.push_back({x, y});
//     }
//     sort(stars.begin(), stars.end());

//     int n;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         picture.insert({x, y});
//     }

//     for (auto p : picture)
//     {
//         int startx = p.first;
//         int starty = p.second;

//         bool ok = true;
//         for (int i = 0; i < m - 1; i++)
//         {
//             int dx = stars[i + 1].first - stars[i].first;
//             int dy = stars[i + 1].second - stars[i].second;

//             if (!picture.count({startx + dx, starty + dy}))
//             {
//                 ok = false;
//                 break;
//             }

//             startx += dx;
//             starty += dy;
//         }

//         if (ok)
//         {
//             ans[0] = startx - stars.back().first;
//             ans[1] = starty - stars.back().second;
//         }
//     }

//     cout << ans[0] << " " << ans[1] << endl;

//     return 0;
// }