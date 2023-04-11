#!/bin/bash

g++ -o $1 $1.cpp \
&& ./$1
exit 0