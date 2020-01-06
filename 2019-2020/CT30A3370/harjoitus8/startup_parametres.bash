#!/bin/bash

# CT30A3370 Käyttöjärjestelmät ja systeemiohjelmointi 
# Harjoitus 8, tehtävä 4
# Topi Jussinniemi 0401301
# startup_parametres.bash

# Environment variables
echo "Environment variables:"
printenv

# Positional parametres
echo "Positional parametres:"
for i in "$@"
do
	echo $i
done


# Special parametres
echo "Special parametres:"
#!/bin/bash
echo "\$!:"
echo $!
echo "\$$:"
echo $$
echo "\$#:"
echo $#
echo "\$0:"
echo $0
echo "\$-:"
echo $-
echo "\$?:"
echo $?
echo "\$_:"
echo $_
echo "\$@:"
echo $@
echo "\$*:"
echo $*
