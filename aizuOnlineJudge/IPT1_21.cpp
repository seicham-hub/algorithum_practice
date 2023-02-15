// Structured Programming

// 前置きインクリメントと後置きインクリメントの違い
// i = 1;
// j= ++i;  jは2
// j = i++; jは1

# include <iostream>
using namespace std;

int main(){
    int n,x;

    cin >> n;
    for (int i=1;i<= n;i++){
        x = i;
        if(x%3 == 0){
            cout << " " << i;
            if (i+1<=n) continue;
            else break;
        }
        

        while(x){
            
            if(x%10 ==3){
                cout << " " << i;
                break;
            }
            x /= 10;
            
        }

    }
    cout << endl;

}
