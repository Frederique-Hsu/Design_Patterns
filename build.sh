#!/bin/sh 
#
#   File name   : build.sh
#   Description : This shell script tells how to build the program.
#

g++ Recurring_Template_Pattern.cpp -std=c++17 -o Recurring_Template_Pattern.o

g++ Mixin_Inheritance.cpp -std=c++17 -o Mixin_Inheritance.o

g++ Properties.cpp -std=c++17 -o Properties.o
