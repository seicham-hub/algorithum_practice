//Finding Missing Cards
// 0214もう一度

# include <iostream>
using namespace std;

int main(){
    int n,tmp,S[13],H[13],C[13],D[13];
    char mark;

    for (int i=0;i<13;i++){
        S[i] = H[i] = C[i] = D[i] =false;
    }

    cin >> n;


    for (int i =0;i<n;i++){
        cin >> mark >> tmp;

        switch(mark){
            case 'S':
                S[tmp] =true;
            case 'H':
                H[tmp] =true;
            case 'C':
                C[tmp] =true;
            case 'D':
                D[tmp] =true;
        }
    }

    return 0;
}
