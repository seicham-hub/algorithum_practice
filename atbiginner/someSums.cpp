
#include <iostream>

using namespace std;

int main(){
    int N,A,B,keta[5],num,sum=0,tempSum;

    cin >> N >> A >>B;

    for (int i=1;i<=N;i++){

        tempSum =0;
        num = i;
        keta[4] = num/10000;
        num = num%10000;

        keta[3] = num/1000;
        num =num%1000;

        keta[2] = num/100;
        num = num%100;

        keta[1] = num/10;
        num = num%10;

        keta[0] = num;

        for (int j=0;j<5;j++) tempSum+=keta[j];

        if (tempSum >=A &&tempSum <=B) sum+=i;
    }
    cout << sum <<endl;


    return 0;
}

// 自分で書いたもの↓

// # include <iostream>
// # include <stdio.h>
// # include <string>
// using namespace std;

// int main(){

//     int N,A,B,sum=0;
//     string curNum;

//     cin >> N >> A >> B;

//     for (int i=1;i<=N;i++){
//         curNum = to_string(i);
//         int tempSum =0;
//         for(int j=0;j<curNum.size();j++){
            
//             tempSum += curNum[j]-'0';
//         }
       

//         if(tempSum >=A && tempSum <=B) sum+=i;
//     }

//     cout << sum << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;
 
 
// int main(){
// 	int n, a, b,keta[5],n_sum,num,sum;
// 	cin >> n >> a >> b;
// 	sum = 0;
// 	for (int i = 1; i <= n;i++) {
// 		num = i;
// 		keta[4] = num / 10000;
// 		num %= 10000;
// 		keta[3] = num / 1000;
// 		num %= 1000;
// 		keta[2] = num / 100;
// 		num %= 100;
// 		keta[1] = num / 10;
// 		num %= 10;
// 		keta[0] = num;
 
// 		n_sum = keta[4] + keta[3] + keta[2] + keta[1] + keta[0];
 
// 			if(n_sum >= a && n_sum <= b) sum += i;
// 	}
 
 
// 	cout << sum << endl;
// 	return 0;
// }