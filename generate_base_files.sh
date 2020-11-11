#!/bin/bash

if [ -z $1 ]
then
	echo "Usage:$0 <search_path>"
else
	./generate_data.sh $1 "*pp"
	mv data/data.txt data/cpp.txt
	
	./generate_data.sh $1 "pdf"
	mv data/data.txt data/pdf.txt
	
	./generate_data.sh $1 "mp3"
	mv data/data.txt data/mp3.txt
fi
