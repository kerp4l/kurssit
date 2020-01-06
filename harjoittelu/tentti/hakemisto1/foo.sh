if [ $2 -eq 0 ]
then
echo "Nollalla ei voi jakaa!"
else jaettava=$1
jakaja=$2
tulos=`expr $jaettava / $jakaja`
echo "Luku $jaettava jaettuna luvulla $jakaja saadaan tulokseksi $tulos"
fi
