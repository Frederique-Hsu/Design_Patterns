#~/bin/sh
#
#
# File name     : build.sh
# Description   : This script tells how to build the code files under SOLID directory.
#

g++ -std=c++17 SRP.cpp -o SRP.o

g++ -std=c++17 OCP.cpp -o OCP.o

g++ -std=c++17 LSP.cpp -o LSP.o

g++ -std=c++17 ISP.cpp -o ISP.o

g++ -std=c++17 DIP.cpp -o DIP.o
