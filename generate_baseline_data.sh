#!/bin/bash

data=data/data/

if [ -z $1 ]
then
	echo "Usage:$0 <search_path>"
else
	mkdir -p data/data

	./generate_data.sh $1 "*pp"
	mv data/result.txt data/data/cpp.txt
	
	./generate_data.sh $1 "pdf"
	mv data/result.txt data/data/pdf.txt
	
	./generate_data.sh $1 "mp3"
	mv data/result.txt data/data/mp3.txt

	./generate_data.sh $1 "jpg"
	mv data/result.txt data/data/jpg.txt
fi
