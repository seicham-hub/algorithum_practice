#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cntS[256] = {}, cntT[256] = {};

    string s, t, at = "atcoder";

    cin >> s >> t;

    for (int i = 0; i < s.size(); i++)
    {
        cntS[s[i]]++;
        cntT[t[i]]++;
    }

    for (int i = 0; i < 7; i++)
    {
        char c = at[i];
        int M = max(cntS[c], cntT[c]);

        cntS['@'] -= M - cntS[c];
        cntT['@'] -= M - cntT[c];

        cntS[c] = cntT[c] = M;
    }

    bool ans = cntS['@'] >= 0 && cntT['@'] >= 0;

    for (int i = 0; i < 255; i++)
    {
        ans = ans && cntS[i] == cntT[i];
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}

/*
やり直し分
*/
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     string s, t, at = "atcoder";
//     int sCnt[256] = {0};
//     int tCnt[256] = {0};

//     cin >> s >> t;

//     for (int i = 0; i < s.size(); i++)
//     {
//         sCnt[s[i]]++;
//         tCnt[t[i]]++;
//     }

//     for (int i = 0; i < 7; i++)
//     {
//         int M = max(sCnt[at[i]], tCnt[at[i]]);

//         sCnt['@'] -= M - sCnt[at[i]];
//         tCnt['@'] -= M - tCnt[at[i]];

//         sCnt[at[i]] = tCnt[at[i]] = M;
//     }

//     bool ans = sCnt['@'] >= 0 && tCnt['@'] >= 0;

//     for (int i = 0; i < 256; i++)
//     {
//         ans = ans && sCnt[i] == tCnt[i];
//     }

//     puts(ans ? "Yes" : "No");

//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int cnt[2][256];
// char s[2][200010];
// char *t = "atcoder";
// int main()
// {
//     scanf("%s %s", s[0], s[1]);
//     for (int i = 0; s[0][i]; i++)
//     {
//         cnt[0][s[0][i]]++;
//         cnt[1][s[1][i]]++;
//     }

//     for (int i = 0; i < 7; i++)
//     {
//         int M = fmax(cnt[0][t[i]], cnt[1][t[i]]);
//         for (int j = 0; j < 2; j++)
//         {
//             cnt[j]['@'] -= M - cnt[j][t[i]];
//             // 同じ回数になるように調整
//             cnt[j][t[i]] = M;
//         }
//     }

//     bool ans = cnt[0]['@'] >= 0;
//     for (int i = 0; i < 256; i++)
//         ans &= cnt[0][i] == cnt[1][i];
//     puts(ans ? "Yes" : "No");
// }

// 本番のコード
// 数字比較の際のture,falseは明確にする必要あり。

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s, t;

//     cin >> s >> t;
//     map<char, int> left, right;

//     for (int i = 'a'; i <= 'z'; i++)
//     {
//         left[i] = 0;
//         right[i] = 0;
//     }
//     left['@'] = 0;
//     right['@'] = 0;

//     for (int i = 0; i < s.size(); i++)
//     {
//         left[s[i]] += 1;
//         right[t[i]] += 1;
//     }

//     for (int i = 'a'; i <= 'z'; i++)
//     {
//         // cout << (char)i << left[i] << right[i] << endl;
//         if (left[i] == right[i])
//             continue;
//         else
//         {
//             if (i == 'a' || i == 't' || i == 'c' || i == 'o' || i == 'd' || i == 'e' || i == 'r')
//             {

//                 // ちゃんと数字は明示してあげる必要がある。>0を省略する事はできない
//                 if (left[i] - right[i] > 0)
//                 {
//                     right['@'] -= left[i] - right[i];
//                 }
//                 else if (right[i] - left[i] > 0)
//                 {
//                     left['@'] -= right[i] - left[i];
//                 }
//             }
//             else
//             {
//                 right['@'] = -100;
//                 left['@'] = -100;
//                 break;
//             }
//         }
//     }

//     if (right['@'] >= 0 && left['@'] >= 0)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }

//     return 0;
// }
