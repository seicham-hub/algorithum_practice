#include <bits/stdc++.h>
using namespace std;

class HashTable
{

public:
    int size;
    vector<vector<array<string, 2>>> table;

    HashTable(int size) : size(size), table(size) {}

    int hash(const string &key)
    {
        int hashValue = 0;
        for (auto &c : key)
        {
            hashValue = (hashValue * 31 + c) % size;
        }

        return hashValue;
    }

    void add(string key, string value)
    {
        int index = hash(key);
        for (auto &data : table[index])
        {
            if (key == data[0])
            {
                data[1] = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

    string get(const string &key)
    {
        int index = hash(key);
        for (auto &data : table[index])
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
        for (auto d : table[index])
        {
            if (d[0] == key)
                return d[1];
        }

        table[index].push_back({key, ""});

        return table[index].back()[1];
    }

    void print()
    {

        for (int i = 0; i < size; ++i)
        {
            cout << i << " ";
            for (auto data : table[i])
            {
                cout << "--> [" << data[0] << "," << data[1] << "] ";
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable fake_map(10);

    fake_map.add("car", "toyota");
    fake_map.add("sns", "youtube");
    cout << fake_map.get("car") << endl;

    fake_map["car"] = "tesla";
    fake_map["pp"] = "point";
    fake_map.print();

    return 0;
}

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