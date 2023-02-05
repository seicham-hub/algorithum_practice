# include <iostream>

int triple(int x){
    int result = x;
    for (int i = 0; i<2;i++){
        result = result*x;
    }

    return result;
}

int main(){
    int N;
    int result;
    std::cin >> N;
    result = triple(N);
    
    std::cout << result << std::endl;
}

