// Toggling Cases
// 0312もう一度


// getline 改行文字が表れるまで（一行すべて）取得する
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    getline(cin,str);
    int i;
    for (i=0;i<str.size();i++){
        if(str[i]>'a' && str[i]<='z') str[i]+='A'-'a';
        else if(str[i]>'A' && str[i]<='Z') str[i]+='a'-'A';
    }
    cout << str << endl;
}


// getchar()はASCIIコードが返ってくる。これをchar型で受け取る事ができる。
// # include <iostream>
// # include <stdio.h>
// using namespace std;

// int main(){

//     char ch;

//     while(((ch)=getchar()) != EOF){
//         // printf("%c",ch);
//         if(ch >= 'a' && ch<= 'z') cout << (char)(ch + ('A'-'a'));
//         else if(ch >= 'A' && ch<= 'Z') cout << (char)(ch +('a'-'A'));
//         else cout << ch;
//     }
//     return 0;
// }

