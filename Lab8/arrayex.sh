#!/bin/bash 
foo=(monday tuesday wednesday thursday friday saturday sunday) 
echo "${foo[@]}" 
unset foo[1] 
echo "${foo[@]}" 
foo[0]= 
echo "${foo[@]}"