// 0209もう一度取り組む

# include <iostream>
# include <stdio.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    double fa = a,fb=b;

    // cout << a/b << " " << a%b << " " << fa/fb << endl;
    printf("%d %d %.5f",a/b,a%b,fa/fb);

    return 0;
}
