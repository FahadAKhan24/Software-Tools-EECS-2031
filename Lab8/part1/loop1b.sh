#!/bin/bash
z=1
while test $z -le 10 ; 
do
	echo $z
	let "z=$z+1"
done

