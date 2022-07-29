#!/bin/bash

cd ./core

echo "building..."
g++ -c -o main.o main.cpp

g++ -o ../build/main main.o -Wall -std=c++17

rm -rf *.o
echo "done building..."
cd ..

echo "running.."
./build/main
