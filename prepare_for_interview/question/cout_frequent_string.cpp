// Input "This is a pen. This is an apple. Applepen"
// Output: {'p':6}

#include <bits/stdc++.h>
using namespace std;

pair<char, int> get_most_frequent_char(string letter)
{

    unordered_map<char, int> freqChar;
    for (char &c : letter)
    {
        if (('a' <= c && c <= 'z') || c == '.')
        {
            freqChar[c]++;
        }
    }

    auto compare = [](const pair<char, int> &a, const pair<char, int> &b)
    {
        return a.second < b.second;
    };

    auto result = max_element(freqChar.begin(), freqChar.end(), compare);

    return *result;
}

int main()
{
    string letter = "This is a pen. This is an apple. Applepen.";
    transform(letter.begin(), letter.end(), letter.begin(), ::tolower);

    pair<char, int> ans = get_most_frequent_char(letter);

    cout << ans.first << ":" << ans.second;
    return 0;
}