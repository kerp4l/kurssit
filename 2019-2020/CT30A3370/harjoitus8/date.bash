#!/bin/bash
set $(date) #initialize $1...$6 with the output of date
echo $* #display all "arguments"
echo -n "Give city for date: "
read city
echo $city, $2 $3, $6 #display date in pretty format

