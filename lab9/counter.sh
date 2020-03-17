#!/bin/bash

function savenum() {
   echo $1 > ~/count.txt
   #let "Q=$r+1"
}

function readnum(){
	if test -e ~/count.txt ; then
      x=`cat ~/count.txt`
      echo $x
   else
   	   echo 0
   fi	   
}

r=$(readnum)

let "Q=$r+1"
savenum $Q


if test $r -eq 0   ; then
	echo "Welcome to the PRISM computer environment "
	elif test $r -eq 1 ; then
		echo "Welcome back to the PRISM computer environment"
	elif test $r -eq 2 ; then
		echo "Welcome back to the PRISM computer environment, again"
	elif [ $r -gt 2  -a $r -lt 9 ]; then
		echo "You have been on the PRISM computer environment $Q times"
	elif [ $r -eq 9 -o $r -gt 9 ] ; then
		echo "You have been on the PRISM computer environment $Q times.Don't you have anything better to do?"
    #else 
    #	echo "nothing"
	fi	
exit

