# include <iostream>
using namespace std;

int main(){
    int n,currentNum,max,min,sum;
    cin >> n;

    for (int i =0;i<n;i++){
        cin >> currentNum;
        if(i == 0){
            min = currentNum;
            max = currentNum;
            sum =  currentNum;
            continue;
        }
        if (currentNum < min) min = currentNum;
        if (currentNum >max) max = currentNum;
        sum += currentNum;
    }

    cout << min <<" "<< max << " "<<sum <<endl;
    return 0;
}
