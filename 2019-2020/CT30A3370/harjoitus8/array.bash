#!/bin/bash
#array.bash - demonstrate array variables
names=(Carrie Sam Charlotte Miranda)
echo "${names[1]} has ${#names[1]} letters"
echo -n "The array has ${#names[@]} elements: "
names[1]=Samantha
last=‘expr ${#names[@]} - 1‘
for i in ‘seq 0 $last‘ ; do
echo -n "${names[i]} "
done; echo
echo " Listed in an easier way: ${names[@]}"
A_arr=("${names[@]}"); B_arr=("${names[*]}")
declare -a | grep _arr

