// Official House
// 0218もう一度
// 0223もう一度
// b棟f階のr番目の部屋にv人が追加で入居したことを示します。vが負の値の場合、-v人退去したことを示します。


#include <iostream>

using namespace std;

int main(){
    int n,b,f,r,v;
    int tower[5][4][11] = {{{}}};

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> b >> f >> r >> v;
        tower[b][f][r] += v;
    }


    for (int i=1;i<=4;i++){
        for(int j=1;j<=3;j++){
            for (int k=1;k<=10;k++) cout <<" " << tower[i][j][k];
            cout << endl;
        }
        if (i!=4) cout << "####################" << endl;
    }
}


// # include <iostream>
// using namespace std;

// int main(){

//     int n,b,f,r,v;

//     int tower[4][3][10];
//      // これでok
//     int build[4][3][10]={{{}}};

//     for (int i =0;i<4;i++){
//         for (int j=0;j<3;j++){
//             for(int k=0;k<10;k++){
//                 tower[i][j][k] =0;
//             }
//         }
//     }

//     cin >> n;

//     for (int i=0;i<n;i++){
//         cin >> b >> f >>r >>v;
//         tower[b-1][f-1][r-1] += v;

//     }

//     for (int i =0;i<4;i++){
//         for (int j=0;j<3;j++){
//             for(int k=0;k<10;k++){
//                 cout << " " <<tower[i][j][k];
//             }
//             cout << endl;
//         }
//         if (i !=3) cout << "####################" << endl;
//     }


//     return 0;
// }
