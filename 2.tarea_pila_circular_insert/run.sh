#!/usr/bin/bash

g++ -c List.cc main.cpp
g++ List.o main.o -o main
./main
