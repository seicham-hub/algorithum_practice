// How many ways?
// 0218もう一度

#include <iostream>

using namespace std;

int main(){
    int n,x,result;

    while(true){
        result =0;
        cin >> n >> x;
        if (n==0&&x==0) break;

        for (int i =1;i<x/3 && i<=n-2;i++){
            // cout << i <<endl;
            for (int j = i+1; j<=n-1;j++){
                for (int k=j+1;k<=n;k++){
                    if(i+k+j == x) result += 1;
                 }
            }
        }

        cout << result << endl;

    }
    return 0;

}




// #include <stdio.h>
// #include <iostream>
// using namespace std;

// int main(){
//     int n,x,count;
//     while(true){
//         scanf("%d %d",&n,&x);
//         if(n ==0 && x==0) break;
//         count =0;
//         for(int min =1;min<x/3&&min<=n-2;min++){
//             // cout << "minです" << min <<  endl;
//             for(int middle = min+1;middle<x-(min+middle)&& middle<=n-1;middle++){
//                 //  cout << "middle" << middle <<  endl;
//                 //  cout << "x-min+middle" << x-(min+middle) <<  endl;
//                 if(x-(min+middle)<=n) ++count;
//             }
//         }
//         cout << count << endl;
//     }

// }

// # include <iostream>
// using namespace std;

// int main(){

//     int n,x,result;
//     while(true){
//         result =0;
//         cin >> n >> x;
//         if (n ==0 && x==0) break;

//         for (int i =1;i<=n;i++){
//             for (int j=i+1;j<=n;j++){
//                 for(int k=j+1;k<=n;k++){
//                     if(i+j+k ==x) result+=1;
//                 }
//             }

//         }
//         cout << result << endl;
//     }
//     return 0;
// }
