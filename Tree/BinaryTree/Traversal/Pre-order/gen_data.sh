#! /usr/bin/env bash
#
# gen_data.sh
# Copyright (C) 2014 KuoE0 <kuoe0.tw@gmail.com>
#
# Distributed under terms of the MIT license.
#

num_case=$1
max_num_node=$2

for i in `seq 1 $num_case`; do

	num_node=$(($RANDOM % $max_num_node + 1))

	echo "$num_node"

	for j in `seq 1 $num_node`; do
		value=$(($RANDOM % ($num_node * 10) + 1))

		echo "$value"
	done
done

