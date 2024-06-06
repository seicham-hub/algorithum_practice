// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
// 0417もう一度
// 0418もう一度
// 2024_06_04もう一度　制約条件よく見る

// 重複なしを考えるとき、以前出てきた数字は無視すればよい(02352789のとき023,025,027,028,029はすべて前半の2をとればよい)
// nに着目するとO(n^3)だが、答えに注目すると10^3だなぁ

#include <bits/stdc++.h>
using namespace std;

vector<string> create_candidate()
{
    vector<string> result;

    for (int i = 0; i <= 999; i++)
    {
        string num = to_string(i);
        for (int j = num.size(); j < 3; j++)
        {
            num.insert(num.begin(), '0');
        }

        result.push_back(num);
    }

    return result;
}

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<string> candidate = create_candidate();

    vector<string> ans;
    for (string num : candidate)
    {
        int ind = 0;
        for (char c : s)
        {
            if (c == num[ind])
                ind++;
            if (ind >= 3)
            {
                ans.push_back(num);
                break;
            }
        }
    }

    cout << ans.size() << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     string s;
//     cin >> n >> s;

//     vector<string> candidate, ans;

//     for (int i = 0; i <= 999; i++)
//     {
//         string num = to_string(i);
//         int size = num.size();
//         for (int i = 0; i < 3 - size; i++)
//             num.insert(num.begin(), '0');

//         candidate.push_back(num);
//     }

//     for (string num : candidate)
//     {
//         int ind = 0;
//         for (int i = 0; i < n; i++)
//         {
//             if (num[ind] == s[i])
//             {
//                 ind++;
//             }
//             if (ind >= 3)
//                 break;
//         }

//         if (ind == 3)
//             ans.push_back(num);
//     }

//     cout << ans.size() << endl;
// }
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, next_index[30005][10], result = 0;
//     string s;

//     cin >> n >> s;

//     for (int i = 0; i < 10; i++)
//     {
//         next_index[n][i] = n;
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         // 後ろのものをいったん引き継ぐ
//         for (int j = 0; j < 10; j++)
//         {
//             next_index[i][j] = next_index[i + 1][j];
//         }
//         // 現在インデックスにある数字について、インデックス番号を格納
//         next_index[i][s[i] - '0'] = i;
//     }

//     for (int i = 0; i < 10; i++)
//     {

//         for (int j = 0; j < 10; j++)
//         {
//             for (int k = 0; k < 10; k++)
//             {

//                 int curIndex = next_index[0][i];
//                 curIndex++;
//                 curIndex = next_index[min(curIndex, n)][j];
//                 curIndex++;
//                 curIndex = next_index[min(curIndex, n)][k];

//                 if (curIndex < n)
//                     result++;
//             }
//         }
//     }

//     cout << result << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, next_index[30005][10], result = 0;
//     string s;
//     cin >> n >> s;

//     // ありえない外れ値作成
//     for (int i = 0; i <= 9; i++)
//     {
//         next_index[n][i] = n;
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j <= 9; j++)
//         {
//             next_index[i][j] = next_index[i + 1][j];
//         }
//         next_index[i][s[i] - '0'] = i;
//     }

//     for (int i = 0; i <= 9; i++)
//     {
//         for (int j = 0; j <= 9; j++)
//         {
//             for (int k = 0; k <= 9; k++)
//             {
//                 int curIndex = next_index[0][i];
//                 curIndex++;
//                 curIndex = next_index[min(curIndex, n)][j];
//                 curIndex++;
//                 curIndex = next_index[min(curIndex, n)][k];

//                 if (curIndex < n)
//                 {
//                     result++;
//                 }
//             }
//         }
//     }

//     cout << result << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {

//     int n, next_index[30005][10], result = 0;
//     string s;

//     cin >> n >> s;

//     for (int i = 0; i < 10; i++)
//     {
//         next_index[n][i] = n;
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             next_index[i][j] = next_index[i + 1][j];
//         }
//         next_index[i][s[i] - '0'] = i;
//     }

//     for (int i = 0; i <= 9; i++)
//     {
//         for (int j = 0; j <= 9; j++)
//         {
//             for (int k = 0; k <= 9; k++)
//             {
//                 int nowIndex = next_index[0][i];
//                 nowIndex++;
//                 nowIndex = next_index[min(nowIndex, n)][j];
//                 nowIndex++;
//                 nowIndex = next_index[min(nowIndex, n)][k];

//                 if (nowIndex < n)
//                     result++;
//             }
//         }
//     }

//     cout << result << endl;

//     return 0;
// }

// 0417解答
// #include <bits/stdc++.h>
// using namespace std;

// string str;
// int nxt[30005][10];

// int main()
// {
//     int n;
//     cin >> n >> str;

//     for (int i = 0; i < 10; i++)
//         nxt[n][i] = n;

//     for (int i = n - 1; i >= 0; i--)
//     {
//         // デフォルトはインデックス存在しないことにする
//         // nxt[0][4]=3 現在の位置0から次に4がでるのはindex３の位置
//         for (int j = 0; j < 10; j++)
//             nxt[i][j] = nxt[i + 1][j];
//         int a = str[i] - '0';
//         nxt[i][a] = i;
//     }

//     int ret = 0;
//     for (int i = 0; i < 10; i++)
//     {
//         for (int j = 0; j < 10; j++)
//         {
//             for (int k = 0; k < 10; k++)
//             {
//                 int nowInd = nxt[0][i];
//                 nowInd++;
//                 nowInd = nxt[min(nowInd, n)][j];
//                 nowInd++;
//                 nowInd = nxt[min(nowInd, n)][k];
//                 if (nowInd < n)
//                     ret++;
//             }
//         }
//     }
//     cout << ret << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, result;
//     string s;
//     cin >> n >> s;

//     for(int i=0;i<=9;i++){
//         for(int j=0;j<=9;j++){
//             for(int k=0;k<=9;k++){

//             }
//         }

//     }

//     return 0;
// }
