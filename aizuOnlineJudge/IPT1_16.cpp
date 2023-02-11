
#include <stdio.h>
using namespace std;

int main(){
    int a,b;
    // char型は一文字のみ格納,stringは複数文字いける charはシングルクォート、stringはダブルクォートで囲む
    char op;

    while(true){
        scanf("%d %c %d",&a,&op,&b);
        if (op=='?') break;
        switch(op){
            case '+':
                printf("%d\n",a+b);
                break;
            case '-':
                printf("%d\n",a-b);
                break;
            case '*':
                printf("%d\n",a*b);
                break;
            case '/':
                printf("%d\n",a/b);
                break;
        }
    }
}


// 最初の自分のコード↓
// # include <iostream>
// using namespace std;

// int main(){
//     int a,b;
//     string op;

//     for(int i=0;;i++){
//         cin >> a >> op >> b;

//         if (op == "?") break;

//         if (op =="+"){
//             cout << a+b <<endl;
//         }else if(op=="-"){
//             cout << a-b  <<endl;
//         }else if(op =="*"){
//             cout << a*b  <<endl;
//         }else if(op=="/"){
//             cout << a/b << endl;
//         }
//     }


//     return 0;
// }
