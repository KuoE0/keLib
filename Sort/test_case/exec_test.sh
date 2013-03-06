#!/usr/bin/env zsh
REPORTTIME=0
for filename in `ls`; do
	if [[ $filename =~ ".*\.in" ]]; then
		echo $filename
		time ./$1 < $filename > /tmp/temp.out
	fi
done
