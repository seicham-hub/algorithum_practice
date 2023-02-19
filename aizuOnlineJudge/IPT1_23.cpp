//Finding Missing Cards
// 0214もう一度

// scanfを使用する際の注意点
// 最後の改行文字がバッファの中に残る
// 何か入力した後にエンターを押して一文字だけ入力する場合に改行文字（空白）が出力されてしまう。

// voidは戻り値がないことを表す

#include <stdio.h>
using namespace std;

void outPut(int Array[],char mark){
    for (int i=1;i<=13;i++){
        if (Array[i] ==0) printf("%c %d\n",mark,i);
    }
}

int main() {

    char mark[2];
    int n,S[14],H[14],C[14],D[14],tmp;
    for (int i=0;i<14;i++) S[i] = H[i] =C[i] =D[i] =0;
    scanf("%d",&n);

    for (int i =0;i<n;i++){
        scanf("%s %d",mark,&tmp);
        printf("%c %d\n",mark[0],i);
        switch(mark[0]){
            case 'S':
                S[tmp] = 1;
                break;  
            case 'H':
                H[tmp] = 1;
                break;
            case 'C':
                C[tmp] = 1;
                break;
            case 'D':
                D[tmp] = 1;
                break;

        }
    }


    outPut(S,'S');
    outPut(H,'H');
    outPut(C,'C');
    outPut(D,'D');


}





// # include <iostream>
// using namespace std;

// int main(){
//     int n,tmp,S[13],H[13],C[13],D[13];
//     char mark;

//     for (int i=0;i<13;i++){
//         S[i] = H[i] = C[i] = D[i] =false;
//     }

//     cin >> n;


//     for (int i =0;i<n;i++){
//         cin >> mark >> tmp;

//         switch(mark){
//             case 'S':
//                 S[tmp] =true;
//             case 'H':
//                 H[tmp] =true;
//             case 'C':
//                 C[tmp] =true;
//             case 'D':
//                 D[tmp] =true;
//         }
//     }

//     return 0;
// }
