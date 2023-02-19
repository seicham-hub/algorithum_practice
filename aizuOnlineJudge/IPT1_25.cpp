// Matrix Vector Multiplication
// 0218もう一度やる

#include <iostream>
using namespace std;

int main(){
    int n,m;
    int i,j,k;
    int mat[100][100] ={};
    int ve[100] ={};
    cin >> n >>m;
    for (i =0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }
    for (j=0;j<m;j++) cin >> ve[j];

    for (i=0;i<n;i++){
        int x =0;
        for (j=0;j<m;j++) x+= mat[i][j]*ve[j];
        cout << x <<endl;
    }
}


// # include <iostream>
// using namespace std;

// int main(){
//     int n,m;
//     cin >> n >> m;

//     int a[n][m],b[m],c[n];

//     for (int i =0;i<n;i++) c[i] =0;

//     for (int i =0;i<n;i++){
//         for (int j=0;j<m;j++) cin >> a[i][j];
//     }

//     for (int i=0;i<m;i++){
//         cin >> b[i];
//     }
//     for (int i =0;i<n;i++){
//         for (int j=0;j<m;j++){
//             c[i] += a[i][j]*b[j];   
//         }
//         cout << c[i] << endl;
//     }

//     return 0;
// }
