// Spreadsheet
// 0312もう一度

#include <iostream>

using namespace std;

int main(){
    int r,c,rowArr[101]={},current;
    cin >> r >> c;

    for (int i=0;i<r;i++){
        int sum =0;
        for (int j=0;j<c;j++){
            cin >> current;
            sum += current;
            rowArr[j] += current;
            cout << current << " ";
        }
        cout << sum << endl;
        rowArr[c] += sum;  
    }

    for(int i=0;i<c;i++){
        cout << rowArr[i] << " ";
    }
    cout << rowArr[c] << endl;

    return 0;
}


// # include <iostream>
// using namespace std;

// int main(){

//     int r,c,rowSum=0;
//     int arr[100],lastRow[101]={};

//     cin >> r >> c;

//     for(int i=0;i<r;i++){

//         rowSum = 0;
//         for(int j =0;j<c;j++){


//             cin >> arr[j];

//             rowSum += arr[j];
//             lastRow[j] += arr[j];

//             cout << arr[j] << " ";
//         }
//         lastRow[c] += rowSum;
//         cout << rowSum << endl;
//     }
//     for(int i=0;i<c;i++){
//         cout << lastRow[i] << " ";
//     }
//     cout << lastRow[c] << endl;

//     return 0;
// }
