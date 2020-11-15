#!/bin/bash

if [ -z $1 ]
then
	echo "Usage:$0 <search_path>"
else
	mkdir -p data/data
	mkdir -p data/input

	if [ ! -f bin/input_generator ]
	then
		make bin/input_generator
	fi

	for ext in pdf mp3 jpg
	do
		./generate_data.sh $1 "$ext"
		mv data/result.txt data/data/$ext.txt

		echo "100" | ./bin/input_generator data/data/$ext.txt > data/input/$ext.in
	done
		

	./generate_data.sh $1 "*pp"
	mv data/result.txt data/data/cpp.txt

	echo "100" | ./bin/input_generator data/data/cpp.txt > data/input/cpp.in
fi
