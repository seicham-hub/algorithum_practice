// TODO:もう一度取り組む0213
// ITP1_5_C:   Print a Chessboard

#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int H,W;
    while(true){
        scanf("%d %d",&H,&W);
        if(H == 0 && W == 0) break;

        for (int i=0;i<H;i++){
            for (int j=0;j<W;j++){
                if ((i+j)%2 == 0) printf("#");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
    }
}


// # include <iostream>
// using namespace std;

// int main(){
//     int H,W;

    

//     while(true){
//         cin >> H >> W;
//         if (H ==0 && W ==0) break;

//         for (int i = 0;i<H;i++){

//             if (i%2 == 1) {
//                 for (int j=0;j<W;j++){
//                     if (j%2==1) cout << "#";
//                     else cout << ".";
//                 }
//                 cout << endl;
//             }

//             if(i%2 ==0){
//                 for (int k=0;k<W;k++){
//                     if(k%2==1) cout << ".";
//                     else cout << "#";
//                 }
//                 cout << endl;
//             }
    
//         }
//         cout << endl;
//     }

//     return 0;
// }
