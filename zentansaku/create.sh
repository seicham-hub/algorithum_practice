#!/bin/bash

if [ -e $1.cpp ]; then
    echo "すでにファイルが存在しています"
else
    touch $1.cpp &&
        code $1.cpp

    cat <<EOS >$1.cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    cin >>

    return 0;
}

EOS

fi

exit 0
