#!/bin/bash

g++ -o beginner_$1 beginner_$1.cpp \
&& ./beginner_$1
exit 0