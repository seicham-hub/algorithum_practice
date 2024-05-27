
// Input 568-379-8466 Output [...,'LOVEPYTHON',...]
// Input 435-569-6753 Output [...,'HELLOWORLD',...]

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> NUM_ALPHABET_MAPPING = {
    {0, "+"},
    {1, "@"},
    {2, "ABC"},
    {3, "DEF"},
    {4, "GHI"},
    {5, "JKL"},
    {6, "MNO"},
    {7, "PQRS"},
    {8, "TUV"},
    {9, "WXYZ"},
};

vector<string> get_candidate(string &text)
{
    vector<string> result;
    vector<int> phone_numbers;

    for (char c : text)
    {
        if ('0' <= c && c <= '9')
            phone_numbers.push_back(c - '0');
    }

    stack<string> st;
    st.push("");

    while (!st.empty())
    {
        string now_str = st.top();
        st.pop();
        int index = now_str.size();

        if (now_str.size() == phone_numbers.size())
            result.push_back(now_str);
        else
        {
            for (char c : NUM_ALPHABET_MAPPING[phone_numbers[index]])
                st.push(now_str + c);
        }
    }

    return result;
}

int main()
{
    string text = "568-379-8466";

    auto ans = get_candidate(text);

    for (string a : ans)
    {
        if (a == "LOVEPYTHON")
        {
            cout << a << endl;
        }
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// map<int, string> NUM_ALPHABET_MAPPING = {
//     {0, "+"},
//     {1, "@"},
//     {2, "ABC"},
//     {3, "DEF"},
//     {4, "GHI"},
//     {5, "JKL"},
//     {6, "MNO"},
//     {7, "PQRS"},
//     {8, "TUV"},
//     {9, "WXYZ"},
// };

// vector<string> get_all_candidate(string &text)
// {

//     vector<int> phone_numbers;

//     for (char c : text)
//     {
//         if ('0' <= c && c <= '9')
//         {
//             phone_numbers.push_back(c - '0');
//         }
//     }

//     vector<string> result;

//     function<void(string, int)> _get_all_candidate = [&](string now_str, int index)
//     {
//         if (now_str.size() == phone_numbers.size())
//         {
//             result.push_back(now_str);
//             return;
//         }

//         int phone_num = phone_numbers[index];

//         for (char candidate : NUM_ALPHABET_MAPPING[phone_num])
//         {
//             string next_str = now_str + candidate;
//             int next_index = index + 1;
//             _get_all_candidate(next_str, next_index);
//         }
//     };

//     _get_all_candidate("", 0);
//     return result;
// }

// vector<string> phone_mnemonic_v2(const string &phone_number)
// {

//     vector<int> phone_number_digits;
//     for (char c : phone_number)
//     {
//         if (isdigit(c))
//         {
//             phone_number_digits.push_back(c - '0');
//         }
//     }

//     vector<string> candidate;
//     stack<string> stack;
//     stack.push("");

//     while (!stack.empty())
//     {
//         string alphabets = stack.top();
//         stack.pop();

//         if (alphabets.size() == phone_number_digits.size())
//         {
//             candidate.push_back(alphabets);
//         }
//         else
//         {
//             int digit = phone_number_digits[alphabets.size()];
//             for (char char_option : NUM_ALPHABET_MAPPING[digit])
//             {
//                 stack.push(alphabets + char_option);
//             }
//         }
//     }

//     return candidate;
// }

// int main()
// {

//     string phone_number = "568-379-8466";
//     // vector<string> ans = get_all_candidate(phone_number);

//     // for (auto a : ans)
//     // {
//     //     if (a == "LOVEPYTHON")
//     //         cout << a << " ,";
//     // }

//     vector<string> mnemonics = phone_mnemonic_v2(phone_number);

//     for (const string &mnemonic : mnemonics)
//     {
//         if (mnemonic == "LOVEPYTHON")
//             cout << mnemonic << endl;
//     }

//     return 0;
// }