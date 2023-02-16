#!/bin/sh

if [ ! $# -eq 2 ] 
then echo "expected 2 arguments but $# was received"; exit 1
fi

if [ ! -d $1 ]
then echo "$1 is not a directory"; exit 1 
fi 

number_of_files=$(find $1 -type f | wc -l )
matching_lines=$( grep -r $2 $1 | wc -l )

echo "The number of files are $number_of_files and the number of matching lines are $matching_lines" 