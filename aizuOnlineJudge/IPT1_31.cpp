// Sum of Numbers
// 0312もう一度

#include <stdio.h>
using namespace std;

int main()
{
    char ch;
    int sum = 0;
    while (true)
    {
        while ((ch = getchar()) != '\n')
        {
            sum += ch - '0';
        }
        if (sum == 0)
            break;
        else
        {
            printf("%d\n", sum);
            sum = 0;
        }
    }
    return 0;
}

// # include <iostream>
// # include <string>
// using namespace std;

// int main(){

//     char x;

//     while(true){
//         int sum =0;
//         while((x = getchar()) !='\n'){
//             sum += x-'0';
//         }

//         if(sum == 0) break;
//         else cout << sum << endl;

//     }

//     return 0;
// }

// #include <iostream>
// #include<string>

// using namespace std;

// int main(){
//     string str;
//     cin >> str;
//     while(str[0] != '0'){
//         int i,o=0;
//         for(i=0;i<str.size();i++){
//             o+= str[i]-'0';
//         }
//         cout << o <<endl;
//         cin >> str;
//     }
//     return 0;
// }