#!/bin/sh

touch /pivx.conf

x=$REMOTES
OLD_IFS=$IFS    # save internal field separator
IFS=","         # set it to '+'
set -- $x       # make the result positional parameters
IFS=$OLD_IFS    # restore IFS
for i in "$@"; do # access each element of array
    echo "addnode = $i" >> /pivx.conf
done

echo "port = 11011" >> /pivx.conf
echo "keypool = 1" >> /pivx.conf
echo "gen = 1" >> /pivx.conf

# check="true"
# if [$GEN == $check]
then
    echo "gen = 1" >> /pivx.conf
fi

./app/pivxd -datadir=/app -printtoconsole