// TODO:0213もう一度取り組む
// 	ITP1_5_B:   Print a Frame

# include <stdio.h>
# include <algorithm>

int main(){
    int H,W;

    scanf("%d %d",&H,&W);
    for (int i =0;i<W;i++) printf("#");
    printf("\n");

    for (int i=1;i<H-1;i++){
        printf("#");
        for (int j=1;j<W-1;j++) printf(".");
        printf("#\n");
    }

    if(H>1){
        for (int i=0;i<W;i++) printf("#");
        printf("\n");
    }
    printf("\n");
    

}


// # include <iostream>
// using namespace std;

// int main(){
//     int H,W;

//     while(true){
//         cin >> H >> W;
//         if (H ==0&& W==0) break;
//         for (int i =0;i<H;i++){
//             for (int j=0;j<W;j++){
//                 if(i ==0 || i==H-1) {
//                     cout << "#";
//                 }else{
//                     if (j==0 || j==W-1) cout << "#";
//                     else cout << ".";
//                 }
//             }
//             cout << endl;
//         }
//         cout << endl;
//     }

    
//     return 0;
// }
