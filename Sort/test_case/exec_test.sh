#!/usr/bin/env zsh
REPORTTIME=0

for filename in `ls`; do
	if [ $filename =~ "100.in" ]; then
		echo $filename
	fi
done
