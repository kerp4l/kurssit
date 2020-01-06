#!/bin/bash

tulos=`expr $1 / $2`

echo "Luku $1 jaetaan luvulla $2 saadaan tulokseksi $tulos"

for ((i=0 ; i < $tulos; i++))
do echo "Tämä on kieeors numero: $i"
done

muuttuja=69

echo muuttuja
