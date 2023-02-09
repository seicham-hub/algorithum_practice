# include <iostream>
using namespace std;

int main(){
    int a,b,c,result=0;

    cin >> a >> b >> c;
    
    for (int i =a;i<b+1;i++){
        if (c%i ==0) result++;
    }

    cout << result << endl;
    return 0;
}
