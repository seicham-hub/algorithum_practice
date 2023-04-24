#!/bin/bash

touch $1.cpp \
 && code $1.cpp

cat << EOS > $1.cpp
# include <bits/stdc++.h>
using namespace std;

int main(){

    cin >> 

    return 0;
}
EOS

exit 0

