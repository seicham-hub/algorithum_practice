// 問題：{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[
// このようなJSON文字列のブラケットが正しく閉じているか判定

#include <bits/stdc++.h>
using namespace std;

bool validate_format(string letter)
{

    stack<char> st;
    unordered_map<char, char> look_up = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

    for (char c : letter)
    {

        if (look_up[c])
            st.push(look_up[c]);

        for (auto m : look_up)
        {
            if (c == m.second)
            {

                if (st.empty() || st.top() != c)
                    return false;
                else
                    st.pop();
            }
        }
    }
    return st.empty();
}
int main()
{
    // string check_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    string check_str = "{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[";
    cout << validate_format(check_str) << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// bool validate_format(string s)
// {

//     unordered_map<char, char> blacket_pair = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

//     stack<char> st;
//     for (char c : s)
//     {
//         if (blacket_pair.count(c))
//             st.push(blacket_pair[c]);

//         for (auto m : blacket_pair)
//         {
//             if (m.second == c)
//             {
//                 if (st.empty() || st.top() != c)
//                     return false;
//                 st.pop();
//             }
//         }
//     }

//     return st.empty()
// }
// int main()
// {

//     string check_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
//     // string check_str = "{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[";

//     bool ans = validate_format(check_str);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool validate_format(string str)
// {

//     unordered_map<char, char> lookup = {{'{', '}'}, {'(', ')'}, {'[', ']'}};

//     vector<char> stack;

//     for (char c : str)
//     {

//         if (lookup.count(c))
//         {
//             stack.push_back(lookup[c]);
//         }
//         else
//         {

//             if (c == '}' || c == ')' || c == ']')
//             {
//                 if (stack.empty() || stack.back() != c)
//                     return false;

//                 stack.pop_back();
//             }
//         }
//     }

//     return stack.empty();
// }

// int main()
// {

//     // string check_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
//     string check_str = "{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[";

//     bool ans = validate_format(check_str);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool validate_format(string str)
// {
//     unordered_map<char, char> lookup = {{'{', '}'}, {'[', ']'}, {'(', ')'}};
//     stack<char> box;
//     for (char c : str)
//     {
//         if (lookup.count(c))
//         {
//             box.push(lookup[c]);
//         }
//         if (c == '}' || c == ')' || ']')
//         {
//             if (box.empty())
//                 return false;
//             if (box.top() != c)
//             {
//                 return false;
//             }
//             box.pop();
//         }
//     }
//     return true;
// }

// int main()
// {

//     // string check_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
//     string check_str = "{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[";

//     bool ans = validate_format(check_str);

//     cout << ans << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool validate_format(string &str)
// {
//     unordered_map<char, char> lookup = {{'{', '}'}, {'(', ')'}, {'[', ']'}};
//     vector<char> stack;
//     for (char c : str)
//     {

//         if (lookup.count(c))
//         {
//             stack.push_back(lookup[c]);
//         }
//         else
//         {
//             for (auto &p : lookup)
//             {
//                 if (c == p.second)
//                 {
//                     if (stack.empty() || stack.back() != c)
//                         return false;
//                     stack.pop_back();
//                     break;
//                 }
//             }
//         }
//     }
//     return stack.empty();
// }

// int main()
// {

//     string check_str = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
//     // string check_str = "{\"users\": [{\"name\": \"David\", \"age\": 28}, {\"name\": \"Eve\", \"age\": 22}]}[";

//     bool ans = validate_format(check_str);

//     cout << ans << endl;

//     return 0;
// }