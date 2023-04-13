// 0413もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int result = 0;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        int bubunLn = 0;
        while (s[i] == 'A' || s[i] == 'T' || s[i] == 'G' || s[i] == 'C')
        {

            bubunLn++;
            i++;
        }
        result = max(result, bubunLn);
    }
    cout << result << endl;
    return 0;
}

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