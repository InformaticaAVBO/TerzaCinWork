#
# A simple makefile for compiling a c++ project
#

.DEFAULT_GOAL := main.cpp

all: clean test

CoinFlipper.cpp: 
    gcc -o ./target/main.out ./src/main/CoinFlipper.cpp

run: CoinFlipper.cpp
    ./target/CoinFlipper.out 10

test: CoinFlipper.cpp
    ./target/CoinFlipper.out 10000

clean: 
    rm -rf ./SlotMachine/*.out