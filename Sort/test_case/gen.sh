#!/usr/bin/env zsh

for (( i = 0; i < 100; ++i )); do
	echo $1
	for (( j = 0; j < $1; ++j )); do
		num=$(( $RANDOM + $RANDOM ))

		if [ $2 -ne 0 ]; then
			num=$(( $num % $2 ))
		fi

		if [ $(( $RANDOM % 2 )) -eq 1 ]; then
			echo $(( $num * -1 ))
		else
			echo $num
		fi
	done
done
