#~/bin/sh
#
#
# File name     : build.sh
# Description   : This script tells how to build the code files under SOLID directory.
#

g++ -std=c++17 SRP.cpp -o SRP

g++ -std=c++17 OCP.cpp -o OCP

g++ -std=c++17 LSP.cpp -o LSP