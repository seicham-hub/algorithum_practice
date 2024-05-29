// 1729 = Ta(2) = 1**3 + 12**3 = 9**3 + 10**3
// Input 1, 2 => [(1729, [(1,12),(9,10)])]
// Input 2, 2 => [(1729,[(1,12),(9,10)]),(4104,[(2,16),(9,15)])]
// Input 1,3 => [(87539319,[(167,436),(228,423),(255,414)])]

#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <utility> // for std::pair
#include <algorithm>

using namespace std;

vector<pair<int, vector<pair<int, int>>>> taxi_cab_number(int max_results_num, int required_pairs_num = 2)
{
    vector<pair<int, vector<pair<int, int>>>> results;
    int current_number = 1;

    while (results.size() < max_results_num)
    {
        unordered_map<int, vector<pair<int, int>>> pairs;
        int max_param = static_cast<int>(pow(current_number, 1.0 / 3.0)) + 1;

        for (int x = 1; x < max_param; ++x)
        {
            for (int y = x + 1; y < max_param; ++y)
            {
                if (x * x * x + y * y * y == current_number)
                {
                    pairs[current_number].emplace_back(x, y);
                }
            }
        }

        if (pairs[current_number].size() == required_pairs_num)
        {
            results.emplace_back(current_number, pairs[current_number]);
        }

        ++current_number;
    }

    return results;
}

void print_taxi_cab_numbers(const vector<pair<int, vector<pair<int, int>>>> &results)
{
    for (const auto &result : results)
    {
        cout << "Number: " << result.first << " Pairs: ";
        for (const auto &pair : result.second)
        {
            cout << "(" << pair.first << ", " << pair.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    int max_results_num = 1;
    int required_pairs_num = 3;

    vector<pair<int, vector<pair<int, int>>>> results = taxi_cab_number(max_results_num, required_pairs_num);
    print_taxi_cab_numbers(results);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int int_pow(int num, int multiplier)
// {
//     int result = 1;

//     for (int i = 0; i < multiplier; i++)
//     {
//         result *= num;
//     }

//     return result;
// }

// vector<pair<int, vector<pair<int, int>>>> taxi_cab(int count, int pair_count)
// {
//     vector<pair<int, vector<pair<int, int>>>> result;

//     int num = 1;
//     while (true)
//     {
//         vector<pair<int, int>> tmp;
//         for (int i = 1; i <= pow(num, (double)1 / (double)3); i++)
//         {
//             for (int j = i + 1; j <= pow(num, (double)1 / (double)3); j++)
//             {
//                 if (num == int_pow(i, 3) + int_pow(j, 3))
//                     tmp.push_back({i, j});
//             }
//         }

//         if (tmp.size() == pair_count)
//             result.push_back({num, tmp});

//         if (result.size() == count)
//             break;

//         num++;
//     }

//     return result;
// }

// int main()
// {

//     vector<pair<int, vector<pair<int, int>>>> ans = taxi_cab(1, 3);

//     for (auto a : ans)
//     {
//         cout << "[" << a.first << ":";
//         for (auto a2 : a.second)
//         {
//             cout << "(" << a2.first << "," << a2.second << "),";
//         }
//     }

//     return 0;
// }