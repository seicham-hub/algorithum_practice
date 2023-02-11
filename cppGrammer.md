## 変数型
char 8ビット  
int  32 ビット　-2,147,483,648~2,147,483,647  
float 32ビット  3.4×10^-38~3.4×10^38  
double 64ビット 1.7×10^-308~3.4×10^308  
bool   1ビット　trueまたはfalse  
void  _        値なし  

※floatとdoubleは小数点を扱えるがfloatのほうが精度が低い。基本的にdoubleを使っておけばよい。  


## 変数宣言
int x;
int y = 5;

<!-- インクリメント,デクリメント -->
x++;
x--;

## 自動型変換
(int型)と(double型)等で演算する場合は、広義な方に型が自動変換される。代入の場合は代入する型に変換される。

例）
```
std::cout << 3*4.0; // 12.0

int x;
x = 3.14; // int型に変換される
```

明示的な型変換
```
 x = (int)3.14
```  

## 配列の宣言

```
// 5つint型を格納できる配列
int a[5];
// 初期値を与える場合
int a[5] = {10,2,3,58,-9}

a[0] = 10;


// 多次元配列の時
int a [2][3]


// サイズを動的に変える必要がある場合は

vector<string> v;
v = {"one","two","three"}

// 多次元配列の場合は要素数が必要　vector<型>(要素数,初期値)
vector<vector<string>> v(2,vector<int>(3));

```

## 関数の宣言  
```
// 戻り値の型、名前の順　引数も型、名前の順
double bekizyo(int &donuts){

}
```


### ポインタ
```
// ポインタを格納できる変数
int *intPointer;

int num = 25;
intPointer = &num;


std::cout << *intPointer << endl; // 25

```

関数に渡すとき  
参照渡し
```
void getOrder(int &donuts){
    cout << "何個のドーナツが欲しいですか？"
    cin >> donuts;
}

```  
ポインタ渡し
```
int number = 5;
showValue(&number)

void showValue(int *value){
    cout << value << endl; // numberのアドレスが表示される
}
```

### 小数の扱いについて  
doubleとfloat  
floatは4バイト　つまり32ビット　符号部に1ビット　仮数部に23ビット　指数部に8ビット
doubleは8バイト　つまり64ビット　符号部に1ビット　仮数部に52ビット　指数部に11ビット  

仮数e指数で計算される

1e2 = 1×10^2

1e-2 = 1×10^(-2)

### 競技プログラミングに役立ちそうなところ
```

// 文字列の長さ取得
cout << s.size() << endl;
cout << s.length() << endl;

//　並び替え
vector<int> v = {3,8,6,9,4,2,5,7};

// 昇順
sort(v.begin(),v.end());

// 降順
reverse(v.begin(),v.end());

// 重複削除
sort(v.begin(),v.end());
v.erase(unique(v.begin(),v.end()),v.end())

// pair (tupleの2つ版)
pair<int,string> p;
p = make_pair(1,"one");

cout << p.first << endll;
cout << p.second << endl;

// tuple(型が複数ある場合の配列)
tuple<int, string,char> t;
t = make_tuple(11,"eleven",'A');

cout << get<0>(t) << endl;
cout << get<1>(t) << endl;
cout << get<2>(t) << endl;

// map
map<string,int> fluits;
fluits["apple"] = 1;
fluits["banana"] = 2;
fruits["melon"] = 3;

for (const auto &item:fluits){
    cout << item.first << ":" << item.secont << endl;
}
// 出力結果
/* 
apple:1
banana:2
melon:3
*/

// マクロ
//マクロを使うと指定した文字列をプログラムの中で置き換えることができる。

#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    vector<int> v = {1,10,100};
    rep(i,v.size()) cout << v[i] << endl;
}


```