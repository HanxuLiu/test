#!/bin/sh

#================================================================
#
#  Author: LiuHanxu
#  Date: 2023-01-06
#  Description: 
#================================================================

export LD_LIBRARY_PATH=/home/lhx/boost/boost167/install/lib:$LD_LIBRARY_PATH

g++ -o test test.cpp -lboost_coroutine -lboost_context -L/home/lhx/boost/boost167/install/lib -I/home/lhx/boost/boost167/install/include
./test

g++ -o demo1 demo1.cpp -lboost_coroutine -lboost_context -L/home/lhx/boost/boost167/install/lib -I/home/lhx/boost/boost167/install/include
./demo1

g++ -o demo2 demo2.cpp -lboost_coroutine -lboost_context -L/home/lhx/boost/boost167/install/lib -I/home/lhx/boost/boost167/install/include
./demo2

g++ -o demo3 demo3.cpp -lboost_coroutine -lboost_context -L/home/lhx/boost/boost167/install/lib -I/home/lhx/boost/boost167/install/include
./demo3

g++ -o demo4 demo4.cpp -lboost_coroutine -lboost_context -L/home/lhx/boost/boost167/install/lib -I/home/lhx/boost/boost167/install/include
./demo4
