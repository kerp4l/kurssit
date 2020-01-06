#!/bin/bash
#checkargs
if [ $# -eq 0 ]
then
echo "Usage: chkargs: chkargs argument ..." 1>&2
exit 1
elif [ $# -eq 1 ]
then
echo "1 argument given"
else
echo "$# arguments given"
fi
exit 0

