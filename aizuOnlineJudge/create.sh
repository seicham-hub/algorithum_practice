#!/bin/bash
# 上の記述はbashを使用するため

touch IPT1_$1.cpp \
 && code IPT1_$1.cpp

cat << EOS > IPT1_$1.cpp
# include <iostream>
using namespace std;

int main(){

    cin >> 

    return 0;
}
EOS

exit 0