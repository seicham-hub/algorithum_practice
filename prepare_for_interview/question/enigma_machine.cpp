// 2024_05_17もう一度

#include <bits/stdc++.h>
using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string get_random_alphabet()
{

    string random_alphabet = ALPHABET;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> rand(0, 25);

    for (int i = 0; i < ALPHABET.size(); i++)
    {
        int j = rand(mt);
        int k = rand(mt);
        swap(random_alphabet[j], random_alphabet[k]);
    }

    return random_alphabet;
}

string get_random_alphabet_shuffled_once()
{
    string random_alphabet = ALPHABET;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> rand(0, 25);

    unordered_map<char, bool> cache;

    for (int i = 0; i < ALPHABET.size(); i++)
    {
        int j = rand(mt);
        int k = rand(mt);

        if (!cache[j] && !cache[k])
            swap(random_alphabet[j], random_alphabet[k]);

        cache[j] = true;
        cache[k] = true;
    }

    return random_alphabet;
}

class PlugBoard
{
public:
    unordered_map<char, char> forward_map;
    unordered_map<char, char> backward_map;
    string alphabet = ALPHABET;

    PlugBoard()
    {
        string random_alphabet = get_random_alphabet();
        for (int i = 0; i < ALPHABET.size(); i++)
        {
            forward_map[ALPHABET[i]] = random_alphabet[i];
            backward_map[random_alphabet[i]] = ALPHABET[i];
        }
    }

    int forward(int index)
    {
        char c = this->alphabet[index];
        c = forward_map[c];
        return this->alphabet.find(c);
    }
    int backward(int index)
    {
        char c = this->alphabet[index];
        c = backward_map[c];
        return this->alphabet.find(c);
    }
};

class Rotor : public PlugBoard
{
public:
    int offset;
    int rotations;

    Rotor(int offset = 1) : PlugBoard()
    {

        this->offset = offset;
        this->rotations = 0;
    }

    int rotate()
    {
        std::rotate(this->alphabet.begin(), this->alphabet.begin() + offset, this->alphabet.end());
        rotations += offset;

        return rotations;
    }
    void reset()
    {
        this->alphabet = ALPHABET;
        rotations = 0;
    }
};

class Reflector
{
public:
    unordered_map<char, char> map;
    Reflector()
    {
        string random_alphabet = get_random_alphabet_shuffled_once();

        for (int i = 0; i < ALPHABET.size(); i++)
        {
            map[ALPHABET[i]] = random_alphabet[i];
        }
    }

    int reflect(int index)
    {

        char c = map[ALPHABET[index]];
        return ALPHABET.find(c);
    }
};

class EnigmaMachine
{
public:
    PlugBoard plg;
    vector<Rotor> rotors;
    Reflector reflector;

    EnigmaMachine(const PlugBoard &plg, const vector<Rotor> &rotors, const Reflector &reflector) : plg(plg), rotors(rotors), reflector(reflector){};

    string encrypt(const string &text)
    {

        string result;

        for (char c : text)
        {

            if ('A' <= c && c <= 'Z')
                result += go_through(c);
            else
                result += c;
        }

        return result;
    }

    string decrypt(const string &text)
    {
        for (auto &rotor : rotors)
        {
            rotor.reset();
        }

        return encrypt(text);
    }

    char go_through(char c)
    {

        int index_num = plg.forward(ALPHABET.find(c));

        for (auto &rotor : rotors)
        {
            index_num = rotor.forward(index_num);
        }

        index_num = reflector.reflect(index_num);

        for (auto it = rotors.rbegin(); it != rotors.rend(); it++)
        {
            index_num = it->backward(index_num);
        }

        index_num = plg.backward(index_num);

        for (auto it = rotors.rbegin(); it != rotors.rend(); it++)
        {
            if (it->rotate() % ALPHABET.size() != 0)
                break;
        }

        return ALPHABET[index_num];
    }
};

