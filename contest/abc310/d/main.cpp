// https://atcoder.jp/contests/abc310/tasks/abc310_d
// チームに分ける方法が分からなかった... →全部分けてみて、チーム数が園可錫なるときを考えればよい
// reserveが必要な理由が分からない..
// 0718もう一度
// 0725もう一度

/*
7/19やり直し分
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

int n, t, m, ans = 0;
vector<int> team;
map<int, int> hate;

void dfs(int now)
{

    if (team.size() == t && now == n)
    {
        ans++;
        return;
    }

    if (now > n - 1)
        return;

    rep(i, team.size())
    {
        if (!(team[i] & hate[now]))
        {
            team[i] |= 1 << now;
            dfs(now + 1);
            team[i] ^= 1 << now;
        }
    }

    if (team.size() < t)
    {
        team.emplace_back(1 << now);
        dfs(now + 1);
        team.pop_back();
    }
}

int main()
{

    cin >> n >> t >> m;

    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        hate[--a] |= 1 << --b;
        hate[b] |= 1 << a;
    }

    dfs(0);

    cout << ans << endl;

    return 0;
}

/*
解答のコード
*/

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; ++i)

// int n, t, m;
// vector<int> hate, teams;

// int dfs(int now)
// {
//     if (now == n)
//         return teams.size() == t;

//     int ans = 0;

//     for (auto &&team : teams)
//     {
//         // チームにnow番目の選手と相性の悪い選手がいなければ
//         if (!(team & hate[now]))
//         {
//             team |= 1 << now;
//             ans += dfs(now + 1);
//             team ^= 1 << now;
//         }
//     }

//     // チーム数に余裕があるとき、新しいチームを作る
//     if (teams.size() < t)
//     {
//         teams.emplace_back(1 << now);
//         ans += dfs(now + 1);
//         teams.pop_back();
//     }

//     return ans;
// }

// int main()
// {
//     cin >> n >> t >> m;

//     hate.resize(n);
//     rep(i, m)
//     {
//         int a, b;
//         cin >> a >> b;
//         hate[--b] |= 1 << --a;
//     }

//     teams.reserve(t);
//     cout << dfs(0) << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// unsigned N, T, M;
// vector<unsigned> hate, teams;

// // 再帰関数でチーム分け
// unsigned dfs(unsigned now)
// {
//     // 最後の選手まで見て T チームに分かれていれば OK
//     if (now == N)
//         return teams.size() == T;

//     unsigned ans{};

//     // すでにあるチームに now 番目の選手を追加する
//     for (auto &&team : teams)
//         // チームに now 番目の選手と相性の悪い選手がいなければ
//         if (!(team & hate[now]))
//         {
//             team ^= 1U << now;
//             ans += dfs(now + 1);
//             team ^= 1U << now;
//         }

//     // チーム数に余裕があるとき、新しいチームを作る
//     if (teams.size() < T)
//     {
//         teams.emplace_back(1U << now);
//         ans += dfs(now + 1);
//         teams.pop_back();
//     }

//     return ans;
// }

// int main()
// {
//     using namespace std;
//     cin >> N >> T >> M;

//     // hate[i] の j ビットめが 1 ⟹ i 番目の選手と j 番目の選手の相性が悪い (0-indexed)
//     hate = vector<unsigned>(N);
//     for (unsigned i{}, a, b; i < M; ++i)
//     {
//         cin >> a >> b;
//         hate[--b] |= 1U << --a;
//     }

//     // teams.reserve(T);
//     cout << dfs(0) << endl;

//     return 0;
// }
