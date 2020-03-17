#!/bin/bash
z=1
until test $z -eq 11;
do
	echo $z
	let "z=$z+1"
done

