jaettava=$1
jakaja=$2
tulos=`expr $1 / $2`
echo " "
echo "LASKU: $jaettava / $jakaja = $tulos"
echo " "


for ((i=0 ; i < $tulos; i++))
do
kierros=`expr $i + 1`
jaettava=`expr $jaettava - $jakaja`
echo "Kierroksen numero on: $kierros ja erotus on $jaettava"
done
