#!/bin/sh

touch /plutus.conf

x=$REMOTES
OLD_IFS=$IFS    # save internal field separator
IFS=","         # set it to '+'
set -- $x       # make the result positional parameters
IFS=$OLD_IFS    # restore IFS
for i in "$@"; do # access each element of array
    echo "addnode = $i" >> /plutus.conf
done

echo "port = 11011" >> /plutus.conf
echo "keypool = 1" >> /plutus.conf
echo "gen = 1" >> /plutus.conf

# check="true"
# if [$GEN == $check]
then
    echo "gen = 1" >> /plutus.conf
fi

./app/plutusd -datadir=/app -printtoconsole