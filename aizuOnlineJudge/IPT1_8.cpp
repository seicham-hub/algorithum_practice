// もう一度取り組む02/09
// 0211もう一度取り組む

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int array[3];
    cin >> array[0] >> array[1] >> array[2];


    for (int i=2;i>0;i--){
        for(int j=0;j<i;j++){
            if (array[j]>array[j+1]) swap(array[j],array[j+1]);
        }
    }

    cout <<array[0]<<" "<<array[1]<<" "<<array[2] << endl;
}

// #include <stdio.h>
// #include <algorithm>
// using namespace std;

// int main(){
//     int array[3];
//     // %d int,short型　%c char型 %s char*(文字列)　%f float型 %lf double型
//     for (int i=0;i<3;i++) scanf("%d",&array[i]);

//     for (int i=2;i>0; i--){

//         for (int j =0;j<i ;j++){
//             if (array[j] > array[j+1]) swap(array[j],array[j+1]);
//         };
//     };

//     printf("%d %d %d\n",array[0],array[1],array[2]);
// }


// #include <iostream>

// using namespace std;

// int main(){

//     int a,b,c,buf;

//     if(a >b){
//         buf = a;
//         a = b;
//         b = buf;
//     }
//     if(b>c){
//         buf = b;
//         b =c;
//         c = buf;
//     }
//     if(a>b){
//         buf = a;
//         a = b;
//         b = buf;
        
//     }
//     cout << a << " " << b << " " << c<< endl;

//     return 0;
// }

// int max (int q,int r){
//     if (q>r) return q;
//     return r;

// }
// int main(){
//     int a,b,c,l,m,h;
//     string result;

//     cin >> a >> b >> c;

//     m = max(a,b);
//     h = max(m,c);


//     if (h == a){
//         m = max(b,c);
//         if (m==b) l = c;
//         else l =b;
//     }else if (h ==b){
//         m= max(a,c);
//         if (m==a) l=c;
//         else l=a;
//     }else if(h ==c){
//         m = max(a,b);
//         if (m==a) l=b;
//         else l=a;
//     }
   

//     ostringstream s1,s2,s3;
//     s1 << h;
//     s2 << m;
//     s3 << l;
//     result = s3.str() +" "+s2.str()+" "+s1.str();


//     cout << result <<endl; 
// }
