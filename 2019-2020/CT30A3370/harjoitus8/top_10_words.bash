#!/bin/bash

# CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi
#  Harjoitus 8, tehtävä 6
# Topi Jussinniemi 0401301
# top_10_words.bash

cat $1 | tr " " "\n" | tr "[A-Z]" "[a-z]" > separate_lines.txt

sed '/^$/d' separate_lines.txt > no_empty_lines.txt

sort no_empty_lines.txt | uniq -c > counted.txt

sort -rn counted.txt  | head -10
