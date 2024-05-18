#include <bits/stdc++.h>
using namespace std;

const string ALPHABET_LOWER_CASE = "abcdefghijklmnopqrstuvwxyz";
const string ALPHABET_UPPER_CASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string ceazer_ciper(string &text, int shift)
{
    string result;

    for (char c : text)
    {
        if (isupper(c))
        {
            int index = (c - 'A' + shift) % ALPHABET_UPPER_CASE.size();
            result += ALPHABET_UPPER_CASE[index];
        }
        else if (islower(c))
        {
            int index = (c - 'a' + shift) % ALPHABET_LOWER_CASE.size();
            result += ALPHABET_LOWER_CASE[index];
        }
        else
        {
            result += c;
        }
    }

    return result;
}

vector<pair<int, string>> ceazer_ciper_hack(string &text)
{

    vector<pair<int, string>> results;
    for (int candidate_shift = 1; candidate_shift <= ALPHABET_LOWER_CASE.size(); candidate_shift++)
    {

        string reverted;
        for (char c : text)
        {
            if (isupper(c))
            {
                int index = (c - 'A' - candidate_shift + ALPHABET_UPPER_CASE.size()) % ALPHABET_UPPER_CASE.size();
                reverted += ALPHABET_UPPER_CASE[index];
            }
            else if (islower(c))
            {
                int index = (c - 'a' - candidate_shift + ALPHABET_LOWER_CASE.size()) % ALPHABET_LOWER_CASE.size();
                reverted += ALPHABET_LOWER_CASE[index];
            }
            else
            {
                reverted += c;
            }
        }
        results.push_back({candidate_shift, reverted});
    }

    return results;
}

int main()
{
    string text = "ATTACK BY SILICON VALLAY by engineer";
    string encrypted = ceazer_ciper(text, 3);
    vector<pair<int, string>> candidate = ceazer_ciper_hack(encrypted);

    for (auto p : candidate)
    {
        cout << p.first << ": " << p.second << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const string UPPERCASE_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// const string LOWERCASE_ALPHABET = "abcdefghijklmnopqrstuvwxyz";

// string ceasar_cipher(const string &text, int shift)
// {
//     string result;
//     for (char c : text)
//     {
//         if (isupper(c))
//         {
//             result += UPPERCASE_ALPHABET[(c - 'A' + shift) % UPPERCASE_ALPHABET.size()];
//         }
//         else if (islower(c))
//         {
//             result += LOWERCASE_ALPHABET[(c - 'a' + shift) % LOWERCASE_ALPHABET.size()];
//         }
//         else
//         {
//             result += c;
//         }
//     }
//     return result;
// }

// vector<pair<int, string>> ceasar_cipher_hack(string &text)
// {
//     vector<pair<int, string>> results;

//     for (int candidate_shft = 1; candidate_shft <= 26; candidate_shft++)
//     {
//         string reverted;
//         for (char c : text)
//         {
//             if (isupper(c))
//             {
//                 int index = c - 'A' - candidate_shft;
//                 if (index < 0)
//                     index += UPPERCASE_ALPHABET.size();
//                 reverted += UPPERCASE_ALPHABET[index];
//             }
//             else if (islower(c))
//             {
//                 int index = c - 'a' - candidate_shft;
//                 if (index < 0)
//                     index += LOWERCASE_ALPHABET.size();
//                 reverted += LOWERCASE_ALPHABET[index];
//             }
//             else
//             {
//                 reverted += c;
//             }
//         }

//         results.push_back({candidate_shft, reverted});
//     }

//     return results;
// }

// int main()
// {
//     string text = "ATTACK BY SILICON VALLAY by engineer";
//     int shift = 3;

//     string encrypted = ceasar_cipher(text, shift);

//     auto hacked = ceasar_cipher_hack(encrypted);

//     for (const auto &pair : hacked)
//     {
//         cout << pair.first << ": " << pair.second << endl;
//     }

//     return 0;
// }

// 自分のコード
// #include <bits/stdc++.h>
// using namespace std;

// string alphabet = "";

// string encrypt(string letter, int shift)
// {

//     string encrypted = "";
//     for (char c : letter)
//     {
//         if ('A' <= c && c <= 'Z')
//             encrypted += ((c - 'A') + shift) % alphabet.size() + 'A';
//         else
//             encrypted += c;
//     }

//     return encrypted;
// }

// vector<string> &cezer_ciper_hack(string encrypted)
// {
//     vector<string> reverted;

//     for (int candidate_shift = 1; candidate_shift < alphabet.size(); candidate_shift++)
//     {
//         string result = "";
//         for (char c : encrypted)
//         {
//             if ('A' <= c && c <= 'Z')
//             {
//                 cout << (c - 'A') - candidate_shift + alphabet.size() << endl;
//                 result += ((c - 'A') - candidate_shift + alphabet.size()) % alphabet.size() + 'A';
//             }
//             else
//                 result += c;
//         }
//         reverted.push_back(result);
//     }

//     return reverted;
// }

// int main()
// {
//     for (char c = 'A'; c <= 'Z'; c++)
//         alphabet += c;

//     string letter = "ATTACK TO SILICON VALLAY ZZZZ AAA";
//     string encrypted = encrypt(letter, 4);

//     auto decrypted = cezer_ciper_hack(encrypted);

//     for (string a : decrypted)
//     {
//         cout << a << endl;
//     }

//     return 0;
// }