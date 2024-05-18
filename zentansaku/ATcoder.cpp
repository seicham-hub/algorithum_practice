
// https://atcoder.jp/contests/abc122/tasks/abc122_b
// 0413もう一度
// 0414もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    unordered_map<char, bool> is_acgt = {{'A', true}, {'C', true}, {'G', true}, {'T', true}};
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        int tmp_max = 0;
        while (is_acgt.count(s[j]))
        {
            tmp_max++;
            j++;
        }

        ans = max(ans, tmp_max);
    }

    cout << ans << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     int maxLength = 0;
//     cin >> s;

//     for (int i = 0; i < s.size();)
//     {

//         int tmpMax = 0;

//         while (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C')
//         {
//             tmpMax++;
//             i++;
//         }

//         if (tmpMax == 0)
//             i++;

//         maxLength = max(tmpMax, maxLength);
//     }
//     cout << maxLength << endl;
//     return 0;
// }

// 0414実施分
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     int maxLength = 0;

//     cin >> s;

//     for (int i = 0; i < s.size();)
//     {
//         int tmp_length = 0;
//         cout << i << endl;
//         while (i < s.size() && (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C'))
//         {
//             tmp_length++;
//             i++;
//         }
//         maxLength = max(maxLength, tmp_length);

//         if (tmp_length == 0)
//             i++;
//     }
//     cout << maxLength << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     int result = 0;
//     cin >> s;

//     for (int i = 0; i < s.size(); i++)
//     {
//         int bubunLn = 0;
//         while (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C')
//         {

//             bubunLn++;
//             i++;
//         }
//         result = max(result, bubunLn);
//     }
//     cout << result << endl;
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int result = 0;
//     string s;
//     cin >> s;

//     for (int i = 0; i < s.size(); i++)
//     {
//         for (int j = 0; j < s.size() - i; j++)
//         {
//             string sub = s.substr(i, s.size() - (i + j));
//             bool isATGC = true;
//             for (int k = 0; k < sub.size(); k++)
//             {
//                 if (sub[k] != 'A' && sub[k] != 'C' && sub[k] != 'G' && sub[k] != 'T')
//                 {
//                     isATGC = false;
//                 }
//             }
//             if (isATGC)
//             {

//                 if (sub.size() > result)
//                     result = sub.size();
//             }
//         }
//     }
//     cout << result << endl;
//     return 0;
// }

// chatGPTのコード。初めからカウントしていく、調べたインデックスは
// 再度調べる必要がないのでぶっ飛ばす。(forのintを進める)

// #include <iostream>
// #include <string>

// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;
//     int ans = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         int cnt = 0;
//         while (i < s.size() && (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'))
//         {
//             cnt++;
//             i++;
//         }
//         ans = max(ans, cnt);
//     }
//     cout << ans << endl;
//     return 0;
// }