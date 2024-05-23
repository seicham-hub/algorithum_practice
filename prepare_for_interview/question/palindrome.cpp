// palindrome
// 回文の時はTrue,そうでないときはFalse (reverse関数は禁止)
// aba → True
// abc → Fals
// 2.Find palindrome
//  abcracecarbda →　cec, aceca,racecar
//  abba

// 2024_05_22もう一度

#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string &text)
{
    if (text.size() < 2)
        return false;

    string reversed;
    for (auto it = text.rbegin(); it != text.rend(); it++)
    {
        reversed += *it;
    }

    return text == reversed;
}

void push_palindrome(int left_edge, int right_edge, string &text, vector<string> &result)
{
    while (0 <= left_edge && right_edge < text.size() && text[left_edge] == text[right_edge])
    {
        result.push_back(string(text.begin() + left_edge, text.begin() + right_edge + 1));
        left_edge--;
        right_edge++;
    }
}

vector<string> find_palindrome(string &text)
{

    vector<string> result;

    for (int i = 0; i < text.size(); i++)
    {
        // abcba
        int left_edge = i - 1;
        int right_edge = i + 1;

        push_palindrome(left_edge, right_edge, text, result);

        // abba
        left_edge = i - 1;
        right_edge = i;
        push_palindrome(left_edge, right_edge, text, result);
    }

    return result;
}

int main()
{

    string text = "abcbacbbc";
    cout << is_palindrome(text) << endl;

    auto ans = find_palindrome(text);

    for (string a : ans)
    {
        cout << a << ",";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool is_palindrome(string &text)
// {
//     if (text.size() <= 1)
//         return false;

//     string reversed;
//     for (auto it = text.rbegin(); it != text.rend(); it++)
//     {
//         reversed += (*it);
//     }

//     return text == reversed;
// }

// void append_palindrome(vector<string> &result, int left_edge, int right_edge, string &text)
// {
//     while (0 <= left_edge && right_edge < text.size())
//     {
//         if (text[left_edge] == text[right_edge])
//         {
//             result.push_back(string(text.begin() + left_edge, text.begin() + right_edge + 1));
//             left_edge--;
//             right_edge++;
//         }
//         else
//             break;
//     }
// }

// vector<string> find_palindrome(string &text)
// {
//     vector<string> result;
//     for (int i = 0; i < text.size(); i++)
//     {
//         int left_edge = i - 1;
//         int right_edge = i + 1;
//         append_palindrome(result, left_edge, right_edge, text);

//         left_edge = i - 1;
//         right_edge = i;
//         append_palindrome(result, left_edge, right_edge, text);
//     }

//     return result;
// }

// int main()
// {

//     string text = "abcracecarbdaabba";

//     vector<string> ans = find_palindrome(text);

//     for (string str : ans)
//     {
//         cout << str << ",";
//     }

//     return 0;
// }