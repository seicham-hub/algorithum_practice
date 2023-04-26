// https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_d

// 0426もう一度

// 方針が思いつかなかった。操作の法則が見つけられなかった

#include <cstdio>

using namespace std;

int n;
char s[11];

void dfs(int x, int y)
{

    if (x == n)
    {
        printf("%s\n", s);
    }
    else
    {
        for (i = 0; i < y; i++)
        {
            s[x] = 'a' + i;
            dfs(x + 1, y);
        }

        s[x] = 'a' + y;
        dfs(x + 1, y + 1);
    }
}

int main()
{
    int i;

    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}

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
