// https://atcoder.jp/contests/abc314/tasks/abc314_d
// 毎回forで回してたら終わらない..→最後にまとめてできないか？
// 0822もう一度
// 0825もう一度

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main()
{
    int n, q;
    string s;

    cin >> n >> s >> q;

    vector<pair<int, char>> personal(n); // personal[sの何文字目か] = {時刻,変更後の文字}

    rep(i, n) personal[i] = {0, s[i]};

    pair<int, int> full = {-100, 5}; // {時刻、大文字か小文字か(2,3)}

    rep(i, q)
    {

        int t, x;
        char c;
        cin >> t >> x >> c;

        if (t == 1)
            personal[x - 1] = {i, c};
        else if (t == 2)
            full = {i, t};
        else
            full = {i, t};
    }

    for (auto p : personal)
    {
        int time = p.first;
        char mozi = p.second;

        int ftime = full.first;
        int to = full.second;

        if (ftime < time)
            cout << mozi;
        else if (to == 2)
            cout << (char)tolower(mozi);
        else
            cout << (char)toupper(mozi);
    }
    cout << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {

//     int N;
//     string S;
//     cin >> N >> S;

//     vector<pair<int, char>> status(N); // 個別の操作（最終変更時間、現在の文字)

//     rep(i, N)
//     {
//         status[i] = {0, S[i]};
//     }

//     int Q;
//     cin >> Q;

//     optional<pair<int, int>> fill = nullopt; // 全体に対する操作（最終変更時間、最後の変更のタイプ）

//     rep(i, Q)
//     {
//         int t, x;
//         char c;

//         cin >> t >> x >> c;
//         if (t == 1)
//             status[x - 1] = {i, c};
//         else
//             fill = {i, t};
//     }

//     for (const auto &[time, c] : status)
//     {
//         if (!fill || time >= fill->first)
//             cout << c;
//         else if (fill->second == 2)
//             cout << static_cast<char>(tolower(c));
//         else
//             cout << static_cast<char>(toupper(c));
//     }

//     cout << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, q;
//     string s;
//     cin >> n >> s >> q;

//     vector<pair<char, int>> exchange(n + 1);

//     rep(i, s.size())
//     {
//         exchange[i] = {s[i], 0};
//     }

//     // この位置で全部文字変換
//     pair<int, char> changeCase = {-100, 'd'};

//     rep(i, q)
//     {
//         int t, x;
//         char c;
//         cin >> t >> x >> c;
//         x--;

//         if (t == 1)
//         {
//             exchange[x] = {c, i};
//         }
//         else if (t == 2)
//         {
//             changeCase = {i, 'l'};
//         }
//         else if (t == 3)
//         {
//             changeCase = {i, 'u'};
//         }
//     }

//     string ans = "";

//     rep(i, s.size())
//     {
//         if (changeCase.first < exchange[i].second)
//         {
//             ans += exchange[i].first;
//         }
//         else
//         {
//             if (changeCase.second == 'l')
//                 ans += tolower(exchange[i].first);
//             else
//                 ans += toupper(exchange[i].first);
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }

/*
自分の解答
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int main()
// {
//     int n, q;
//     string s;

//     cin >> n >> s >> q;

//     map<int, char> Chapital;
//     map<int, char> mini;

//     rep(i, n)
//     {
//         if ('A' <= s[i] && s[i] <= 'Z')
//             Chapital[i] = s[i] + 'a' - 'A';
//         else
//             mini[i] = s[i];
//     }

//     rep(i, q)
//     {
//         int t, x;
//         char c;
//         cin >> t >> x >> c;

//         x--;

//         switch (t)
//         {
//         case 1:
//             if (Chapital[x])
//                 Chapital[x] = c;
//             else if (mini[x])
//                 mini[x] = c;

//             break;
//         case 2:
//             mini.insert(Chapital.begin(), Chapital.end());
//             Chapital.clear();
//             break;
//         case 3:
//             Chapital.insert(mini.begin(), mini.end());
//             mini.clear();
//         }
//     }

//     string ans = "";

//     rep(i, n)
//     {
//         if (Chapital[i])
//         {
//             ans += Chapital[i] + 'A' - 'a';
//         }
//         else if (mini[i])
//         {
//             ans += mini[i];
//         }
//     }

//     cout << ans << endl;

//     return 0;
// }