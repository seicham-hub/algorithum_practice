# include <iostream>
using namespace std;

int main(){

    int A,B,C,X,TP500,TP100,TP50,way=0;

    cin >> A >> B >> C >> X;

    for(int i=0;i<=A;i++){
        TP500 = 500*i;
        if (X-TP500 <0) break;
        for(int j=0;j<=B;j++){
            TP100 = 100*j;
            if(X-(TP500+TP100)<0) break;
            for(int k=0;k<=C;k++){
                TP50=50*k;
                if(X-(TP500+TP100+TP50) ==0) way++;
                if(X-(TP500+TP100+TP50)<0) break;
            }
        }
    }

    cout << way << endl;

    return 0;
}
