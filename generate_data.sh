#!/bin/bash

if [ -z "$1" ] || [ -z "$2" ] || [ ! -z "$3" ]
then
	echo "Usage:$0 <search_path> <extension>"
else
	find $1 -name "*.$2" > data/data.txt
fi
