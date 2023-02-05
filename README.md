# C++ インストール手順

ubuntuにはデフォルトでコンパイラのgcc,g++がインストールされている。

```
    gcc --version
    g++ --version
```

build-essentialは開発に必要なパッケージ一式  
中身はg++,gcc,make,libc6-dev等  
[詳細はこちら](https://packages.ubuntu.com/ja/bionic/build-essential)
```
    sudo apt install build-essential
```

  
## gcc,g++の違い

#### gcc (GNU C Compiler)
*.cファイルはCとして、*.cppファイルはC++としてコンパイル

#### g++ (GNU C++ Compiler)
実体はgccにオプションを付けて呼び出したものと同じ。
*.cファイルも、*.cppファイルもC++としてコンパイル