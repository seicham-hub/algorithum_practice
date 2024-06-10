// https://atcoder.jp/contests/joi2007ho/tasks/joi2007ho_c

#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int n;
vector<array<pair<int, int>, 2>> candidate;
vector<pair<int, int>> poll;

int main()
{

    cin >> n;

    poll.resize(n);
    set<P> st;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        poll[i] = {x, y};
        st.insert({x, y});
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            pair<int, int> A = poll[i];
            pair<int, int> B = poll[j];

            int x1 = A.first;
            int y1 = A.second;
            int x2 = B.first;
            int y2 = B.second;

            pair<int, int> C = {x1 + y1 - y2, y1 - x1 + x2};
            pair<int, int> D = {x2 + y1 - y2, y2 - x1 + x2};

            if (st.count(C) && st.count(D))
            {
                ans = max(ans, (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
            }
        }
    }

    cout << ans << endl;

    return 0;
}

// 自分で書いたコード（解けなかった）
// 4点全探索→O(n^4)
// 3点決めて計算で座標出す→O(n^3)

// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, array<pair<int, int>, 2>>> sides;
// int n;

// pair<int, array<pair<int, int>, 2>> calc_side(vector<int> selected_ind, vector<pair<int, int>> &poll)
// {
//     int x1 = poll[selected_ind[0]].first;
//     int y1 = poll[selected_ind[0]].second;

//     int x2 = poll[selected_ind[1]].first;
//     int y2 = poll[selected_ind[1]].second;

//     return {(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1), {{{x1, y1}, {x2, y2}}}};
// }

// void candidate_sides(int node, vector<int> selected, vector<pair<int, int>> &poll)
// {

//     if (node > n)
//         return;

//     if (selected.size() == 2)
//     {
//         auto side = calc_side(selected, poll);
//         sides.push_back(side);
//         return;
//     }

//     candidate_sides(node + 1, selected, poll);

//     selected.push_back(node);
//     candidate_sides(node + 1, selected, poll);
// }

// int main()
// {

//     cin >> n;

//     vector<pair<int, int>> poll(n);

//     for (int i = 0; i < n; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         poll[i] = {x, y};
//     }

//     candidate_sides(0, {}, poll);

//     sort(sides.begin(), sides.end());

//     int sid = 0;
//     int count = 0;
//     for (int i = 0; i < sides.size(); i++)
//     {
//         int tmp_side = sides[i].first;
//         array<pair<int, int>, 2> dots = sides[i].second;

//         if (sid != tmp_side)
//         {
//             sid = tmp_side;
//             count =
//         }
//         else
//             count++;
//     }

//     return 0;
// }