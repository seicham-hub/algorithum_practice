//Finding Missing Cards
// 0214もう一度

# include <stdio.h>

using namespace std;

int main(){
    char mark;
    int n,S[14],H[14],C[14],D[14],tmp;
    for(int i=0;i<14;i++) S[i] =H[i] =C[i] =D[i] =0;
    scanf("%d",&n);


    for (int i=0;i<n;i++){
        scanf("%c %d",&mark,&n);
        
    }
}

// # include <iostream>
// using namespace std;

// int main(){
//     int n,tmp,S[14],H[14],C[14],D[14];
//     char mark;

//     for (int i=0;i<14;i++){
//         S[i] =0;
//         H[i] =0;
//         C[i] = 0;
//         D[i] = 0;
//     }

//     cin >> n;


//     for (int i =0;i<n;i++){
//         cin >> mark >> tmp;

//         switch(mark){
//             case 'S':
//                 S[tmp] =1;
//                 break;
//             case 'H':
//                 H[tmp] =1;
//                 break;
//             case 'C':
//                 C[tmp] =1;
//                 break;
//             case 'D':
//                 D[tmp] =1;
//                 break;
//         }
//     }


//     for (int i=1;i<14;i++){
//         if (!S[i]) cout << "S" << " " << i << endl;
//     }
//     for (int i=1;i<14;i++){
//         if (!H[i]) cout << "H" << " " << i << endl;
//     }
//     for (int i=1;i<14;i++){
//         if (!C[i]) cout << "C" << " " << i << endl;
//     }
//     for (int i=1;i<14;i++){
//         if (!D[i]) cout << "D" << " " << i << endl;
//     }

//     return 0;
// }
