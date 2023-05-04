#!/bin/bash

if [ -d $1 ]; then
    echo "すでにディレクトリが存在しています"
else
    mkdir $1
    cp BFS/create.sh BFS/test.sh $1/
    cd $1/
fi

exit 0
