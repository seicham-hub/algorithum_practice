
// Generate Prime Numbers

// Input 50 → OutPut:[2,3,5,7,11,13,17,19,23,29,31,37,41,43,47]
#include <bits/stdc++.h>
using namespace std;

vector<int> get_prime_numbers(int num)
{

    vector<int> result;

    for (int i = 2; i <= num; i++)
        result.push_back(i);

    for (int i = 0; i < result.size(); i++)
    {
        int j = 2;
        if (result[i] == -1)
            continue;
        while (result[i] * j <= num)
        {
            int index = result[i] * j - 2;
            result[index] = -1;
            j++;
        }
    }

    int i = 0;
    while (i < result.size())
        if (result[i] == -1)
            result.erase(result.begin() + i);
        else
            i++;

    return result;
}

vector<int> get_prime_numbers_v2(int num)
{
    unordered_map<int, bool> cache;
    vector<int> result;

    for (int i = 2; i <= num; i++)
    {

        if (cache[i] == true)
            continue;

        result.push_back(i);
        cache[i] = true;

        for (int j = 2; j * i <= num; j++)
        {
            cache[j * i] = true;
        }
    }

    return result;
}

int main()
{

    auto ans = get_prime_numbers_v2(50);

    for (int a : ans)
        cout << a << " ";

    return 0;
}