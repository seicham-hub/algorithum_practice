// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d

// 0426もう一度

// 方針が思いつかなかった。操作の法則が見つけられなかった

#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
int n;

void dfs(string now, int used_count)
{
    if (now.size() == n)
    {
        ans.push_back(now);
        return;
    }

    char last = now.back();
    for (int i = 0; i <= used_count; i++)
    {
        char next = 'a' + i;
        if (i != used_count)
            dfs(now + next, used_count);
        else
            dfs(now + next, used_count + 1);
    }
}

int main()
{

    cin >> n;

    dfs("a", 1);

    for (string a : ans)
        cout << a << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int n;
// vector<string> ans;

// void dfs(string text, int used_char_count)
// {

//     if (text.size() == n)
//     {
//         ans.push_back(text);
//         return;
//     }

//     for (int i = 0; i <= used_char_count; i++)
//     {
//         char add_char = 'a' + i;

//         if (i == used_char_count)
//             dfs(text + add_char, used_char_count + 1);
//         else
//             dfs(text + add_char, used_char_count);
//     }
// }

// int main()
// {

//     cin >> n;

//     dfs("a", 1);

//     for (string a : ans)
//     {
//         cout << a << endl;
//     }

//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;

// int n;

// void dfs(string str, int uniqueNum)
// {
//     if (str.size() == n)
//     {
//         cout << str << endl;
//         return;
//     }
//     else
//     {
//         for (int i = 0; i < uniqueNum; i++)
//         {
//             char add = 'a' + i;
//             dfs(str + add, uniqueNum);
//         }
//         char add = 'a' + uniqueNum;
//         dfs(str + add, uniqueNum + 1);
//     }
// }

// int main()
// {

//     cin >> n;

//     dfs("", 0);

//     return 0;
// }

/*
お手本解答
*/
// #include <cstdio>

// using namespace std;

// int n;
// char s[11];

// void dfs(int x, int y)
// {

//     if (x == n)
//     {
//         printf("%s\n", s);
//     }
//     else
//     {
//         for (i = 0; i < y; i++)
//         {
//             s[x] = 'a' + i;
//             dfs(x + 1, y);
//         }

//         s[x] = 'a' + y;
//         dfs(x + 1, y + 1);
//     }
// }

// int main()
// {
//     int i;

//     scanf("%d", &n);

//     dfs(0, 0);

//     return 0;
// }

// 解説をよんで書いたコード↓
// #include <bits/stdc++.h>
// using namespace std;

// int n;

// vector<string> ans;

// void dfs(string str, int uStrNum)
// {
//     if ((int)str.size() == n)
//     {
//         ans.push_back(str);
//         return;
//     }
//     else
//     {

//         for (char i = 'a'; i <= 'a' + uStrNum; i++)
//         {
//             int nextUstrNum = uStrNum;
//             if (i == 'a' + uStrNum)
//             {
//                 nextUstrNum++;
//             }
//             string nextStr = str + i;
//             dfs(nextStr, nextUstrNum);
//         }
//     }
// }

// int main()
// {
//     cin >> n;

//     dfs("", 0);

//     for (int i = 0; i < (int)ans.size(); i++)
//     {

//         cout << ans[i] << endl;
//     }

//     return 0;
// }
