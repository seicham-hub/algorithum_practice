// https://atcoder.jp/contests/abc380/tasks/abc380_c
// 見通しが悪く時間かかった

// 2024_11_21もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<pair<char, int>> rle;

    for (char &c : s)
    {
        if (rle.size() && rle.back().first == c)
        {
            rle.back().second++;
        }
        else
        {
            rle.emplace_back(c, 1);
        }
    }

    int cnt = 0;
    int swapInd = 0;
    rep(i, rle.size())
    {
        if (rle[i].first == '1')
            cnt++;
        if (cnt == k)
        {
            swapInd = i;
            break;
        }
    }

    swap(rle[swapInd - 1], rle[swapInd]);

    for (auto &r : rle)
    {
        rep(i, r.second) cout << r.first;
    }
    cout << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     string s;
//     cin >> s;

//     vector<pair<char, int>> rle;

//     for (char &c : s)
//     {
//         if (rle.size() && rle.back().first == c)
//         {
//             rle.back().second++;
//         }
//         else
//         {
//             rle.push_back({c, 1});
//         }
//     }

//     int oneCnt = 0;
//     int swapInd = 0;
//     rep(i, rle.size())
//     {
//         if (rle[i].first == '1')
//             oneCnt++;
//         if (oneCnt == k)
//         {
//             swapInd = i;
//             break;
//         }
//     }

//     swap(rle[swapInd - 1], rle[swapInd]);

//     for (auto &ri : rle)
//     {
//         rep(i, ri.second)
//         {
//             cout << ri.first;
//         }
//     }

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;

//     vector<pair<char, int>> rle;
//     rep(i, n)
//     {
//         char now;
//         cin >> now;
//         if (rle.size() && rle.back().first == now)
//             rle.back().second++;
//         else
//             rle.push_back({now, 1});
//     }

//     int one = 0;
//     rep(i, rle.size())
//     {
//         if (rle[i].first == '1')
//         {
//             one++;
//             if (one == k)
//             {
//                 swap(rle[i], rle[i - 1]);
//             }
//         }
//     }

//     string ans;

//     for (auto [c, len] : rle)
//     {
//         rep(i, len) ans += c;
//     }

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     string s;

//     cin >> s;

//     int cnt = 0;
//     int bend = 0, abegin = 0, aend = 0;
//     rep(i, s.size())
//     {

//         if (s[i] == '1')
//             cnt++;
//         if (!abegin && cnt == k)
//             abegin = i;
//         while (s[i] == '1')
//         {
//             i++;
//         }
//         if (!bend && cnt == k - 1)
//             bend = i;
//         if (!aend && cnt == k)
//             aend = i;
//     }

//     string mae = s.substr(0, bend);
//     string insert = s.substr(abegin, aend - abegin);
//     string usi = s.substr(bend, abegin - bend) + s.substr(aend);

//     cout << mae + insert + usi << endl;

//     return 0;
// }