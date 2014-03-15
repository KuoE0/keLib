#
# makefile
# KuoE0, 2014-03-15 00:01
#

all: topdown bottomup bottomup1d

topdown: knapsack.cpp
	g++ -o knapsack_topdown knapsack.cpp -DTOPDOWN -std=c++11

bottomup: knapsack.cpp
	g++ -o knapsack_bottomup knapsack.cpp -DBOTTOMUP -std=c++11

bottomup1d: knapsack.cpp
	g++ -o knapsack_bottomup1d knapsack.cpp -DBOTTOMUP1D -std=c++11

# vim:ft=make
#