int main()
{

    PlugBoard plg = PlugBoard();
    Rotor r1 = Rotor(1);
    Rotor r2 = Rotor(2);
    Rotor r3 = Rotor(3);
    Reflector ref = Reflector();

    EnigmaMachine machine = EnigmaMachine(plg, {r1, r2, r3}, ref);

    string s = "KONNICHIWA BOKU SEICHAM DESU";
    string encrypted = machine.encrypt(s);
    string decrypted = machine.decrypt(encrypted);

    cout << "Original: " << s << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// string get_random_alphabet()
// {
//     string result = ALPHABET;

//     random_device rd;
//     mt19937 mt(rd());
//     uniform_int_distribution<int> rand(0, 25);

//     for (int i = 0; i < result.size(); i++)
//     {
//         int k = rand(mt);
//         int j = rand(mt);

//         swap(result[k], result[j]);
//     }

//     return result;
// }
// string get_swap_alphabet()
// {
//     string result = ALPHABET;

//     random_device rd;
//     mt19937 mt(rd());
//     uniform_int_distribution<int> rand(0, 25);

//     unordered_map<int, bool> cache;

//     for (int i = 0; i < result.size(); i++)
//     {
//         int k = rand(mt);
//         int j = rand(mt);

//         if (!cache[k] && !cache[j])
//             swap(result[k], result[j]);

//         cache[k] = true;
//         cache[j] = true;
//     }

//     return result;
// }

// class PlugBoard
// {
// public:
//     string alphabet = ALPHABET;
//     unordered_map<char, char> forward_map, backward_map;

//     PlugBoard()
//     {
//         string random_alphabet = get_random_alphabet();
//         for (int i = 0; i < ALPHABET.size(); i++)
//         {
//             forward_map[ALPHABET[i]] = random_alphabet[i];
//             backward_map[random_alphabet[i]] = ALPHABET[i];
//         }
//     };
//     int forward(int alphabet_index)
//     {
//         char c = alphabet[alphabet_index];
//         char mapped_char = forward_map[c];
//         return alphabet.find(mapped_char);
//     }
//     int backward(int alphabet_index)
//     {
//         char c = alphabet[alphabet_index];
//         char mapped_char = backward_map[c];
//         return alphabet.find(mapped_char);
//     }
// };

// class Rotor : public PlugBoard
// {
// public:
//     int offset;
//     int rotations;

//     Rotor(int offset = 0)
//     {
//         PlugBoard();
//         this->offset = offset;
//         rotations = 0;
//     }

//     int rotate(int offset = 0)
//     {
//         if (offset == 0)
//             offset = this->offset;
//         std::rotate(alphabet.begin(), alphabet.begin() + offset, alphabet.end());
//         rotations += offset;
//         return rotations;
//     }

//     void reset()
//     {
//         rotations = 0;
//         alphabet = ALPHABET;
//     }
// };

// class Reflector
// {
// public:
//     unordered_map<char, char> mp;
//     Reflector()
//     {

//         string swapped_alphabet = get_swap_alphabet();
//         for (int i = 0; i < ALPHABET.size(); i++)
//         {
//             mp[ALPHABET[i]] = swapped_alphabet[i];
//         }
//     }

//     int reflect(int index_num)
//     {
//         char reflected_char = mp[(ALPHABET[index_num])];
//         return ALPHABET.find(reflected_char);
//     }
// };

// class EnigmaMachine
// {
// public:
//     PlugBoard plug_board;
//     vector<Rotor> rotors;
//     Reflector reflector;

//     EnigmaMachine(const PlugBoard &plug_board, const vector<Rotor> &rotors, const Reflector &reflector)
//         : plug_board(plug_board), rotors(rotors), reflector(reflector){};

//     string encrypt(const string &text)
//     {
//         string result;
//         for (char c : text)
//         {
//             result += go_through(c);
//         }

//         return result;
//     }

//     string decrypt(const string &text)
//     {

//         for (auto &rotor : rotors)
//             rotor.reset();

//         return encrypt(text);
//     }

//     char go_through(char c)
//     {

//         if (!('A' <= c && c <= 'Z'))
//             return c;

//         int index_num = ALPHABET.find(c);
//         index_num = plug_board.forward(index_num);

//         for (auto &rotor : rotors)
//         {
//             index_num = rotor.forward(index_num);
//         }

//         index_num = reflector.reflect(index_num);

//         for (auto it = rotors.rbegin(); it != rotors.rend(); it++)
//         {
//             index_num = it->backward(index_num);
//         }

//         index_num = plug_board.backward(index_num);

//         for (auto it = rotors.rbegin(); it != rotors.rend(); it++)
//         {
//             if (it->rotate() % ALPHABET.size() != 0)
//                 break;
//         }

//         return ALPHABET[index_num];
//     }
// };

// int main()
// {

//     PlugBoard plg = PlugBoard();
//     Rotor r1 = Rotor(3);
//     Rotor r2 = Rotor(2);
//     Rotor r3 = Rotor(1);
//     Reflector reflector = Reflector();

//     EnigmaMachine machine = EnigmaMachine(plg, {r1, r2, r3}, reflector);

//     string s = "ATTACK SILICON VALLEY";
//     string e = machine.encrypt(s);

//     string d = machine.decrypt(e);

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <algorithm>
// #include <random>
// #include <string>

// const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// class PlugBoard
// {
// public:
//     PlugBoard(const std::string &map_alphabet)
//     {
//         mapping(map_alphabet);
//     }

//     void mapping(const std::string &map_alphabet)
//     {
//         for (size_t i = 0; i < ALPHABET.size(); ++i)
//         {
//             forward_map[ALPHABET[i]] = map_alphabet[i];
//             backward_map[map_alphabet[i]] = ALPHABET[i];
//         }
//     }

//     int forward(int index_num) const
//     {
//         char char_forward = forward_map.at(ALPHABET[index_num]);
//         return ALPHABET.find(char_forward);
//     }

//     int backward(int index_num) const
//     {
//         char char_backward = backward_map.at(ALPHABET[index_num]);
//         return ALPHABET.find(char_backward);
//     }

// private:
//     std::unordered_map<char, char> forward_map;
//     std::unordered_map<char, char> backward_map;
// };

// class Rotor : public PlugBoard
// {
// public:
//     Rotor(const std::string &map_alphabet, int offset = 0) : PlugBoard(map_alphabet), offset(offset), rotations(0)
//     {
//         rotate(offset);
//     }

//     int rotate(int offset = 0)
//     {
//         if (offset == 0)
//             offset = this->offset;
//         std::rotate(alphabet.begin(), alphabet.begin() + offset, alphabet.end());
//         rotations += offset;
//         return rotations;
//     }

//     void reset()
//     {
//         rotations = 0;
//         alphabet = ALPHABET;
//     }

// private:
//     int offset;
//     int rotations;
//     std::string alphabet = ALPHABET;
// };

// class Reflector
// {
// public:
//     Reflector(const std::string &map_alphabet)
//     {
//         for (size_t i = 0; i < ALPHABET.size(); ++i)
//         {
//             map[ALPHABET[i]] = map_alphabet[i];
//         }
//         for (size_t i = 0; i < ALPHABET.size(); ++i)
//         {
//             if (ALPHABET[i] != map[map_alphabet[i]])
//             {
//                 throw std::invalid_argument("Invalid reflector mapping");
//             }
//         }
//     }

//     int reflect(int index_num) const
//     {
//         char reflected_char = map.at(ALPHABET[index_num]);
//         return ALPHABET.find(reflected_char);
//     }

// private:
//     std::unordered_map<char, char> map;
// };

// class EnigmaMachine
// {
// public:
//     EnigmaMachine(const PlugBoard &plug_board, const std::vector<Rotor> &rotors, const Reflector &reflector)
//         : plug_board(plug_board), rotors(rotors), reflector(reflector) {}

//     std::string encrypt(const std::string &text)
//     {
//         std::string result;
//         for (char c : text)
//         {
//             result += go_through(c);
//         }
//         return result;
//     }

//     std::string decrypt(const std::string &text)
//     {
//         for (auto &rotor : rotors)
//         {
//             rotor.reset();
//         }
//         return encrypt(text);
//     }

// private:
//     char go_through(char c)
//     {
//         if (ALPHABET.find(c) == std::string::npos)
//         {
//             return c;
//         }

//         int index_num = ALPHABET.find(c);
//         index_num = plug_board.forward(index_num);

//         for (auto &rotor : rotors)
//         {
//             index_num = rotor.forward(index_num);
//         }

//         index_num = reflector.reflect(index_num);

//         for (auto it = rotors.rbegin(); it != rotors.rend(); ++it)
//         {
//             index_num = it->backward(index_num);
//         }

//         index_num = plug_board.backward(index_num);
//         c = ALPHABET[index_num];

//         for (auto it = rotors.rbegin(); it != rotors.rend(); ++it)
//         {
//             if (it->rotate() % ALPHABET.size() != 0)
//             {
//                 break;
//             }
//         }

//         return c;
//     }

//     PlugBoard plug_board;
//     std::vector<Rotor> rotors;
//     Reflector reflector;
// };

// std::string get_random_alphabet()
// {
//     std::string alphabet = ALPHABET;
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(alphabet.begin(), alphabet.end(), g);
//     return alphabet;
// }

// std::string rotate_alphabet(const std::string &text, int shift)
// {

//     std::string result;
//     for (char c : text)
//     {
//         result += (c - 'A' + shift) % 26 + 'A';
//     }
//     return result;
// }

// int main()
// {

//     PlugBoard p(get_random_alphabet());
//     Rotor r1(get_random_alphabet(), 3);
//     Rotor r2(get_random_alphabet(), 2);
//     Rotor r3(get_random_alphabet(), 1);

//     std::string reflector_alphabet = ALPHABET;
//     std::vector<int> indexes;
//     for (size_t i = 0; i < ALPHABET.size(); ++i)
//     {
//         indexes.push_back(i);
//     }
//     std::random_device rd;
//     std::mt19937 g(rd());
//     std::shuffle(indexes.begin(), indexes.end(), g);

//     for (size_t i = 0; i < indexes.size() / 2; ++i)
//     {
//         std::swap(reflector_alphabet[indexes[i * 2]], reflector_alphabet[indexes[i * 2 + 1]]);
//     }

//     Reflector reflector(reflector_alphabet);

//     std::vector<Rotor> rotors = {r1, r2, r3};
//     EnigmaMachine machine(p, rotors, reflector);

//     std::string s = "ATTACK SILICON VALLEY";
//     std::string e = machine.encrypt(s);
//     std::cout << "Encrypted: " << e << std::endl;
//     std::string d = machine.decrypt(e);
//     std::cout << "Decrypted: " << d << std::endl;

//     return 0;
// }

// 自分で書いたコード（できなかった

// #include <bits/stdc++.h>
// using namespace std;

// const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// string shuffle_text(const string &text)
// {
//     srand(time(NULL));
//     string result = text;

//     for (int i = 0; i < text.size() * 3; i++)
//     {
//         int index1 = rand() % text.size();
//         int index2 = rand() % text.size();
//         swap(result[index1], result[index2]);
//     }
//     return result;
// }
// string get_swap_alphabet()
// {
//     string result = alphabet;

//     random_device rd;
//     mt19937 mt(rd());
//     uniform_int_distribution<int> rand(0, 25);

//     unordered_map<int, bool> cache;

//     for (int i = 0; i < result.size(); i++)
//     {
//         int k = rand(mt);
//         int j = rand(mt);

//         if (!cache[k] && !cache[j])
//             swap(result[k], result[j]);

//         cache[k] = true;
//         cache[j] = true;
//     }

//     return result;
// }

// class PlugBoad
// {
// public:
//     unordered_map<int, char> forward;
//     unordered_map<char, int> backward;

//     PlugBoad()
//     {
//         string shuffled = shuffle_text(alphabet);

//         for (char c = 'A'; c <= 'Z'; c++)
//         {
//             int index = c - 'A';
//             forward[index] = shuffled[index];
//             backward[shuffled[index]] = index;
//         }
//     }

//     char get_forward(char input)
//     {
//         int index = input - 'A';
//         return forward[index];
//     }
//     char get_backward(char output)
//     {
//         return backward[output] + 'A';
//     }
// };

// class Reflector
// {
//     unordered_map<char, char> reflect_map;

// public:
//     Reflector()
//     {
//         string shuffled = get_swap_alphabet();

//         for (char c = 'A'; c <= 'Z'; c++)
//         {
//             reflect_map[c] = shuffled[c - 'A'];
//         }
//     }

//     char get_reflect(char input)
//     {
//         return reflect_map[input];
//     }
// };

// class Rotor : public PlugBoad
// {
// public:
//     int offset;
//     int counter;

//     Rotor(int offset)
//     {
//         this->offset = offset;
//         counter = 0;
//         PlugBoad();
//     }

//     char get_forward(char input)
//     {
//         int index = input - 'A';
//         // 回転分ずらしたインデックスを取得する
//         index = (index + counter * offset) % 26;
//         return this->forward[index];
//     }
//     char get_backward(char input)
//     {
//         int index = this->backward[input];
//         // 回転分ずらしたインデックスから文字を取得する
//         return (index + counter * offset) % 26 + 'A';
//     }

//     void reset()
//     {
//         counter = 0;
//     }

//     bool rotate()
//     {

//         this->counter += 1;
//         if (counter * offset % alphabet.size() == 0)
//             reset();

//         return counter * offset % alphabet.size() == 0;
//     }
// };

// char go_through(char &c, PlugBoad plug, Rotor r1, Rotor r2, Rotor r3, Reflector refrector)
// {
//     if ('A' <= c && c <= 'Z')
//     {
//         char output = plug.get_forward(c);
//         output = r1.get_forward(output);
//         output = r2.get_forward(output);
//         output = r3.get_forward(output);
//         output = refrector.get_reflect(output);
//         output = r3.get_backward(output);
//         output = r2.get_backward(output);
//         output = r1.get_backward(output);

//         bool is_rotate_next = r3.rotate();
//         if (is_rotate_next > 0)
//         {
//             is_rotate_next = r2.rotate();
//             if (is_rotate_next > 0)
//                 r1.rotate();
//         }
//         output = plug.get_backward(output);

//         return output;
//     }
//     else
//     {
//         return c;
//     }
// }

// int main()
// {

//     string text = "ATTACK BY SILICON VALLAY";
//     // string text = "ATT";

//     PlugBoad plug = PlugBoad();
//     Reflector refrector = Reflector();
//     Rotor r1 = Rotor(1);
//     Rotor r2 = Rotor(2);
//     Rotor r3 = Rotor(3);

//     string encrypted;
//     for (char c : text)
//     {
//         encrypted += go_through(c, plug, r1, r2, r3, refrector);
//     }

//     r1.reset();
//     r2.reset();
//     r3.reset();

//     string decrypted;
//     for (char &c : encrypted)
//     {
//         decrypted += go_through(c, plug, r1, r2, r3, refrector);
//     }
//     cout << decrypted << endl;

//     return 0;
// }
