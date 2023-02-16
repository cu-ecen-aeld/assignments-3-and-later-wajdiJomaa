#!/bin/sh

if [ ! $# -eq 2 ] 
then echo "expected 2 arguments but $# was received"; exit 1
fi

mkdir -p "$(dirname $1)" && touch $1

if [ $? -eq 1 ]
then echo "file could not be created" ; exit 1
fi

echo $2 > $1