#! /usr/bin/env bash
#
# gen_data.sh
# Copyright (C) 2014 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.
#

num_case=$1
max_num_item=$2
max_cap_knapsack=$3

for i in `seq 1 $num_case`; do

	num_item=$(($RANDOM % $max_num_item + 1))
	cap_knapsack=$(($RANDOM % $max_cap_knapsack + 1))

	echo "$num_item $cap_knapsack"

	for j in `seq 1 $num_item`; do
		weight=$(($RANDOM % $cap_knapsack + 1))
		value=$(($RANDOM % $cap_knapsack + 1))

		echo "$weight $value"
	done
done

