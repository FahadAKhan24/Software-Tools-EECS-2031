#!/bin/bash
gcc -ansi -pedantic is42.c -o is42

function isfourty(){
	
if [ $1 -eq 0 ] ; then
echo "is42 was passed the value 42"
else 
	echo "is42 was not passed the value 42"
fi

}

./is42 42
isfourty $?

./is42 not42
isfourty $?

./is42 
isfourty $?

exit
