// 0410もう一度
// 0411もう一度

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int N,aliceP=0,bobP=0;
    vector<int> a;
    cin >> N;
    a.resize(N);
    for(int i=0;i<N;i++) cin >>a[i] ;

    sort(a.begin(),a.end(),greater<int>());

    for (int i=0;i<N;i++){

        if (i%2 ==0) aliceP += a[i];
        else bobP += a[i];
    }

    cout << aliceP-bobP << endl;

    return 0;
}

// # include <iostream>
// using namespace std;

// int main(){
//     int N,ai[101]={},max=-1,aliceP=0,bobP=0;
//     cin >> N;
//     for(int i=1;i<=N;i++) {
//         cin >> ai[i];
//     }


//     for(int i=1;i<=N;i++){

//         max =-1;
//         int index = 0;
//         for(int j=1;j<=N;j++){
//             if(max < ai[j]) {
//                 max = ai[j];
//                 index = j;
//             }
//         }

//         ai[index] =0;

//         if (i%2 == 1) aliceP += max;
//         else bobP += max;
//     }

//     cout << aliceP-bobP << endl;

    
//     return 0;
// }
