// ITP1_5_A:   Print a Rectangle
#include <stdio.h>
#include <algorithm>

int main(){
    int H,W;
    while(true){
        scanf("%d %d",&H,&W);
        if (H ==0 && W==0) break;
        for (int i =0;i<H;i++){
            for(int j =0;j<W;j++){
                printf("#");
            }
            printf("#");
        }
        printf("#");
    }
}



// # include <iostream>
// using namespace std;

// int main(){
//     int H,W;

//     for (int i=0;;i++){
//         cin >> H >> W;
//         if (H==0 && W ==0) break;

//         for (int j =0;j<H;j++){
//             for(int k=0;k<W;k++){
//                 cout << "#";
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

//     return 0;
// }
