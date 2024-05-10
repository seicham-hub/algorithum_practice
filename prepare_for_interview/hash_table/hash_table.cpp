#include <bits/stdc++.h>
using namespace std;

class HashTable
{
public:
    int size;
    vector<vector<array<string, 2>>> table;

    HashTable(int size)
    {
        this->size = size;
        table.resize(size);
    }

    int hash(string key)
    {

        int hash_value = 0;

        for (char c : key)
        {
            hash_value = (hash_value * 31 + c) % size;
        }

        return hash_value;
    }

    void add(string key, string value)
    {
        int index = hash(key);
        for (auto &data : table[index])
        {
            if (data[0] == key)
            {
                data[1] = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

    string get(string key)
    {
        int index = hash(key);
        for (auto data : table[index])
        {
            if (data[0] == key)
            {
                return data[1];
            }
        }
        return "";
    }

    string &operator[](const string &key)
    {
        int index = hash(key);
        for (auto &data : table[index])
        {
            if (data[0] == key)
            {
                return data[1];
            }
        }

        table[index].push_back({key, ""});
        return table[index].back()[1];
    }

    void remove(string key)
    {
        int index = hash(key);
        for (int i = 0; i < table[index].size(); i++)
        {
            auto data = table[index][i];
            if (data[0] == key)
            {
                table[index].erase(table[index].begin() + i);
            }
        }

        return;
    }
};

int main()
{
    HashTable *hash_table = new HashTable(10);
    hash_table->add("michel", "jackson");
    hash_table->add("hogehoge", "pichipichi");

    (*hash_table)["hogehoge"] = "bogibogi";
    (*hash_table)["bakibaki"] = "doutei";

    cout << (*hash_table)["hogehoge"] << endl;
    cout << (*hash_table)["bakibaki"] << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// class HashTable
// {
// public:
//     int size;
//     vector<vector<array<string, 2>>> table;

//     HashTable(int size)
//     {
//         this->size = size;
//         table.resize(size);
//     }

//     int hash(const string &key)
//     {
//         int hash_value = 0;
//         for (char c : key)
//         {
//             hash_value = (hash_value * 31 + c) % size;
//         }

//         return abs(hash_value);
//     }
//     void add(const string &key, const string &value)
//     {
//         int index = hash(key);

//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//             {
//                 data[1] = value;
//                 return;
//             }
//         }

//         table[index].push_back({key, value});
//         return;
//     }

//     string get(const string &key)
//     {

//         int index = hash(key);
//         for (auto &data : table[index])
//         {
//             if (key == data[0])
//                 return data[1];
//         }

//         return "";
//     }

//     string &operator[](const string &key)
//     {
//         int index = hash(key);
//         for (auto &data : table[index])
//         {
//             if (key == data[0])
//                 return data[1];
//         }

//         table[index].push_back({key, ""});
//         return table[index].back()[1];
//     }
// };

// int main()
// {
//     HashTable *hash = new HashTable(10);
//     hash->add("ghq", "マッカーサー");
//     hash->add("ghq", "マッカーサー2");
//     hash->add("ghq", "マッカーサー3");
//     hash->add("映画", "ヒトラーの逆襲");

//     cout << hash->get("ghq") << endl;
//     cout << hash->get("映画") << endl;
//     cout << hash->get("gdshafjsd") << endl;
//     (*hash)["gdshafjsd"] = "gfjdsakgfjds";
//     (*hash)["映画"] = "ゴジラ";
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class HashTable
// {

// public:
//     int size;
//     vector<vector<array<string, 2>>> table;

//     HashTable(int size)
//     {
//         this->size = size;
//         table.resize(size);
//     }

//     int hash(const string &key)
//     {
//         int hash_value = 0;
//         for (char c : key)
//         {
//             hash_value = (hash_value * 31 + c) % size;
//         }

//         return hash_value;
//     }

//     void add(string key, string value)
//     {
//         int index = hash(key);
//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//             {
//                 data[1] = value;
//                 return;
//             }
//         }

//         table[index].push_back({key, value});
//     }

//     string get(const string &key)
//     {
//         int index = hash(key);
//         for (auto data : table[index])
//         {
//             if (data[0] == key)
//             {
//                 return data[1];
//             }
//         }

//         return "";
//     }

//     string &operator[](const string key)
//     {
//         int index = hash(key);

//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//                 return data[1];
//         }

//         table[index].push_back({key, ""});
//         return table[index].back()[1];
//     }
// };

// int main()
// {

//     HashTable *hash = new HashTable(15);
//     hash->add("johnny", "deapp");
//     hash->add("johnny", "beep");
//     hash->add("bad", "boy");
//     cout << hash->get("johnny") << endl;

//     cout << hash->get("bad") << endl;
//     cout << (*hash)["bad"] << endl;
//     (*hash)["good"] = "girl";
//     cout << (*hash)["good"] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class HashTable
// {
// public:
//     int size;
//     vector<vector<array<string, 2>>> table;

//     HashTable(int size)
//     {
//         this->size = size;
//         table.resize(size);
//     };

//     int hash(const string &key)
//     {
//         int hashValue = 0;

//         for (auto &c : key)
//         {
//             // 31は素数でハッシュ値の衝突を避けられる、2^5に近いのでコンピュータが扱いやすく高速
//             hashValue = (hashValue * 31 + c) % size;
//         }

//         return hashValue;
//     }

//     void add(string key, string value)
//     {
//         int index = hash(key);

//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//             {
//                 data[1] = value;
//                 return;
//             }
//         }
//         table[index].push_back({key, value});
//     }

//     string get(const string key)
//     {
//         int index = hash(key);

//         for (auto data : table[index])
//         {
//             if (data[0] == key)
//                 return data[1];
//         }

//         return "";
//     }

//     string &operator[](const string &key)
//     {
//         int index = hash(key);

//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//                 return data[1];
//         }

//         table[index].push_back({key, ""});

//         return table[index].back()[1];
//     }
// };

// int main()
// {

//     HashTable *hash = new HashTable(10);

//     hash->add("police", "angry");
//     hash->add("sea", "beautiful");
//     hash->add("police", "happy");
//     cout << hash->get("police") << endl;
//     cout << hash->get("sea") << endl;
//     (*hash)["sea"] = "excellent";
//     (*hash)["ttt"] = "ttt";
//     cout << (*hash)["sea"] << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class HashTable
// {

// public:
//     int size;
//     vector<vector<array<string, 2>>> table;

//     HashTable(int size) : size(size), table(size) {}

//     int hash(const string &key)
//     {
//         int hashValue = 0;
//         for (auto &c : key)
//         {
//             hashValue = (hashValue * 31 + c) % size;
//         }

//         return hashValue;
//     }

//     void add(string key, string value)
//     {
//         int index = hash(key);
//         for (auto &data : table[index])
//         {
//             if (key == data[0])
//             {
//                 data[1] = value;
//                 return;
//             }
//         }

//         table[index].push_back({key, value});
//     }

//     string get(const string &key)
//     {
//         int index = hash(key);
//         for (auto &data : table[index])
//         {
//             if (data[0] == key)
//             {
//                 return data[1];
//             }
//         }

//         return "";
//     }

//     string &operator[](const string &key)
//     {
//         int index = hash(key);
//         for (auto d : table[index])
//         {
//             if (d[0] == key)
//                 return d[1];
//         }

//         table[index].push_back({key, ""});

//         return table[index].back()[1];
//     }

//     void print()
//     {

//         for (int i = 0; i < size; ++i)
//         {
//             cout << i << " ";
//             for (auto data : table[i])
//             {
//                 cout << "--> [" << data[0] << "," << data[1] << "] ";
//             }
//             cout << endl;
//         }
//     }
// };

// int main()
// {
//     HashTable fake_map(10);

//     fake_map.add("car", "toyota");
//     fake_map.add("sns", "youtube");
//     cout << fake_map.get("car") << endl;

//     fake_map["car"] = "tesla";
//     fake_map["pp"] = "point";
//     fake_map.print();

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class HashTable
// {

// public:
//     int size;
//     vector<vector<array<string, 2>>> table;

//     int hash(string key)
//     {
//         int hashValue = 0;
//         for (char c : key)
//         {
//             hashValue = (hashValue * 31 + c) % size;
//         }
//         return hashValue;
//     }

//     void add(string key, string value)
//     {
//         int index = hash(key);

//         for (auto &t : table[index])
//         {
//             if (t[0] == key)
//             {
//                 t[1] = value;
//                 return;
//             }
//         }
//         table[index].push_back({key, value});
//     }

//     string get(const string &key)
//     {

//         int index = hash(key);
//         for (auto &d : table[index])
//         {
//             if (d[0] == key)
//                 return d[1];
//         }

//         return "";
//     }
//     // get関数とadd関数を[]で表現
//     // operatorで記号を関数名として定義
//     string &operator[](const string &key)
//     {

//         int index = hash(key);
//         for (auto &d : table[index])
//         {
//             if (d[0] == key)
//                 return d[1];
//         }
//         table[index].push_back({key, ""});

//         return table[index].back()[1];
//     }

//     void print()
//     {
//         for (int i = 0; i < size; i++)
//         {
//             cout << i << " ";
//             for (auto &t : table[i])
//                 cout << "-->[" << t[0] << "," << t[1] << "] ";
//             cout << endl;
//         }
//     }

//     HashTable(int size) : size(size), table(size){};
// };

// int main()
// {
//     HashTable hash_table(10);

//     cout << hash_table.hash("pc") << endl;

//     hash_table.add("car", "tesla");
//     hash_table.add("car", "tesla2");
//     hash_table.add("car", "tesla3");
//     hash_table.add("sns", "youtube");

//     hash_table.print();
//     hash_table["fast"] = "api";

//     cout << hash_table.get("dfhg") << endl;
//     return 0;
// }