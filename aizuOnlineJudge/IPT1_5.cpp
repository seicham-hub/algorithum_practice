# include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    // if (a < b){
    //     cout << "a < b" << endl;
    // }else if(a>b){
    //     cout << "a > b" << endl;
    // }else if(a == b){
    //     cout <<"a == b" << endl;
    // }
    cout << "a ";
    if(a<b) cout << "< ";
    if(a==b) cout << "== ";
    if(a>b) cout << "> ";
    cout << "b" <<endl;
    return 0;

}