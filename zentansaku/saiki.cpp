
// すべての桁が1以上 M以下であるような、増加的な N
// 桁の整数をすべて出力してください。（増加的な整数とは、
// 112や1355679のような数のことを指します。）

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;

void find_increasing_num(const int &digit, int now_num, string tmp)
{

    if (tmp.size() == digit)
    {
        ans.push_back(stoi(tmp));
        return;
    }

    for (int i = now_num; i <= m; i++)
    {
        string next_tmp = tmp;
        next_tmp += i + '0';
        find_increasing_num(digit, i, next_tmp);
    }
}

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {

        find_increasing_num(i, 1, "");
    }

    for (int a : ans)
    {
        cout << a << endl;
    }

    return 0;
}

// int n, m;

// void func(string cur)
// {
//     if (cur.size() == n)
//     {
//         cout << cur << endl;
//         return;
//     }
//     int last = 1;
//     if (cur.size() >= 1)
//         last = cur[cur.size() - 1];
//     for (int i = last; i <= m; i++)
//     {
//         string nex = cur;
//         nex += ('0' + i);
//         func(nex);
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     cin >> m >> n;

//     return 0;
// }
