#
# Makefile
# KuoE0, 2014-03-17 22:01
#

all: recursive morris

recursive: post-order.cpp
	g++ -o recursive post-order.cpp -DRECURSIVE_METHOD -std=c++11

morris: post-order.cpp
	g++ -o morris post-order.cpp -DMORRIS_METHOD -std=c++11

test: recursive morris
	./gen_data.sh 100 100 > binary_tree.in
	./recursive < binary_tree.in > recursive.out
	./morris < binary_tree.in > morris.out

clean:
	rm recursive morris *.out

# vim:ft=make
#

