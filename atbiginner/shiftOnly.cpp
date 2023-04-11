# include <iostream>
using namespace std;

int main(){
    int N,count=0;
    long long int Ai[200];
    bool flg=true;

    cin >> N;
    for(int i=0;i<N;i++) cin >>Ai[i];

    while(true){
        for(int i=0;i<N;i++){
            if(Ai[i]%2 ==0){
                Ai[i] = Ai[i]/2;
            } 
            else {
                flg=false;
                break;

            }
        }
        if (flg == false) break;
        count++;

    }

    cout << count << endl;


    return 0;
}
