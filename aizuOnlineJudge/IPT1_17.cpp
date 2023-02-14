// ITP1_4_D:   Min, Max and Sum
//0213もう一度


#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int n,max_num=-1000001,min_num=1000001,tmp;
    long long int sum=0;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        sum +=tmp;
        max_num = max(max_num,tmp);
        min_num = min(min_num,tmp);
    }

    printf("%d %d %lld\n",min_num,max_num,sum);

}


// # include <iostream>
// using namespace std;

// int 型とlong型 と longlong 型
// sizeof(int) <= sizeof(long) <= sizeof(longlong)
// intは16ビットまたは32ビット
// longは㉜ビットまたは64ビット
// long long 64ビット
// 16ビットの時表現できる数は2^16-1 = 65535 ~65535
// atcoderのintは32ビット　-20億~20億ほど




// int main(){
//     int n;
//     long long currentNum,max,min,sum;
//     cin >> n;

//     for (int i =0;i<n;i++){
//         cin >> currentNum;
//         if(i == 0){
//             min = currentNum;
//             max = currentNum;
//             sum =  currentNum;
//             continue;
//         }
//         if (currentNum < min) min = currentNum;
//         if (currentNum >max) max = currentNum;
//         sum += currentNum;
//     }

//     cout << min <<" "<< max << " "<<sum <<endl;
//     return 0;
// }
