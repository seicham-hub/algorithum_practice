#!/bin/bash

touch beginner_$1.cpp \
 && code beginner_$1.cpp

cat << EOS > beginner_$1.cpp
# include <iostream>
using namespace std;

int main(){
    cin >>

    return 0;
}

EOS

exit 0