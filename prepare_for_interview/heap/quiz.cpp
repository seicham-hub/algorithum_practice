#include <bits/stdc++.h>
using namespace std;

vector<string> w = {"python", "c", "java", "python", "c", "go", "python"};
// 1:python
// 2:go
// 2:c
// 4:java

vector<string> top_n_with_heap(vector<string> words, int n)
{
    unordered_map<string, int> freqMap;
    for (int i = 0; i < words.size(); ++i)
    {
        freqMap[words[i]]++;
    }
    auto compare = [](const pair<string, int> a, pair<string, int> b) -> bool
    {
        return a.second < b.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(compare)>
        heap(compare);

    for (auto m : freqMap)
        heap.push(m);

    vector<string> result;
    int count = 0;
    while (!heap.empty() && n > 0)
    {
        result.push_back(heap.top().first);
        heap.pop();
        n--;
    }

    return result;
}

int main()
{
    vector<string> topWords = top_n_with_heap(w, 3);

    for (const auto &word : topWords)
    {
        cout << word << endl;
    }

    return 0;
}

// int main()
// {
//     priority_queue<int, vector<int>, greater<int>> heap;

//     vector<int> s = {5, 6, 2, 9, 10, 18, 14, 2};

//     for (int i = 0; i < s.size(); ++i)
//         heap.push(s[i]);

//     while (!heap.empty())
//     {
//         cout << heap.top() << endl;
//         heap.pop();
//     }

//     return 0;
// }