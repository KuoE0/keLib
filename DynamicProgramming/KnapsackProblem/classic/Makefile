#
# makefile
# KuoE0, 2014-03-15 00:01
#

all: topdown bottomup bottomup1d

topdown: knapsack.cpp
	g++ -o topdown knapsack.cpp -DTOPDOWN -std=c++11

bottomup: knapsack.cpp
	g++ -o bottomup knapsack.cpp -DBOTTOMUP -std=c++11

bottomup1d: knapsack.cpp
	g++ -o bottomup1d knapsack.cpp -DBOTTOMUP1D -std=c++11

test: topdown bottomup bottomup1d
	./gen_data.sh 100 100 1000 > knapsack.in
	./topdown < knapsack.in > topdown.out
	./bottomup < knapsack.in > bottomup.out
	./bottomup1d < knapsack.in > bottomup1d.out

clean:
	rm knapsack.in topdown bottomup bottomup1d topdown.out bottomup.out bottomup1d.out

# vim:ft=make
#

