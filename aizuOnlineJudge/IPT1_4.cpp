# include <iostream>

using namespace std; 

int main(){
    int second;
    // int h;
    // int m;
    // int s;
    int s,h,m;
    cin >> second;

    h = second/3600;
    second = second%3600;
    m = second/60;
    second = second%60;
    s = second;

    cout << h <<":"<< m <<":"<< s <<endl;

}