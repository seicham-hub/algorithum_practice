// 0410もう一度

// https://atcoder.jp/contests/abc297/tasks/abc297_d

// 問題文の操作をそのまま実行すると、例えばA=10^18,B=1の時に
// 制限時間オーバー

// 割り算の商とあまりを用いて計算
// 計算量は一回の操作でAが半分未満になるためO(logA+logB)

#include <bits/stdc++.h>

using namespace std;

int main(){

    long long int A,B,ans=0;

    cin >> A >> B;
    if(A<B) swap(A,B);

    while(B!=0){
        ans += A/B;
        A %= B;
        swap (A,B);
    }

    cout << ans-1 <<endl;

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     long long a,b;

//     cin >> a >> b;
//     long long ans =0;

//     if(a<b) swap(a,b);
//     while(b>0){
//         ans+= a/b;
//         a %=b;
//         swap(a,b);
//     }
//     cout << ans-1 <<endl;

//     return 0;
// }
