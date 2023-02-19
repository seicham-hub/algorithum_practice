// Grading
// 0218もう一度

#include <stdio.h>

using namespace std;

int main(){
	int m,f,r;
	char grade;
	while(true){
		scanf("%d %d %d",&m,&f,&r);
		if(m == -1 && f == -1 && r == -1) break;
		if(m == -1 || f == -1){
			grade = 'F';
		}else if(m+f >= 80){
			grade = 'A';
		}else if(m+f >= 65){
			grade = 'B';
		}else if(m+f >= 50){
			grade = 'C';
		}else if(m+f >= 30){
			grade = (r >= 50)? 'C':'D';
		}else{
			grade = 'F';
		}
		printf("%c\n",grade);
	}
}

// # include <iostream>
// using namespace std;

// int main(){

//     int m,f,r;

//     while(true){

//         cin >> m >> f >> r;
//         if (m == -1 && f==-1 && r== -1) break;

//         if ((m==-1 || f==-1) || (m+f <30 )) {
//             cout << "F" << endl; 
//             continue;
//         }

//         if (m+f >=80) {
//             cout << "A" << endl; 
//             continue;
//         }
//         if (m+f <80 && m+f >=65) {
//             cout << "B" << endl; 
//             continue;
//         }
//         if (m+f >=50 && m+f <65) {
//             cout << "C" << endl; 
//             continue;
//         }
//         if (m+f >=30 && m+f <50) {
//             if (r >= 50) cout << "C" << endl;
//             else cout << "D" << endl; 
//             continue;
//         }
        

//     }

//     return 0;
// }
