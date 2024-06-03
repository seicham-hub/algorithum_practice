// 暗号化する文字 SILLICON VALLAYをkeyを使って暗号化
// keyは暗号化する文字と同じ長さで特定の文字が繰り返される（CATCATCAT等）
// 暗号化する際はkeyのインデックス分アルファベットをずらす

#include <bits/stdc++.h>
using namespace std;

const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string generate_key(string &source_key, string &text)
{
    string result;
    if (source_key.size() == 0)
        return result;

    for (int i = 0; i < text.size(); i++)
    {
        if ('A' <= text[i] && text[i] <= 'Z')
            result += source_key[i % source_key.size()];
        else
            result += text[i];
    }

    return result;
}

string enctypt(string &text, string &key)
{
    string result;
    for (int i = 0; i < text.size(); i++)
    {
        if ('A' <= text[i] && text[i] <= 'Z')
        {
            int index = (alphabet.find(text[i]) + alphabet.find(key[i])) % alphabet.size();
            result += alphabet[index];
        }
        else
            result += text[i];
    }

    return result;
}

string decrypt(string &text, string &key)
{
    string result;
    for (int i = 0; i < text.size(); i++)
    {
        if ('A' <= text[i] && text[i] <= 'Z')
        {
            int index = (alphabet.find(text[i]) - alphabet.find(key[i]) + alphabet.size()) % alphabet.size();
            result += alphabet[index];
        }
        else
            result += text[i];
    }

    return result;
}

int main()
{

    string text = "SILLYCON VALLAY";
    string source_key = "CAT";
    string key = generate_key(source_key, text);

    string encrypted = enctypt(text, key);
    string decrypted = decrypt(encrypted, key);

    return 0;
}