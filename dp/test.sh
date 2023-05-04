#!/bin/bash

g++ -g -o $1 $1.cpp \
&& ./$1
exit 0