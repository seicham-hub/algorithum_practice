//
// Input {{1, 2}, {3, 5}, {4, 7}, {5, 3}, {7, 4},{0, 16}}
// Output [(5,3),(7,4)]

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> find_symmetric(vector<pair<int, int>> &pairs)
{
    vector<pair<int, int>> result;

    unordered_map<int, int> cache;

    for (pair<int, int> &int_pair : pairs)
    {
        int first = int_pair.first, second = int_pair.second;
        if (cache.count(second) && cache[second] == first)
            result.push_back({first, second});
        cache[first] = second;
    }

    return result;
}

int main()
{

    vector<pair<int, int>> pairs = {{1, 2}, {3, 5}, {4, 7}, {5, 3}, {7, 4}, {0, 16}};

    auto ans = find_symmetric(pairs);

    for (auto a : ans)
    {
        cout << "{" << a.first << "," << a.second << "} ";
    }

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> get_symmetric_pair(vector<pair<int, int>> num_pairs)
// {

//     unordered_map<int, int> pairMap;

//     vector<pair<int, int>> result;

//     for (auto &np : num_pairs)
//     {
//         int a = np.first;
//         int b = np.second;
//         if (pairMap.count(b) && pairMap[b] == a)
//         {
//             result.push_back(np);
//         }
//         else
//         {
//             pairMap[a] = b;
//         }
//     }

//     return result;
// }

// int main()
// {

//     vector<pair<int, int>> pairs = {{1, 2}, {3, 5}, {4, 7}, {5, 3}, {7, 4}, {0, 452}};

//     vector<pair<int, int>> ans = get_symmetric_pair(pairs);

//     for (auto a : ans)
//     {
//         cout << "{" << a.first << "," << a.second << "}," << endl;
//     }
//     return 0;
// }