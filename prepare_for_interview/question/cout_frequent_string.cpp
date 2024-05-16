// Input "This is a pen. This is an apple. Applepen"
// 大文字はすべて小文字に変換してカウントしろ
// Output: {'p':6}

#include <bits/stdc++.h>
using namespace std;

pair<char, int> count_frequent_char(string letter)
{

    unordered_map<char, int> char_count;
    for (char c : letter)
    {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
            char_count[c]++;
    }

    auto compare = [](const pair<char, int> &a, const pair<char, int> &b)
    {
        return a.second < b.second;
    };

    // max_elementの計算量はO(n) イテレータを返す
    auto result = max_element(char_count.begin(), char_count.end(), compare);
    return *result;
}

int main()
{
    string letter = "This is a pen. This is an apple. Applepen.";
    // 第三引数はコピー先のイテレータの先頭
    transform(letter.begin(), letter.end(), letter.begin(), ::tolower);
    pair<char, int> ans = count_frequent_char(letter);

    cout << ans.first << "," << ans.second << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// pair<char, int> get_most_frequent_char(string letter)
// {

//     unordered_map<char, int> freqChar;
//     for (char &c : letter)
//     {
//         if (('a' <= c && c <= 'z') || c == '.')
//         {
//             freqChar[c]++;
//         }
//     }

//     auto compare = [](const pair<char, int> &a, const pair<char, int> &b)
//     {
//         return a.second < b.second;
//     };

//     auto result = max_element(freqChar.begin(), freqChar.end(), compare);

//     return *result;
// }

// int main()
// {
//     string letter = "This is a pen. This is an apple. Applepen.";
//     transform(letter.begin(), letter.end(), letter.begin(), ::tolower);

//     pair<char, int> ans = get_most_frequent_char(letter);

//     cout << ans.first << ":" << ans.second;
//     return 0;
// }