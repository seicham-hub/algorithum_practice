// https://atcoder.jp/contests/pakencamp-2019-day3/tasks/pakencamp_2019_day3_c

// 解説見て書いたコード
// わざわざDFSしなくてよい

#include <bits/stdc++.h>
using namespace std;

long long calc_total_score(int first, int second, vector<vector<int>> &A)
{
    long long result = 0;

    for (auto a : A)
    {
        result += max(a[first], a[second]);
    }

    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }

    long long ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            long long total_score = calc_total_score(i, j, A);
            ans = max(ans, total_score);
        }
    }

    cout << ans << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int n, m;

// vector<pair<int, int>> music;

// void candidate_music_pair(int ind, vector<int> taken)
// {

//     if (taken.size() == 2)
//     {
//         music.push_back({taken[0], taken[1]});
//         return;
//     }
//     if (ind >= m)
//         return;

//     candidate_music_pair(ind + 1, taken);
//     taken.push_back(ind);
//     candidate_music_pair(ind + 1, taken);
// }

// int main()
// {

//     cin >> n >> m;
//     vector<vector<int>> A(n, vector<int>(m));

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//             cin >> A[i][j];
//     }
//     candidate_music_pair(0, {});

//     vector<pair<int, int>> ms = music;

//     long long ans = 0;
//     for (auto mus : music)
//     {
//         int first = mus.first;
//         int second = mus.second;

//         long long point = 0;
//         for (int i = 0; i < n; i++)
//         {
//             point += max(A[i][first], A[i][second]);
//         }

//         ans = max(ans, point);
//     }

//     cout << ans << endl;

//     return 0;
// }