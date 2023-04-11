// 0411もう一度

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, y;
    cin >> n >> y;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int k = n - i - j;
            int total = 10000 * i + 5000 * j + 1000 * k;
            if (total == y)
            {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;
    return 0;
}

// 自分が書いたコード
// n^3だからめちゃ遅い

// #include<bits/stdc++.h>
// using namespace std;

// void keisan(int N,int Y,int arr[3]){
//     int manP,gosenP,senP,result[3];
//     for (int i=N;i>=0;i--){
//         manP= 10000*i;
//         if(manP > Y) continue;
//         for(int j=N;j>=0;j--){
//             gosenP = 5000*j;
//             if(manP+gosenP > Y) continue;
//             for(int k=0;k<=N;k++){
//                 senP=1000*k;
//                 if(Y == manP+gosenP+senP && i+k+j == N) {
//                     arr[0] =i;
//                     arr[1] =j;
//                     arr[2] =k;
//                     return;
//                 };
//                 if(manP+gosenP+senP>Y) break;
//             }
//         }
//     }
// }

// int main(){
//     int N,Y,result[3] ={-1,-1,-1};
//     cin >> N >> Y;

//     keisan(N,Y,result);

//     cout << result[0] <<" "<<result[1] <<" " <<result[2];

//     return 0;
// }
