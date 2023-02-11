// 0209もう一度取り組む

#include <iostream>
using namespace std;

int main(){
    int x;
    for (int i =0;;i++){
        cin >> x;
        if (x == 0) break;

        cout << "Case " << i+1 <<": " << x << endl;
    }


    return 0;
}

// #include <iostream>

// using namespace std;

// int main(){
//     int x;
//     for (int i =0;;i++){
//         cin >> x;
//         if (x ==0) break;
//         cout << "Case " << i+1 << ": " << x << endl;
//     }
// }
