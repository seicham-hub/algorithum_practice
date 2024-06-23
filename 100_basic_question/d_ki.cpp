// https://atcoder.jp/contests/abc138/tasks/abc138_d
// わからなかった

// 2024_06_22もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, q;
//     cin >> n >> q;

//     vector<int> counter(n, 0);

//     vector<vector<int>> graph(n);

//     for (int i = 0; i < n - 1; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         a--;
//         b--;
//         graph[a].push_back(b);
//     }

//     vector<pair<int, int>> operation(q);

//     for (int i = 0; i < q; i++)
//     {
//         int p, x;
//         cin >> p >> x;
//         p--;
//         operation[i] = {p, x};
//     }

//     vector<vector<int>> part(n);

//     function<void(int, int)> dfs = [&](int parent, int node)
//     {
//         part[parent].push_back(node);
//         for (int next : graph[node])
//         {
//             dfs(parent, next);
//         }
//     };

//     for (int i = 0; i < n; i++)
//         dfs(i, i);

//     for (auto op : operation)
//     {
//         int node = op.first;
//         int plus = op.second;

//         for (int child : part[node])
//         {
//             counter[child] += plus;
//         }
//     }

//     for (int i = 0; i < counter.size(); i++)
//     {

//         if (i != counter.size() - 1)
//             cout << counter[i] << " ";
//         else
//             cout << counter[i] << endl;
//     }

//     return 0;
// }
