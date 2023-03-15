// Matrix Multiplication
// 0312もう一度

#include <iostream>
using namespace std;

int main(){
    int n,m,l,a[100][100],b[100][100];

    cin >> n >> m >> l;

    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    for (int i=0;i<m;i++){
        for(int j=0;j<l;j++){
            cin >> b[i][j];
        }
    }

    for (int i=0;i<n;i++){
        for(int j=0;j<l;j++){
            long long int Cij = 0;
            for(int k=0;k<m;k++) Cij +=a[i][k]*b[k][j];
            if(j!=l-1) cout << Cij << " ";
            else cout << Cij;
        }
        cout << endl;
    }

    return 0;
}

// # include <iostream>
// using namespace std;

// int main(){

//     int n,m,l,a[100][100],b[100][100],c[100][100];

//     cin >> n >> m >> l;

//     for (int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin >> a[i][j];
//         }
//     }
//     for (int i=0;i<m;i++){
//         for(int j=0;j<l;j++){
//             cin >> b[i][j];
//         }
//     }



//     for (int i=0;i<n;i++){
//         for(int j=0;j<l;j++){
//             long long int sum =0;
//             for(int k=0;k<m;k++){
//               sum +=  a[i][k]*b[k][j];
//             }
//             if (j != l-1) cout << sum << " ";
//             else cout << sum ;
//         }

//         cout << endl;
//     }


//     return 0;
// }
